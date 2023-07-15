#include <stdio.h>
#include <math.h>
#include <string.h>
#include "file.h" 


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
