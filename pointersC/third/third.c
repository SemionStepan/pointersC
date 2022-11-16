#include "third.h"

int *initArray(int strs, int cols)
{
    int* array = calloc(strs * cols, sizeof(int));
  return array;
}

void freeArray(int *array)
{
    free(array);
}

int *fillArrayWithRandomNumbers(int *array, int strs, int cols)
{
    for(int i = 0; i < (strs * cols); i++)
    {
        *(array + i) = rand() % 100;
    }
    return array;
}

// Последующий больше нулевого -> смена проанализировать, поставить на 1 место элемент с макс значением

int *swapMaxToFirst(int *array, int strs, int cols)
{
    for(int i = 0; i < strs; i++)
    {
        int max = 0;
        for(int j = 0; j < cols; j++)
        {
            if(max < *(array + j + (cols * i)))
            {
                max = *(array + j + (cols * i));
                *(array + j + (cols * i)) = *(array + (cols * i));
                *(array + (cols * i)) = max;
            }
        }
    }
  return array;
}

void showArray(int *array, int strs, int cols)
{
    for(int i = 0; i < strs; i++)
    {
        for(int j = 0; j < cols; j++)
        {
            printf("  %2d  ", *(array + i * cols + j));
        }
        printf("\n");
    }
}

void exec()
{
    int flag = 1;

    while(flag)
    {
        printf("\n Введите количество строк массива : ");

        int strs, cols = 0;
        scanf("%d", &strs);

        printf("\n Введите количество столбцов массива : ");

        scanf("%d", &cols);

        int* array = initArray(strs, cols);

        fillArrayWithRandomNumbers(array, strs, cols);

        swapMaxToFirst(array, strs, cols);

        showArray(array, strs, cols);

        freeArray(array);

        printf("Завершить программу - 0, начать заново - 1\n");
        scanf("%d", &flag);
    }
}

