#include <stdio.h>
#include <math.h>
#include <string.h>
#include "a5_file.h" 
#include "util.h"
typedef struct storeRGB {
    char val[3];
} RGB;

int checkForComments(FILE *fr) {
    char x;
    x = fgetc(fr);
    if(x == '#') {
	while(x != '\n') {
            fscanf(fr, "%c", &x);
	}
	return 0;
    } 
    fseek(fr, -1L, SEEK_CUR);
    return 1;
}


int getType(FILE *fr) {
    char fileType[2];
    if (checkForComments(fr) == 0)
	return getType(fr);
    fscanf(fr, "%s\n",fileType);
    return fileType[1] - 48;
}

int * getSize(FILE *fr) {
    // valgrind tells me this is leaking twice even though 
    // I freed it in main at the end of the program
    //int *heightWidth = (int *) malloc(2 * sizeof(int));
    static int heightWidth[2]; // so I had to go with a static array instead
    if (checkForComments(fr) == 0)
	return getSize(fr);
    int x, y; 
    fscanf(fr, "%d %d", &x, &y);
    heightWidth[0] = x; 
    heightWidth[1] = y;
   
    return heightWidth;    
}

void skipType(FILE *fr) {
    char x; 
    char type[3];
    if (checkForComments(fr) == 0)
	skipType(fr);
    fscanf(fr, "%s\n", type, &x);
}

void skipIntensity(FILE *fr) {
    if (checkForComments(fr) == 0)
	skipIntensity(fr);
    int intensity;
    fscanf(fr, "%d\n", &intensity);
}

int getQuality(FILE *fr) {
    if (checkForComments(fr) == 0)
        skipIntensity(fr);
    int quality;
    fscanf(fr, "%d\n", &quality);
    return quality;
}

char * getData(FILE *fr, int fileType, int size) {
    if (checkForComments(fr) == 0)
	return getData(fr, fileType, size);
    int i;
    char *data = (char *) malloc(size * sizeof(char));
    if (fileType == 2) {
	for (i = 0; i < size; i++) {
	    int x;
	    fscanf(fr, "%d ", &x);
	    char y = x;
	    data[i] = y;
        }
    }
    else if (fileType == 5 || fileType == 6) {
    	fread(data, sizeof(char), size, fr);
    }

    return data;
}

void writeToFile(FILE *fw, int fileType, char *array, int size, int *heightWidth) {
    if (fileType == 2 || fileType == 5) 
	fprintf(fw, "P5\n%d %d\n255\n", heightWidth[0], heightWidth[1]);
    if (fileType == 6)
	fprintf(fw, "P6\n%d %d\n255\n", heightWidth[0], heightWidth[1]);
    fwrite(array, 1, size, fw);
}   

// hw5 additions

Block * toBlocks(char *array, int *oldhw, int *hw, int fileType) {
    Block *blocks = (Block *) malloc((hw[0]/N)*(hw[1]/N) * sizeof(Block));
    int i, j, k = 0;
    
    if (fileType == 5) {
        unsigned char array2d[hw[0]][hw[1]];
    	for (i = 0; i < hw[0]; i++) {
	    for (j = 0; j < hw[1]; j++) {
		if (i < oldhw[0] && j < oldhw[1])
		    array2d[i][j] = array[k++];
		else 
		    array2d[i][j] = 0;
	    }
	}
	
	k = 0;
        int blockAmount = (hw[0]/N) * (hw[1]/N);
	for (k = 0; k < blockAmount; k++) {
	    for (i = 0; i < N; i++) {
	    	for (j = 0; j < N; j++) {
    		    blocks[k].element[i][j] = array2d[i+N*(k/(hw[1]/N))][j+N*(k%(hw[1]/N))];
		}
	    }
	}
    }
    else {
	blocks = (Block*) realloc(blocks,(hw[0]/N)*(hw[1]/N)*3*sizeof(Block));
	unsigned char arrayRGB[hw[0]][hw[1]][3];
	for (i = 0; i < hw[0]; i++) {
            for (j = 0; j < hw[1]; j++) {
                if (i < oldhw[0] && j < oldhw[1]) {
                    arrayRGB[i][j][0] = array[k++];
		    arrayRGB[i][j][1] = array[k++];
		    arrayRGB[i][j][2] = array[k++];
                } else {
                    arrayRGB[i][j][0] = 0;
		    arrayRGB[i][j][1] = 0;
		    arrayRGB[i][j][2] = 0;
            	}
	    }
        }

        k = 0;
        int blockAmount = (hw[0]/N) * (hw[1]/N);
	int counter = 0;
        for (k = 0; k < blockAmount; k++) {
            for (i = 0; i < N; i++) {
                for (j = 0; j < N; j++) {
		    blocks[counter].element[i][j] = arrayRGB[i+N*(k/(hw[1]/N))][j+N*(k%(hw[1]/N))][0];
                    blocks[counter+1].element[i][j] = arrayRGB[i+N*(k/(hw[1]/N))][j+N*(k%(hw[1]/N))][1];
		    blocks[counter+2].element[i][j] = arrayRGB[i+N*(k/(hw[1]/N))][j+N*(k%(hw[1]/N))][2];
		    
		}
	    }
	    counter += 3;
        }
    }
    return blocks;
}

