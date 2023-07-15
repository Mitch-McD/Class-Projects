#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#include "a2.h"

const Matrix Q50 = {{16, 11, 10, 16, 24, 40, 51, 61,
    12, 12, 14, 19, 26, 58, 60, 55,
    14, 13, 16, 24, 40, 57, 69, 56,
    14, 17, 22, 29, 51, 87, 80, 62,
    18, 22, 37, 56, 68,109,103, 77,
    24, 35, 55, 64, 81,104,113, 92,
    49, 64, 78, 87,103,121,120,101,
    72, 92, 95, 98,112,100,103, 99}
};

Matrix convertFromBlock(Block *block) {
    int i, j;
    Matrix matrix;
    for (i = 0; i < N; i++) {
	for (j = 0; j < N; j++)
	    matrix.element[i][j] = block->element[i][j];
    }
    return matrix;
}
Block convertToBlock(Matrix *matrix) {
    int i, j;
    Block block;
    for (i = 0; i < N; i++) {
        for (j = 0; j < N; j++) {
            //printf("i: %d j: %d val: %d \n", i, j, matrix->element[i][j]);
	    if (matrix->element[i][j] > 255)
		block.element[i][j] = 225;
	    else if (matrix->element[i][j] < 0)
	       block.element[i][j] = 0;
	    else
	    	block.element[i][j] = matrix->element[i][j];
	}
    }
    return block;
}

void PrintIntMatrix(Matrix *a) {
    int i, j;
    for (i=0; i<N; i++) {
        for (j=0; j<N; j++)
            printf("%d\t", (int)a->element[i][j]);
        printf("\n");
    }
    printf("\n");
}
// for printing T
void PrintDoubleMatrix(Matrix *a) {
    int i, j;
    for (i=0; i<N; i++) {
        for (j=0; j<N; j++)
            printf("%.4f\t", a->element[i][j]);
        printf("\n");
    }
    printf("\n");
}
float ComputeAverage(Matrix *a) {
    int total = 0;
    int i, j;
    for (i=0; i<N; i++) {
        for (j=0; j<N; j++)
            total += a->element[i][j];
    }
    float avg = (total/(N*N));
    //printf("avg of matrix: %d", avg);
    return (avg);
}

void Add(Matrix *a, int dc) {
    int i, j;
    for (i=0; i<N; i++) {
        for (j=0; j<N; j++) {
            a->element[i][j] += dc;
	}
    }
}

Matrix MatrixTranspose(Matrix *a) {
    int i, j;
    Matrix b;
    for (i=0; i<N; i++) {
        for (j=0; j<N; j++)
            b.element[j][i] = a->element[i][j];
    }
    return b;
}
Matrix MatrixElementMult(Matrix *a, Matrix *b) {
    Matrix c;
    int i, j;
    for (i=0; i<N; i++) {
        for (j=0; j<N; j++)
            c.element[i][j] = a->element[i][j]*b->element[i][j];
    }
    return c;
}
Matrix MatrixMult(Matrix a, Matrix b) {
    int i,j,k;
    Matrix c;
    for (i=0;i<N;i++) {
        for (j=0;j<N;j++) {
            double rowTotal = 0;
            for (k=0;k<N;k++) {
                rowTotal += a.element[i][k] * b.element[k][j];
            }
            c.element[i][j] = rowTotal;
        }
    }
    return c;
}

Matrix MatrixElementDiv(Matrix *a, Matrix *b) {
    Matrix c;
    int i, j;
    for (i=0; i<N; i++) {
        for (j=0; j<N; j++)
            c.element[i][j] = a->element[i][j]/b->element[i][j];
    }
    return c;
}
void Init(int quality, Matrix *T, Matrix *Q) {
    // init T
    int i, j;
    for (i=0; i<N; i++) {
        for (j=0; j<N; j++) {
            if (i == 0)
                T->element[i][j] = (1/sqrt(N));
            else {
                T->element[i][j] = sqrt(2/(double)N)*cos(((2*j+1)*i*(double)PI)/(2*(double)N));
            }
        }
    }
    // init Q

    double r1 = (1/50.0)*(100-quality);
    double r2 = 50/(double)quality;
    double scale = (quality > 50 ? r1 : r2);
    for (i=0; i<N; i++) {
        for (j=0; j<N; j++) {
            double temp = Q50.element[i][j]*scale;
            if (temp < 1)
                temp = 1;
            else if (temp > 255)
                temp = 255;
            Q->element[i][j] = temp;
        }
    }
}

// Added to round matrices as this proved to be more accurate
// than rounding them in the div/mult functions for whatever reason
void MatrixRound(Matrix *a) {
    int i,j;
    for(i=0;i<N;i++) {
        for(j=0;j<N;j++)
            a->element[i][j] = round(a->element[i][j]);
    }
}

