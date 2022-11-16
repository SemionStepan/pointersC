#include "fourth.h"


int* initMatrix(int strs, int cols)
{
    int* matrixArray = calloc(strs * cols, sizeof(int));
  return matrixArray;
}

void freeMatrixArray(int* matrixArray)
{
    free(matrixArray);
}

int* fillMatrixWithRandomNumbers(int* matrixArray, int strs, int cols)
{
    for(int i = 0; i < (strs * cols); i++)
    {
        *(matrixArray + i) = rand() % 6;
    }
  return matrixArray;
}

void showMatrix(int *matrixArray, int strs, int cols)
{
    for(int i = 0; i < strs; i++)
    {
        for(int j = 0; j < cols; j++)
        {
            printf("  %2d  ", *(matrixArray + i * cols + j));
        }
        printf("\n");
    }
}

int* transponizeMatrix(int* matrixArray,int* transponizedMatrix, int strs, int cols)
{    
    for(int i = 0; i < strs; i++)
    {
        for(int j = 0; j < cols; j++)
        {            
            *(transponizedMatrix + i * strs + j) = *(matrixArray + j * cols + i); // Пояснение для тех, кто 5 дней разбирает транспонирование матрицы : на 1 итерации все значения равны нул(? * 0 = 0), потом маркер столбцов становится равен 1, поэтому начало матрицы + 1 = начало Т матрицы + количество столбцов * на 1. Таким образом главная диагональ (ЛЕВЫЙ ВЕРХ - ПРАВЫЙ НИЗ!) остаётся не тронутой, так как в этих местах значения маркеров строки и столбца равны.
        }
    }
  return transponizedMatrix;
}

void exec()
{
    int flag = 1;
    while(flag)
    {
        int strs = 0, cols = 0;
        printf("Введите количество строк: \n");

        scanf("%d", &strs);

        printf("Введите количество столбцов:\n");

        scanf("%d", &cols);

        int* matrixArray = initMatrix(strs, cols);

        fillMatrixWithRandomNumbers(matrixArray, strs, cols);

        showMatrix(matrixArray, strs, cols);

        printf("Транспонированная матрица :\n");

        int* transponizedMatrix = initMatrix(strs, cols);

        transponizeMatrix(matrixArray, transponizedMatrix, strs, cols);

        showMatrix(transponizedMatrix, cols, strs);

        freeMatrixArray(transponizedMatrix);
        freeMatrixArray(matrixArray);

        printf("Завершить программу - 0, повторить - 1\n");
        scanf("%d", &flag);
    }
}
