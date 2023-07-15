#include <stdlib.h>
#include <stdio.h>
#include <math.h>

#define N 8
#define PI 3.14159265358979323846
// left type as double because T requires decimals
typedef struct _Matrix {
    double element[N][N];
} Matrix;

Matrix Q, T;

Matrix Q50 = {{16, 11, 10, 16, 24, 40, 51, 61,
    12, 12, 14, 19, 26, 58, 60, 55,
    14, 13, 16, 24, 40, 57, 69, 56,
    14, 17, 22, 29, 51, 87, 80, 62,
    18, 22, 37, 56, 68,109,103, 77,
    24, 35, 55, 64, 81,104,113, 92,
    49, 64, 78, 87,103,121,120,101,
    72, 92, 95, 98,112,100,103, 99}
};
// for printing the other matrices
void PrintIntMatrix(Matrix a) {
    int i, j;
    for (i=0; i<N; i++) {
        for (j=0; j<N; j++)
	    printf("%d\t", (int)a.element[i][j]);
        printf("\n");
    }
    printf("\n");
}
// for printing T
void PrintDoubleMatrix(Matrix a) {
    int i, j;
    for (i=0; i<N; i++) {
        for (j=0; j<N; j++)
            printf("%.4f\t", a.element[i][j]);
        printf("\n");
    }
    printf("\n");
}


float ComputeAverage(Matrix a) {
    int total = 0;
    int i, j;
    for (i=0; i<N; i++) {
        for (j=0; j<N; j++)
            total += a.element[i][j];
    }
    float avg = (total/(N*N));
    return (avg);
}

Matrix Add(Matrix a, int dc) {
    int i, j;
    for (i=0; i<N; i++) {
        for (j=0; j<N; j++)
            a.element[i][j] += dc;
    }    
    return a;
}

Matrix MatrixTranspose(Matrix a) {  
    Matrix b;
    int i, j;
    for (i=0; i<N; i++) {
        for (j=0; j<N; j++)
            b.element[j][i] = a.element[i][j];
    }
    return b;
}

Matrix MatrixElementMult(Matrix a, Matrix b) {
    Matrix c;
    int i, j;
    for (i=0; i<N; i++) {
        for (j=0; j<N; j++)
            c.element[i][j] = a.element[i][j]*b.element[i][j];
    }
    return c;
}

// matrix mult compatibility deemed not necessary for square matrices
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

Matrix MatrixElementDiv(Matrix a, Matrix b) {
    Matrix c;
    int i, j;
    for (i=0; i<N; i++) {
        for (j=0; j<N; j++)
            c.element[i][j] = a.element[i][j]/b.element[i][j];
    }
    return c;
}

void Init(int quality) {
    // init T
    int i, j;
    for (i=0; i<N; i++) {
	for (j=0; j<N; j++) {
	    if (i == 0)
		T.element[i][j] = (1/sqrt(N));
	    else {
		T.element[i][j] = sqrt(2/(double)N)*cos(((2*j+1)*i*(double)PI)/(2*(double)N));
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
	    Q.element[i][j] = temp;
	}
    }
}

// Added to round matrices as this proved to be more accurate 
// than rounding them in the div/mult functions for whatever reason
Matrix MatrixRound(Matrix a) {
    int i,j;
    Matrix b;
    for(i=0;i<N;i++) {
	for(j=0;j<N;j++) 
	    b.element[i][j] = round(a.element[i][j]);
    }
    return b;
}

int main(int argc, char **argv)
{
    Matrix M = {{154, 123, 123, 123, 123, 123, 123, 136,
        192, 180, 136, 154, 154, 154, 136, 110,
        254, 198, 154, 154, 180, 154, 123, 123,
        239, 180, 136, 180, 180, 166, 123, 123,
        180, 154, 136, 167, 166, 149, 136, 136,
        128, 136, 123, 136, 154, 180, 198, 154,
        123, 105, 110, 149, 136, 136, 180, 166,
        110, 136, 123, 123, 123, 136, 154, 136}};
    
    int quality = atoi(argv[1]);    

    Init(quality); // init T and Q

    printf("T\n");
    PrintDoubleMatrix(T); 
    
    Q = MatrixRound(Q); // round Q

    printf("Q\n");
    PrintIntMatrix(Q);

    float avg = ComputeAverage(M); // get average of M
    int dc = round(avg); // round average to int
    
    M = Add(M, -dc); // subtracted average from M

    Matrix D = MatrixMult(MatrixMult(T,M), MatrixTranspose(T)); // D = T * M, * T`
    
    Matrix C = MatrixElementDiv(D,Q); // C = D / Q      
    
    C = MatrixRound(C); // round C
 
    printf("C\n"); 
    PrintIntMatrix(C);

    Matrix R = MatrixElementMult(Q,C);

    Matrix M2 = MatrixMult(MatrixMult(MatrixTranspose(T),R),T); // M2 = T` * R, * T   
    
    M2 = MatrixRound(M2); // round M2

    M2 = Add(M2, dc); // add average to M2
    
    printf("M2\n");
    PrintIntMatrix(M2);

    return EXIT_SUCCESS;
}
