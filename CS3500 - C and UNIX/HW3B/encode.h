#include "util.h"

#ifndef _ENCODE_H
#define _ENCODE_H

typedef struct _Storage {
    int val;
    int occurrence;
} Storage;

int * reorder(Matrix M);

void printZig(int *data);

Storage * countConsecutive(int *data);

void convertToBits(Storage *occOfVal, FILE *fp);

void writeKBits(Storage *occOfval, int size, FILE *fp);

#endif

