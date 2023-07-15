
#ifndef _FILE_H
#define _FILE_H

#include <stdio.h>
#include <stdlib.h>

int checkForComments(FILE *fr);

int getType(FILE *fr);

void skipType(FILE *fr);

int * getSize(FILE *fr);

void skipIntensity(FILE *fr);

char * getData(FILE *fr, int fileType, int size);

void writeToFile(FILE *fw, int fileType, char *array, int size, int *heightWidth);



#endif 
