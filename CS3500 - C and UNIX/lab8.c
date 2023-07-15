#include <stdlib.h>
#include <stdio.h>
#include <math.h>

#define N 8

typedef struct _Matrix {
    int element[N][N];
} Matrix;

void PrintMatrix(Matrix *a) {
    int i, j;
    for (i=0; i<N; i++) {
        for (j=0; j<N; j++)
            printf("%d\t", a->element[i][j]);
        printf("\n");
    }
}

void ComputeAverage(Matrix *a, float *avg) {
    int total = 0;
    int i, j;
    for (i=0; i<N; i++) {
        for (j=0; j<N; j++)
            total += a->element[i][j];
    }
    *avg = (total/(N*N));
}

void Add(Matrix *a, int *dc) {
    int i, j;
    for (i=0; i<N; i++) {
        for (j=0; j<N; j++)
            a->element[i][j] += *dc;
    }    
}

void MatrixTranspose(Matrix *a, Matrix *b) {  
    int i, j;
    for (i=0; i<N; i++) {
        for (j=0; j<N; j++)
            b->element[j][i] = a->element[i][j];
    }
}

void MatrixElementMult(Matrix *a, Matrix *b) {
    int i, j;
    for (i=0; i<N; i++) {
        for (j=0; j<N; j++)
            b->element[i][j] = a->element[i][j]*b->element[i][j];
    }
}

void MatrixElementDiv(Matrix *a, Matrix *b) {
    int i, j;
    for (i=0; i<N; i++) {
        for (j=0; j<N; j++)
           a->element[i][j] = a->element[i][j]/b->element[i][j];
    }
}

Matrix Q50 = {{16, 11, 10, 16, 24, 40, 51, 61,
    12, 12, 14, 19, 26, 58, 60, 55,
    14, 13, 16, 24, 40, 57, 69, 56,
    14, 17, 22, 29, 51, 87, 80, 62,
    18, 22, 37, 56, 68,109,103, 77,
    24, 35, 55, 64, 81,104,113, 92,
    49, 64, 78, 87,103,121,120,101,
    72, 92, 95, 98,112,100,103, 99}
};

int main(int argc, const char * argv[])
{
    Matrix M = {{154, 123, 123, 123, 123, 123, 123, 136,
        192, 180, 136, 154, 154, 154, 136, 110,
        254, 198, 154, 154, 180, 154, 123, 123,
        239, 180, 136, 180, 180, 166, 123, 123,
        180, 154, 136, 167, 166, 149, 136, 136,
        128, 136, 123, 136, 154, 180, 198, 154,
        123, 105, 110, 149, 136, 136, 180, 166,
        110, 136, 123, 123, 123, 136, 154, 136}};
    // display matrix M
    printf("Matrix M:\n");
    PrintMatrix(&M);

    // get average of M
    float avg = 0;
    ComputeAverage(&M, &avg);

    // calculate the round - had to run "gcc assignment1_mdcaniel.c -lm -std=c99" to get round to work
    int dc = round(avg);
    printf("\nAve = %d\n",dc);
    dc = dc * -1;
    // add average to M, output M2
    Matrix M2 = M;
    Add(&M2, &dc);
    
    // display matrix M2 (M - avg)
    printf("\nAverage Subtracted:\n");
    PrintMatrix(&M2);
    
    // flip M, output T2
    Matrix T2 = M;
    MatrixTranspose(&M, &T2);
    printf("\nTransposed:\n");
    PrintMatrix(&T2);
    
    // Multiply by element M and Q50, output R
    Matrix R = M;
    MatrixElementMult(&Q50,&R);
    printf("\nMultiplied:\n");
    PrintMatrix(&R);
    
    // Divide by element R by Q50, output C
    Matrix C = R;
    MatrixElementDiv(&C,&Q50);
    printf("\nDivided:\n");
    PrintMatrix(&C);
    
    
        
    return EXIT_SUCCESS;
}
