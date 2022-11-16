#ifndef THIRD_H
#define THIRD_H

#include <stdio.h>
#include <stdlib.h>

typedef enum
{
    true,
    false
} bool;

int* initArray(int strs, int cols);
void freeArray(int* array);

int *fillArrayWithRandomNumbers(int *array, int strs, int cols);

int* swapMaxToFirst(int* array, int strs, int cols);

void showArray(int* array, int strs, int cols);

void exec();

#endif // THIRD_H
