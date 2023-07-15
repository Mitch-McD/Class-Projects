#ifndef _UTIL_H
#define _UTIL_H

#define N 8
#define PI 3.14159265358979323846

typedef struct _Block {
    unsigned char element[N][N];
} Block;

typedef struct _Matrix {
    double element[N][N];
    int avg;
} Matrix;

void PrintMatrix(Matrix a);

#endif

