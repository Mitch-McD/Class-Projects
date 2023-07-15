#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "a5_file.h"
#include "util.h"
#include "a2.h"
#include "a3_e.h"

int main(int argc, char **argv) {
    
    int quality;

    if(argc == 4)
	quality = atoi(argv[3]);
    else if (argc == 3)
	quality = 50;
    else {
	printf("Wrong amount of command line arguments given (image file, data file, quality)\n");
	return 1;
    }
    FILE *fr = NULL;
    if ((fr = fopen(argv[1], "rb")) == NULL) {
    	printf("Could not open read file.\n");
	return 1;
    }
    
    FILE *fw = NULL;
    if ((fw = fopen(argv[2], "wb")) == NULL) {
        printf("Could not open write file.\n");
        return 1;
    }
    int fileType = getType(fr);
    if (fileType == 2) {
            fclose(fr);
    	    fileType = 2;
    	if ((fr = fopen(argv[1], "r")) == NULL) {
            printf("Could not open read text file.\n");
            return 1;
        }
        skipType(fr);
    }
    
    int *wh = getSize(fr);
    int size = wh[0] * wh[1];
    size = (fileType == 6 ? size*3 : size);
    skipIntensity(fr);

    char *array = getData(fr, fileType, size);
    
    fileType = (fileType == 2 ? 5 : fileType);

    fclose(fr);

    int oldWH[2] = {wh[1], wh[0]};
    int newWH[2] = {wh[1], wh[0]};
    while (newWH[0] % N != 0)
    	newWH[0]++;
    while (newWH[1] % N != 0)
    	newWH[1]++;
    

    Block *blocks = toBlocks(array, oldWH, newWH, fileType);
    
    free(array);
    
    fprintf(fw, "P%u\n%u %u\n%u\n", fileType, wh[0], wh[1], quality);
 
    Matrix T, Q;
    Init(quality, &T, &Q);
    MatrixRound(&Q);
    int i;
    for(i = 0; i < (newWH[0]*newWH[1])/(N*N)*(fileType == 6 ? 3 : 1); i++) {
	Matrix M = convertFromBlock(&blocks[i]);
        float avg = ComputeAverage(&M); 
        int dc = round(avg); 
	Add(&M, -dc);
        Matrix D;
        D = MatrixMult(T,M); 
	Matrix Tx = MatrixTranspose(&T);
	D = MatrixMult(D, Tx);
        Matrix C = MatrixElementDiv(&D,&Q);
	MatrixRound(&C);
	int *data = reorder(&C);
	Storage *occOfVal = countConsecutive(data);
	convertToBits(occOfVal, fw, dc, i);
	free(occOfVal);
    }

 

    free(blocks);
    fclose(fw);
    return 0;
}
