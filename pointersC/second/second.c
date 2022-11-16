#include "second.h"

int *init2DArray(int strs, int cols)
{
    int* array = calloc(strs * cols, sizeof(int));
  return array;
}

void free2DArray(int *array)
{
    free(array);
}

int *fill2DArrayWithRandomNumbers(int *array, int strs, int cols)
{
    for(int i = 0; i < (strs * cols); i++)
    {
        *(array + i) = rand() % (50 - 0 + 1) + 0;
    }
  return array;
}

void show2DArray(int *array, int strs, int cols)
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

int exec(int strs, int cols)
{
    int flag = 1;
    while(flag)
    {
        printf("\n Введите количество строк массива : ");

        scanf("%d", &strs);

        printf("\n Введите количество столбцов массива : ");

        scanf("%d", &cols);

        int* array = init2DArray(strs, cols);

        fill2DArrayWithRandomNumbers(array, strs, cols);

        show2DArray(array, strs, cols);

        free2DArray(array);

        printf("Завершить программу - 0, начать заново - 1\n");
        scanf("%d", &flag);
    }
  return 0;
}
