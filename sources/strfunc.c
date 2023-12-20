#include<strfunc.h>
#include<string.h>
#include<ctype.h>
#include<stdlib.h>

char* toLower(const char* stringInput)
{
    size_t inputLenght = strlen(stringInput);
    char* lowerString = (char *) malloc(inputLenght);

    for(int i=0; i<strlen(stringInput); i++)
    {
        lowerString[i] = tolower(stringInput[i]);
    }

    return lowerString;
}