#ifndef SECOND_H
#define SECOND_H

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define RAND_MAX 50
/* я спрашиваю количество строк и столбцов,
 *  создаю двумерный массив,
 *  заполняю его случайными числами от 10 до 50,
 *  вывожу на экран,
 * очищаюсь
*/

int* init2DArray(int strs, int cols);

void free2DArray(int* array);

int* fill2DArrayWithRandomNumbers(int* array, int strs, int cols);

void show2DArray(int* array, int strs, int cols);

int exec();

#endif // SECOND_H
