#include "util.h"

#ifndef _ENCODE_H
#define _ENCODE_H

typedef struct _Storage {
    int val;
    int occurrence;
} Storage;

int * reorder(Matrix *M);

Storage * countConsecutive(int *data);

void convertToBits(Storage *occOfVal, FILE *fp, int avg, int blockCount);

void writeKBits(Storage *occOfval, int size, FILE *fp, int avg, int blockCount);

#endif

