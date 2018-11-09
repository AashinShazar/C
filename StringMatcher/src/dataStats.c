#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "storeval.h"
#include "dataStats.h"

void printStats(int varDataCounter, int varTempCounter, int varSuccessRep, int varFailRep)
{
    fprintf( stdout, "Execution successful!\n" );
    fprintf( stdout, "Variables found in Data file: %d\n" , varDataCounter);
    fprintf( stdout, "Variables found in Template file: %d\n" , varTempCounter);
    fprintf( stdout, "Number of successful replacements: %d\n" , varSuccessRep);
    fprintf( stdout, "Number of failed replacements: %d\n" , varFailRep);
}