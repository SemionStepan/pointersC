

#include "fifth.h"

char* inputString(char* message, int length)
{
    char *buffer = calloc(sizeof(char), length);
    if(buffer)
    {
        printf("%s\n", message);
        scanf("%99s", buffer);
    }
  return buffer;
}

int dialog(char *message)
{
    int flag;
    printf("%s\n", message);
    scanf("%d", &flag);
  return flag;
}

void outputString(char *subString, int count)
{
    printf("%s было найдено %d раз\n", subString, count);
}

int exec(char* string, char* subString)
{
    int count = 0;
    int lengthSubString = strlen(subString);

    while((string = strstr(string, subString)))
    {
        string += lengthSubString;
        count++;
    }
  return count;
}
