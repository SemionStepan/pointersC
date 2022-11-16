#ifndef SEVENTH_H
#define SEVENTH_H

#include <string.h>
#include <stdio.h>
#include <stdlib.h>

typedef enum
{
    true,
    false
} bool;

typedef struct
{
    char* word; // Корень
    int massSize; // Размер массива
    char **endsMass;  // Массив
}
Number;

typedef struct
{
    int class; // Разряд
    Number num[10];
} Line;

// 1. Ввод числа  2. Счёт его символов  3. Определение цифр в слова  4. Вывод

// Главный цикл
int exec();

// Функция, считающая количество символов в числе
int counter(char* number);

// Функция, возвращающая определённую цифру числа
int miniTranslator(char* number, int count, int type);

// Функция, переводящая цифры в текст
const Line* interpreter(char* number);

// Функция, сохраняющая переданное ей слово в строку
char* saver(char* word, char* str);

// Вывод
void showText(char* str);


#endif // SEVENTH_H
