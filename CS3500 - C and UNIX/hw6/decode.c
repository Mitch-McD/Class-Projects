#include <stdio.h>
#include <stdlib.h>
#include "a2.h"
#include "a3_d.h"
#include "util.h"
#include "a5_file.h"

int main(int argc, char **argv) {

    

    if (argc != 3) {
        printf("Wrong amount of command line arguments given (input data file, output pgm)\n");
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
    //wh[0] = 8;
    //wh[1] = 8;
    int size = wh[0] * wh[1];
    size = (fileType == 6 ? size*3 : size);
    int quality = getQuality(fr);
 
    int oldWH[2] = {wh[1], wh[0]};
    int newWH[2] = {wh[1], wh[0]};
    while (newWH[0] % N != 0)
        newWH[0]++;
    while (newWH[1] % N != 0)
        newWH[1]++;

    int blockAmount = (newWH[0]*newWH[1])/(N*N)*(fileType == 6 ? 3 : 1);

    int *bytes = readAllBits(fr);

    fclose(fr);

    int count = 0;

    int i = 0;

    Matrix T, Q;
    Init(quality, &T, &Q);
    MatrixRound(&Q);
    Block *blocks = (Block *) malloc(sizeof(Block)*blockAmount);

    Matrix *matrixArray = matrixFromBytes(bytes, blockAmount);



    for(i = 0; i < blockAmount; i++) {
	Matrix C = matrixArray[i]; 
	int dc = matrixArray[i].avg;
        Matrix R = MatrixElementMult(&Q,&C);
        Matrix M2;
	Matrix Tx = MatrixTranspose(&T);
	M2 = MatrixMult(Tx,R);
        M2 = MatrixMult(M2,T);
        MatrixRound(&M2);
        Add(&M2, dc);
        blocks[i] = convertToBlock(&M2);
    }
    char *array = fromBlocks(blocks, size, oldWH, newWH, fileType);
    writeToFile(fw, fileType, array, size, wh);

    free(matrixArray);
    free(array);
    free(blocks);
    fclose(fw);

    return 0;
}

