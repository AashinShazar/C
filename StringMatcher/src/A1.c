/**********************
Assignment 1
Aashin Shazar
1/24/2016
************************/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "storeval.h"
#include "stringManip.h"
#include "dataStats.h"

/**
* main
* Declares all the variables used in the program and executes accordingly
* IN: Takes in relative file paths when program is executed
* OUT: Returns a statstic of variables and outputs an output file of all the replacements
* POST: None
* ERROR: None
*/
int main(int argc, char* argv[]) {
    
char *ptr1;
int j = 0;
char z = '}';
char tempLine[256];
char dataLine[256];
char * ret;
int x = 0;
char * withThis;
char *newstr = NULL;
int varTempCounter = 0;
int varSuccessRep = 0;
int varFailRep = 0;
char * pch;
int i = 0;
char * gotValueName[256];
int varDataCounter = 0;
char * delim = "=";


if(argc < 3) {
    fputs( "This program requires 3 relative file paths.\n", stderr); //if there are less than 3 file names entered, will return this statement
    return -1;
}

FILE *TEMPinputFile = fopen(argv[1], "r");
FILE *DATAinputFile  = fopen(argv[2], "r");
FILE *outputFile  = fopen(argv[3], "a");

while (fgets(dataLine,256,DATAinputFile)) //reads variable names from data file
{
    pch = strtok (dataLine,"=");
    while (pch != NULL) //splits up the varName and varValue from data
    {
        varDataCounter++;
        gotValueName[i] = strtokData(pch, delim, i);
        i++;
        break;
        
    }
}


while(fgets(tempLine, 256, TEMPinputFile) != NULL)
{
    for (x=0; x<i; ++x)
    {
        ret = strstr(tempLine, gotValueName[x]);  //gets value from dataFile variables and compares with current fileLine
        
        if (ret != NULL)
        {
            varTempCounter++;
            
            
            ptr1 = ret;
            for (j=0; j<strlen(ret);j++)  //trims up string if the {} characters are found
            {
                if (*ptr1 == z) *ptr1 = 0;
                ptr1++;
            }
            withThis = getValue(ret);
            newstr = stringReplace(tempLine, ret, withThis);
            fprintf(outputFile,"%s\n", newstr);
            free(newstr);
            varFailRep = varDataCounter - varTempCounter;
            varSuccessRep = varDataCounter - varFailRep;
            
            if (fgets(tempLine, 256, TEMPinputFile) == NULL)
            {
                printStats(varDataCounter, varTempCounter, varSuccessRep, varFailRep); //prints statistics
            }
            
        }
        
    }
}

fclose(TEMPinputFile);
fclose(DATAinputFile);
fclose(outputFile);

return 0;

}
