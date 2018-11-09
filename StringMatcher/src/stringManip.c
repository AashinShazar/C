#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "storeval.h"
#include "stringManip.h"

char *stringReplace(const char *s, const char *old, const char *new1)
{
    char *ret;
    int i, count = 0;
    int lengthNew = strlen(new1);
    int lengthOld = strlen(old);
    
    for (i = 0; s[i] != '\0'; i++)
    {
        if (strstr(&s[i], old) == &s[i])
        {
            count++;
            i += lengthOld - 1;
        }
    }
    
    ret = (char *)malloc(i + count * (lengthNew - lengthOld));
    if (ret == NULL)
        exit(EXIT_FAILURE);
    i = 0;
    while (*s)
    {
        if (strstr(s, old) == s) //compare the substring with the newstring
        {
            strcpy(&ret[i], new1);
            i += lengthNew; //adding lengthNewgth to the new string
            s += lengthOld;//adding the same old length the old string
        }
        else
            ret[i++] = *s++;
    }
    ret[i] = '\0';
    return ret;
}

char * strtokData(char * fileLine, char * delim, int i)
{
    char * varName;
    char * varValue;
    char * gotValueName[256];
    
    varName = fileLine;
    fileLine = strtok (NULL, delim);
    varValue = fileLine;
    setValue(varValue, varName);
    setValue(varName, varValue);
    gotValueName[i] = getValue(varValue);
    
    return gotValueName[i];
}