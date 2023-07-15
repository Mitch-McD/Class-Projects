#include <stdlib.h>
#include <stdio.h>
#include "util.h"

void PrintMatrix(Matrix a) {
    int i, j;
    for (i=0; i<N; i++) {
        for (j=0; j<N; j++)
            printf("%d\t", a.element[i][j]);
        printf("\n");
    }
}

