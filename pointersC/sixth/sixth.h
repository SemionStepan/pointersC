#ifndef SIXTH_H
#define SIXTH_H

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

#define MAX_STRING 100

typedef enum
{
    true = 1,
    false = 0
} bool;

//Функция для вывода строки в терминал
void showStr(char *subString);

bool isSeparator(const char character);

bool isBadSimbols(const char character);

const char* getBeginWord(const char* string);

const char* getEndWord(const char* pStart);

//Функция, которая проверяет слово
bool checkWord(const char* pBeginWord, const char *pEndWord);

void showWords(const char* pBegin, const char *pEnd);

//Функция, использующая функцию проверки в цикле
int exec(const char* string);

#endif // SIXTH_H
