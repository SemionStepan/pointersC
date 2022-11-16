#include "first.h"

int exec()
{
    int flag = 1;
    int size = 0;

    while(flag)
    {
        printf("\n Введите размер массива : ");

        scanf("%d", &size);

        double* array = initDoubleArray(size);

        printf("\n Вводите элементы массива(%d штук) : \n", size);

        fillDoubleArray(array, size);

        printf("\n Элементы массива : \n");

        showDoubleArray(array, size);

        freeDoubleArray(array);

        printf("Завершить программу - 0, начать заново - 1\n");
        scanf("%d", &flag);
    }
  return 0;
}

double* initDoubleArray(int size)
{

    double* array = calloc(size, sizeof(double));
  return array;
}

void freeDoubleArray(double* array)
{
    free(array);
}

double* fillDoubleArray(double* array, int size)
{
    for(int i = 0; i < size; i++)
    {
        double number = 0;
        scanf("%lf", &number);
        array[i] = number; //&&&
    }
  return array;
}

void showDoubleArray(double* array, int size)
{
    for(int i = 0; i < size; i++)
    {
        printf(" %lf; \n", array[i]);
    }
}
