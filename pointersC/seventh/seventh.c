#include "seventh.h"

int toBound(int min, int value, int max)
{
    return value < min ? min : value > max ? max : value;
}

bool isBound(int min, int value, int max)
{
    return value < min ? false : value > max ? false : true;
}

bool isMinus(char* string)
{
  return *string == '-' ? true : false;
}

int characterToDigit(char* character)
{
//   return isBound('0', character, '9') ? character - '0' : -1;
    int digit = 0;
    static int digitArray[] = {0,1,2,3,4,5,6,7,8,9};
    static int characterArray[] = {'0','1','2','3','4','5','6','7','8','9'};

    for(int i = 0; i < 9; i++)
    {
        if(*character == characterArray[i])
        {
            digit = digitArray[i];
        }
    }
  return digit ;
}

const Line* interpreter(char* string)
{
    static const Line array[7] =
    {
        { 1, {{ "ноль", 0, NULL }, { "од", 2, NULL }, { "дв", 2, NULL }, { "три", 0, NULL }, { "четыре", 0, NULL }, {"пять", 0, NULL }, {"шесть", 0, NULL }, {"семь", 0, NULL }, {"восемь", 0, NULL }, {"девять", 0, NULL }} },
        { 10, {{ "десять", 0, NULL }, { "двадцать", 0, NULL }, { "тридцать", 0, NULL }, { "сорок", 0, NULL }, { "пятьдесят", 0, NULL }, { "шестьдесят", 0, NULL }, { "семьдесят", 0, NULL }, { "восемьдесят", 0, NULL }, { "девяносто", 0, NULL }} },
        { 100, {{ "сто", 0, NULL }, { "двести", 0, NULL }, { "триста", 0, NULL }, { "четыреста", 0, NULL }, { "пятьсот", 0, NULL }, { "шестьсот", 0, NULL }, { "семьсот", 0, NULL }, { "восемьсот", 0, NULL }, { "девятьсот", 0, NULL }} },
        { 1000, {{ "одна тысяча", 0, NULL }, { "ноль", 0, NULL }, { "ноль", 0, NULL }, { "ноль", 0, NULL }, { "ноль", 0, NULL }} },
        { 10000, {{ "десять тысяч", 0, NULL }, { "ноль", 0, NULL }, { "ноль", 0, NULL }, { "ноль", 0, NULL }, { "ноль", 0, NULL }} },
        { 100000, {{ "сто тысяч", 0, NULL }, { "ноль", 0, NULL }, { "ноль", 0, NULL }, { "ноль", 0, NULL }, { "ноль", 0, NULL }} },
        { 1000000, {{ "миллион", 0, NULL }, { "ноль", 0, NULL }, { "ноль", 0, NULL }, { "ноль", 0, NULL }, { "ноль", 0, NULL }} }
    };

//          }, // Единицы
//              {"десять", "одиннадцать", "двенадцать", "тринадцать", "четырнадцать", "пятнадцать", "шестнадцать", "семнадцать", "восемнадцать", "девятнадцать"},
//              {"", "", "", "", "", "", "", ""},// Десятки
//              {"сто", "", "", "", "", "", "", "", ""},// Сотни
//              {"одна тысяча", "две тысячи", "три тысячи", "четыре тысячи", "пять тысяч", "шесть тысяч", "семь тысяч", "восемь тысяч", "девять тысяч"},// Тысячи
//              {"десять тысяч", "одиннадцать тысяч", "двенадцать тысяч", "тринадцать тысяч", "четырнадцать тысяч", "пятнадцать тысяч", "шестнадцать тысяч", "семнадцать тысяч", "восемнадцать тысяч"},
//              {"девятнадцать тысяч", "двадцать тысяч" ,"тридцать тысяч", "сорок тысяч", "пятьдесят тысяч", "шестьдесят тысяч", "семьдесят тысяч", "восемьдесят тысяч", "девяносто тысяч"},// Десятки тысяч
//              {"сто тысяч", "двести тысяч", "триста тысяч", "четыреста тысяч", "пятьсот тысяч", "шестьсот тысяч", "семьсот тысяч", "восемьсот тысяч", "девятьсот тысяч"},// Сотни Тысяч
//              {"один миллион", "два миллиона", "три миллиона", "четыре миллиона", "пять миллионов", "шесть миллионов", "семь миллионов", "восемь миллионов", "девять миллионов"} // Милллионы
//    };

    int count = strlen(string);
    count = toBound(1, count, 8);

    const Number* word = NULL;

    for(int type = 0; count > 1; type++ ,count--)
    {
        if(count == 2)
        {
            if(*string + type == 1)
            {
                if(9 >= *string + type + 1 >= 1)
                {
                     return word = array[3][*(string + type)];
                }
            }
        }
        word = array[count][*(string + type)];
    }

  return word;
}

void showWord(const char *word )
{
    printf("%s", word);
}

int exec()
{
    //Ввод
    printf("Введите число (от - 1 000 000 до 1 000 000) : ");
    char* string = calloc(sizeof(char), 7);
    scanf("%s", string);

    // Вывод
    printf("Строка в текстовом варианте : ");

    // Проверка на отрицательность
    static const char *minus = "минус ";
    if(!isMinus(string))
    {
        showWord(minus);
    }

    // Функция
    const char* word = interpreter(string);

    //Вывод
    showWord(word);
    printf(" ");
    printf("\n");

    free(string);
   return 1;
}
