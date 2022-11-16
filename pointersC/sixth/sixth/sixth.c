#include "sixth.h"

bool isSeparator(const char character) // Функция для определения разделителей
{
    static const char *separators = " ;:,.?'(){}<>[]!|`~_#%&^=+*/\\-";  // Объявление разделителей
  return strchr(separators, character) ? true : false; // Краткое if, которое возвращает правду если есть совпадение, ложь если совпадения нет
}

bool isBadSimbol(const char character) // Функция для определения запрещённых символов
{
    static const char *badSimbols = "lkrsij"; // Объявление символов
  return strchr(badSimbols, character) ? true : false; // Краткое if, которое возвращает правду если есть совпадение, ложь если совпадения нет
}

const char* getBeginWord(const char* string) // Функция для установки указателя на первую букву слова
{
    const char* pStart = string; // Инициализация указателя на начало слова
    while(isSeparator(*pStart) == true)  // Цикл, пока есть совпадения с разделителями
    {
        pStart++; // Инкрементация указателя
    }
  return pStart; // Возврат установленного на букву указателя
}

const char* getEndWord(const char* pStart) // Функция для установки указателя на последнюю букву слова
{
    const char* pEnd = pStart; // Новый указатель, стоит в начале слова
    for(int i = 0; isSeparator(*pEnd) == false; i++) // Проходит все буквы, встаёт на последнюю букву
    {
        pEnd++;
    }
  return pEnd; // И возвращается
}

bool checkWord(const char* pBeginWord, const char *pEndWord) // Функция для проверки слова
{
    const char *p = pBeginWord; // Инициализация третьего указателя, чтобы не сбивать указатель а первую букву
    while(*p != '\0' && p <= pEndWord) // Пока третий указатель не \0 и не равен концу слова
    {
        if(isBadSimbol(*p)) // Используется проверка на запрещённые буквы
        {
            return true; // Совпадение - возврат совпадения
        }
        p++; // Иначе инкремент
    }
  return false; // Совпадений нет - возврат не совпадения
}

void showWord(const char* pBegin, const char *pEnd) // Функция для вывода слов
{
    for(int i = 0; i < (pEnd-pBegin);i++) // Пока счётчик меньше разности указателей
    {
        printf("%c", *(pBegin+i)); // Печатается символ
    }
    printf(" "); // И пробел, чтобы было удобнее читать
}

int exec(const char* string) // Главный цикл, в котором происходят все вычисления и используются все функции
{
    const char* pBegin = NULL; // Инициализация ук. на начало слова(пустой)
    const char* pEnd = string; // Иниц. ук. на конец слова(сейчас указывает на первый символ строки)

    printf("Проверенная строка : "); // Чтобы было удобно читать
    do                               // Минимум 1 итерация
    {
        pBegin = getBeginWord(pEnd); // Поставить ук. начала слова на начало слова
        pEnd = getEndWord(pBegin);   // Поставить ук. конца слова на конец слова
        if(!checkWord(pBegin, pEnd)) // Если между этими указателями нет запрещённых слов
        {
            showWord(pBegin, pEnd); // То вывести это слово
        }
    }
    while(*pEnd != '\0');            // Пока не достигнут конец строки
    printf("\n");                    // чтобы было удобно читать
  return 1;
}
