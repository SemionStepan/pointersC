#include "sixth.h"

bool isSeparator(const char character)
{
    static const char *separators = " ;:,.,/\\-";
  return strchr(separators, character) ? true : false;
}

bool isBadSimbols(const char character)
{
    static const char *badSimbols = "lkrsij";
  return strchr(badSimbols, character) ? true : false;
}

const char* getBeginWord(const char* string)
{
    const char* pStart = string;
    while(isSeparator(*pStart) == true)
    {
        pStart++;
    }
  return pStart;
}

const char* getEndWord(const char* pStart) // Функция для получения указателя на последнюю букву слова
{
    const char* pEnd = pStart; // Новый указатель, стоит в начале слова
    for(int i = 0; isSeparator(*pEnd) == false; i++) // Проходит все буквы, встаёт на последнюю букву
    {
        pEnd++;
    }
  return pEnd; // И возвращается
}

bool checkWord(const char* pBeginWord, const char *pEndWord)
{
    const char *p = pBeginWord;
    while(*p != '\0' && p <= pEndWord)
    {
        if(isBadSimbols(*p))
        {
            return true;
        }
        p++;
    }
  return false;
}

void showWords(const char* pBegin, const char *pEnd)
{
    for(int i = 0; i < (pEnd-pBegin);i++)
    {
        printf("%c", *(pBegin+i));
    }
    printf(" ");
}

int exec(const char* string) // Обрабатываю строку, нужно выделить слово из строки, прогнать его через проверку запрещённых букв и записать в новую проверенную строку
{
    const char* pBegin = NULL;
    const char* pEnd = string;

        printf("Проверенная строка : ");
        do
        {
            pBegin = getBeginWord(pEnd);
            pEnd = getEndWord(pBegin);
            if(!checkWord(pBegin, pEnd))
            {
                showWords(pBegin, pEnd);
            }
        }
        while(*pEnd != '\0');
        printf("\n");
  return 1;
}
