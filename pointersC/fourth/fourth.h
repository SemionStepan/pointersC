#ifndef FOURTH_H
#define FOURTH_H

#include <stdio.h>
#include <stdlib.h>


int* initMatrix();

void freeMatrixArray(int* matrixArray);

int *fillMatrixWithRandomNumbers(int* matrixArray, int strs, int cols);

int* transponizeMatrix(int* matrixArray, int* transponizedMatrix, int strs, int cols);

void showMatrix(int* matrixArray, int strs, int cols);

void exec();

#endif // FOURTH_H
