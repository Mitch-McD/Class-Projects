
#ifndef _FILE_H
#define _FILE_H

#include <stdio.h>
#include <stdlib.h>
#include "util.h"
#define N 8 
int checkForComments(FILE *fr);

int getType(FILE *fr);

void skipType(FILE *fr);

int * getSize(FILE *fr);

void skipIntensity(FILE *fr);

char * getData(FILE *fr, int fileType, int size);

void writeToFile(FILE *fw, int fileType, char *array, int size, int *heightWidth);

// hw5 additions

Block * toBlocks(char *array, int *oldhw, int *hw, int fileType);

void printFirstLast(Block *blocks, int *oldHW, int *newHW, int fileType);

char * fromBlocks(Block *blocks, int size, int *oldHW, int *newHW, int fileType);

int getQuality(FILE *fr);

#endif 