char * fromBlocks(Block *blocks, int size, int *oldHW, int *newHW, int fileType) {
    int blockAmount = newHW[0]/N*newHW[1]/N;
    int i, j, k, counter = 0;
    char arrayRGB[newHW[0]][newHW[1]][3];    
    char array2d[newHW[0]][newHW[1]]; 
    for (k = 0; k < blockAmount; k++) {
        for (i = 0; i < N; i++) {
  	    for (j = 0; j < N; j++) {
	    	if (fileType == 5 || fileType == 2)
		    array2d[i+N*(k/(newHW[1]/N))][j+N*(k%(newHW[1]/N))] = blocks[k].element[i][j];
	    	else {
		    arrayRGB[i+N*(k/(newHW[1]/N))][j+N*(k%(newHW[1]/N))][0] = blocks[counter].element[i][j];
		    arrayRGB[i+N*(k/(newHW[1]/N))][j+N*(k%(newHW[1]/N))][1] = blocks[counter+1].element[i][j];
		    arrayRGB[i+N*(k/(newHW[1]/N))][j+N*(k%(newHW[1]/N))][2] = blocks[counter+2].element[i][j];
		}
	    }
	}
	counter+=3;
    }
    k = 0;
    char *array = (char *) malloc (sizeof(char) * size);
    for (i = 0; i < newHW[0]; i++) {
	for (j = 0; j < newHW[1]; j++) {
	    if (i < oldHW[0] && j < oldHW[1]) {
		if (fileType == 5) 
		    array[k++] = array2d[i][j];
		else {
		    array[k++] = arrayRGB[i][j][0];
		    array[k++] = arrayRGB[i][j][1];
		    array[k++] = arrayRGB[i][j][2];
		}
	    }
	}
    }
			
    
	

    return array;
}
void printFirstLast(Block *blocks, int *heightWidth, int *newHW, int fileType) {
    int i, j, k = 0;
    int blockAmount = (fileType == 5 ? newHW[0]/N*newHW[1]/N : newHW[0]/N*newHW[1]/N*3);
    printf("Image size = (%d, %d)\n", heightWidth[0], heightWidth[1]);
    printf("Number of Blocks = %d\n", blockAmount);
    printf("First Block ...\n");
    for (i = 0; i < N; i++) {
        for (j = 0; j < N; j++) {
	    if (fileType == 5)
                printf(" %d ", blocks[0].element[i][j]);
	    else
		printf(" %d ", blocks[0].element[i][j]);
        }
        printf("\n");
    }
    printf("Last Block ...\n");
    for (i = 0; i < N; i++) {
        for (j = 0; j < N; j++) {
	    if (fileType == 5)
        	printf(" %d ", blocks[blockAmount-1].element[i][j]);
            else
		printf(" %d ", blocks[blockAmount-3].element[i][j]);
        }
        printf("\n");
    }
    
}

