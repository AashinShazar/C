#include "rogue.h"

void RemoveSpaces(char* source)
{
	char* i = source;
	char* j = source;
	while(*j != 0)
    {
		*i = *j++;
		if(*i != ' ')
			i++;
	}
	*i = 0;
}

 int checkFile(char fileName[])
{
	FILE * file;

	file = fopen(fileName, "r");
	if (file == NULL) 
    {
		printf("I couldn't open the file! n");
		exit(0);
	}

	return 1;
}

void removeChar(char *string, char trash) 
{
	char *source, *dest;
	for (source = dest = string; *source != '\0'; source++) 
    {
		*dest = *source;
		if (*dest != trash) dest++;
	}
	*dest = '\0';
}

char * strtokData(const char * pch, char * var) 
{
	char * found;
	char *ret;
	if (strstr(pch, var) != NULL)
    {
		ret = strstr(pch, var);
		found = strtok(ret, var);
		while (found != NULL)
        {
			break;
			
		}
	}
	return found;
}

int lenHelper(unsigned x) 
{
    if (x>=100) return 3;
    if (x>=10) return 2;
    return 1;
}

int printLen(int x) 
{
    return x<0 ? lenHelper(-x)+1 : lenHelper(x);
}


char *replace(const char *containingLine, char charReplaced, const char *replacingChar) 
{
	int count = 0;
	const char *t;
	for(t=containingLine; *t; t++)
		count += (*t == charReplaced);

	size_t rlen = strlen(replacingChar);
	char *res = malloc(strlen(containingLine) + (rlen-1)*count + 1);
	char *ptr = res;
	for(t=containingLine; *t; t++) 
    {
		if(*t == charReplaced) 
        {
			memcpy(ptr, replacingChar, rlen);
			ptr += rlen;
		} 
		else 
        {
			*ptr++ = *t;
		}
	}
	*ptr = 0;
	return res;
}
