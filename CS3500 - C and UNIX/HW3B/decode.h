#include "util.h"

#ifndef _DECODE_H
#define _DECODE_H

typedef struct _Storage {
    int val;
    int occurrence;
} Storage;

Storage * convertFromBit(FILE *fp);

void printData(Storage *data);

Matrix convertToMatrix(Storage *data);

int * readKBits(FILE *fp, int fileSize);

#endif
