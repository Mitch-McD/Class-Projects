
#ifndef _FILE_H
#define _FILE_H

#include <stdio.h>
#include <stdlib.h>

#define N 8 

typedef struct _Block2 {
    unsigned char r[N][N];
    unsigned char g[N][N];
    unsigned char b[N][N];
} BLOCK2;

int checkForComments(FILE *fr);

int getType(FILE *fr);

void skipType(FILE *fr);

int * getSize(FILE *fr);

void skipIntensity(FILE *fr);

char * getData(FILE *fr, int fileType, int size);

void writeToFile(FILE *fw, int fileType, char *array, int size, int *heightWidth);

// hw5 additions

BLOCK2 * toBlocks(char *array, int *oldhw, int *hw, int fileType);

void printFirstLast(BLOCK2 *blocks, int *oldHW, int *newHW, int fileType);

char * fromBlocks(BLOCK2 *blocks, int size, int *oldHW, int *newHW, int fileType);

#endif 
