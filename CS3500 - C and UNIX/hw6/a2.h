#ifndef _A2_H
#define _A2_H

#include "util.h"

Matrix convertFromBlock(Block *block);
Block convertToBlock(Matrix *matrix);
void PrintIntMatrix(Matrix *a);
void PrintDoubleMatrix(Matrix *a);
float ComputeAverage(Matrix *a);
void Add(Matrix *a, int dc);
Matrix MatrixTranspose(Matrix *a);
Matrix MatrixElementMult(Matrix *a, Matrix *b);
Matrix MatrixMult(Matrix a, Matrix b);
Matrix MatrixElementDiv(Matrix *a, Matrix *b);
void Init(int quality, Matrix *T, Matrix *Q);
void MatrixRound(Matrix *a); 

#endif
