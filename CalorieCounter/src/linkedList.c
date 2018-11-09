#include "linkedList.h"
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <ctype.h>

char *strdupVer (const char *s) {
    char *d = malloc (strlen (s) + 1);   // Space for length plus nul
    if (d == NULL) return NULL;          // No memory
    strcpy (d,s);                        // Copy the characters
    return d;                            // Return the new string
}

Food * createRecord(char * name, char * group, int calories, char theType)
{

	Food * foodList;
	foodList = malloc(sizeof(Food));
	
	int nameLength;
	int groupLength;
	
	nameLength = strlen(name);
	groupLength = strlen(group);
	
	//name test cases
	if (nameLength > 50)
    {
		free(foodList);
		return NULL;
	}
	
	else if (nameLength == 0)
    {
		free(foodList);
		return NULL;
	}
	
	else if (strspn(name, "0123456789.") == strlen(name)) 
    {
		free(foodList);
        return NULL;
    }
	
	else 
    {
		foodList->name = strdupVer(name);
	}
	
	//foodGroup test cases
	if (groupLength > 50)
    {
		free(foodList);
		return NULL;
	}
	
	else if (groupLength == 0)
    {
		free(foodList);
		return NULL;
	}
	
	else if (strspn(group, "0123456789.") == strlen(group)) 
    {
		free(foodList);
        return NULL;
    }
	
	else 
    {
		foodList->foodGroup = strdupVer(group);
	}
	
	//calorie test cases
	if (calories > 0)
    {
		foodList->calories = calories;
	}
	
	else
    {
		free(foodList);
		return NULL;
	}
	
	//theType test cases
	if (theType == 'h' || theType == 'j')
    {
		foodList->type = theType;
	}
	
	else 
    {
		free(foodList);
		return NULL;
	}	
	
	return foodList;
	
}

char * printRecord(Food * toPrint)
{
	if (toPrint == NULL)
    {
		return NULL;
	}
	
	else 
    {
	    char* string = malloc(500);
	    sprintf(string, "%s (%s):%d[%c]", toPrint->name, toPrint->foodGroup,  toPrint->calories, toPrint->type);
	    return string;		
	}

} 

void destroyRecord(Food * toDie)
{
	Food *next;
	
    for (Food *curr = toDie; curr; curr = next)
    {
        next = curr->next;
        free(curr);
    }
	
}

Food * addToFront(Food * theList, Food * toBeAdded)
{
			
	if(isEmpty(theList) == 1)
    {
		toBeAdded->next = theList;
		theList = toBeAdded;
    }

	else 
    {
		Food *tempList;
		tempList = toBeAdded;
		tempList->next = theList;
		theList = tempList;
	}

    return (theList);
}

Food * addToBack(Food * theList, Food * toBeAdded)
{	

	 Food *renamedList = theList;	 
    if (!renamedList) return toBeAdded;
    while (renamedList->next)
    renamedList = renamedList->next;
    renamedList->next = toBeAdded;
    return theList;

}

Food * removeFromFront(Food * theList)
{
	Food *tempList = theList;          
    if (tempList == NULL) return NULL;           
    theList = tempList->next;                  
    free (tempList);                          
	
	return theList;
}

Food * removeFromBack(Food * theList)
{
	Food *tempList = theList;
    Food *preList = NULL;
	
    if (theList == NULL) 
    {
		//do nothing
    } 
	
	else if (theList->next == NULL) 
    {
        theList = NULL;
    } 
	
	else if (theList != NULL) 
    {
        while (tempList->next != NULL) 
        {
            preList = tempList;
            tempList = tempList->next;
        }
        destroyList(tempList);
        preList->next = NULL;
    }
    return (theList);
	
}

Food * getLastItem(Food * theList)
{
	 Food *tempList = theList;
	 
    if (theList==NULL)
    {
         return (tempList);
    }
	
    while (tempList->next != NULL) 
    {
        tempList = tempList->next;
    }
	
    return (tempList);
	
}

Food * getFirstItem(Food * theList)
{
	return(theList);
}

int isEmpty(Food * theList)
{
	if (theList == NULL)
    {
		return 1;
	}
	
	else 
    {
		return 0;
	}
}

void printList(Food * theList)
{
   
    if (theList != NULL) 
    {
	   printf("%s (%s):%d[%c]\n", theList->name, theList->foodGroup, theList->calories, theList->type);
       printList(theList->next);
    }

}

void destroyList(Food * theList)
{
	
    Food* current = theList;
	Food * next;
	
	while (current != NULL) 
    {
		next = current->next;
		free(current);
		current = next;
	}
	
	
}


