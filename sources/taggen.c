#include<taggen.h>
#include<string.h>
#include<stdlib.h>
#include<stdio.h>

char* TAG_TEMPLATE = "<%s id=\"%s\" class=\"%s\">%s</%s>";
int EMPTY_TAG_LEN = strlen("< id=\"\" class=\"\"></>");

char* getClassesString(char *classes[])
{
    int arrayLength = sizeof(classes) / sizeof(size_t);
    int i=0;
    char* classesBuffer = malloc(strlen(classes[i]) * sizeof(char));
    sprintf(classesBuffer, "%s ", classes[i]);
    i++;

    do
    {
        classesBuffer = (char *) realloc(classesBuffer, sizeof(classesBuffer) + strlen(classes[i]) * sizeof(char));
        sprintf(classesBuffer, "%s%s ", classesBuffer, classes[i]);
        i++;
    }
    while(i < arrayLength);

    return classesBuffer;
}

char* generateTag(const char *tagName, const char *innerText, const char *id, char *classes[])
{
    char* classesStr = getClassesString(classes);

    int totalTagLength = EMPTY_TAG_LEN + (strlen(tagName) * 2) 
        + strlen(innerText) + strlen(id)
        + strlen(classesStr);
    
    char* tagBuffer = malloc(totalTagLength * sizeof(char)); 
    
    sprintf(tagBuffer, TAG_TEMPLATE, tagName, id, classesStr, innerText, tagName);

    free(classesStr);

    return tagBuffer;
}