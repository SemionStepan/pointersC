//Найди все вхождения заданной пользователем подстроки в заданную пользователем строку.

#include "fifth.h"

#define MAX_STRING 100

int main()
{
    do
    {
        char* string = inputString("Введите строку (до 99 символов):", MAX_STRING);
        char* subString = inputString("Введите подстроку (до 99 символов):", MAX_STRING);

        outputString(subString, exec(string, subString));

        free(subString);
        free(string);
    }
    while(dialog("Продолжить программу - 1, завершить - 0 :"));
  return 0;
}
