#include "util.h"

#ifndef _DECODE_H
#define _DECODE_H

typedef struct _Storage {
    int val;
    int occurrence;
} Storage;

Matrix convertToMatrix(Storage *data);

Matrix * matrixFromBytes(int *bytes, int blockAmount);

int * readAllBits(FILE *fp);



#endif
