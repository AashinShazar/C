#include "linkedList.h"
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <ctype.h>
#include <math.h>

int main(int argc, char**argv)
{
	FILE * testFile;
	char * fileName = argv[1];
	char regBuffer[150];
	 char * strtokString;
	 int i = 0;
	 char * foodName;
	 char * foodGroup;
	 int foodCalories;
	 char foodType;
	 Food * foodItem = malloc(sizeof(Food));
	 Food * foodList = NULL; 
	 int foodCount = 0;
	 int totalCalories = 0;
	 double vegfruitCalories = 0.00;
	 double meatCalories = 0.00;
	 double dariyCalories = 0.00;
	 double grainsCalories = 0.00;
	 double fatCalories = 0.00;
	 double vegfruitCount = 0.00;
	 double meatCount = 0.00;
	 double dairyCount = 0.00;
	 double grainsCount = 0.00;
	 double fatCount = 0.00;
	 double vegfruitcaloriesAvg = 0.00;
	 double meatcaloriesAvg = 0.00;
	 double dariycaloriesAvg = 0.00;
	 double grainscaloriesAvg = 0.00;
	 double fatcaloriesAvg = 0.00;

	testFile = fopen(fileName, "r");	
	while(fgets(regBuffer, 150, testFile) != NULL) 
    {
		
		strtokString = strtok (regBuffer,",");
			while (strtokString != NULL)
            {
				
				switch (i)
                {
					
					case 0:
						foodName = strtokString;
						i++;
						break;
						
					case 1:
						foodGroup = strtokString;
						i++;
						break;
						
					case 2:
						foodCalories = atoi(strtokString);
						totalCalories = foodCalories + totalCalories;
						i++;
						
						if (strcmp(foodGroup, "vegfruit") == 0)
                        {
							vegfruitCalories = foodCalories + vegfruitCalories;
							vegfruitCount++;
						}
						
						else if (strcmp(foodGroup, "meat") == 0)
                        {
							meatCalories = foodCalories + meatCalories;
							meatCount++;
						}
						
						else if (strcmp(foodGroup, "dairy") == 0)
                        {
							dariyCalories = foodCalories + dariyCalories;
							dairyCount++;
						}
						
						else if (strcmp(foodGroup, "grains") == 0)
                        {
							grainsCalories = foodCalories + grainsCalories;
							grainsCount++;
						}
						
						else if (strcmp(foodGroup, "fat") == 0)
                        {
							fatCalories = foodCalories + fatCalories;
							fatCount++;
						}
						
						break;
					
					case 3:
						foodType = *strtokString;
						foodItem = createRecord(foodName, foodGroup, foodCalories, foodType);
						//printf("%s", printRecord(foodItem));
						
						if (foodType == 'h')
                        {
							foodList = addToFront(foodList, foodItem);
						}
						
						else if (foodType == 'j')
                        {
							foodList = addToBack(foodList, foodItem);
						}
						
						if (foodItem != NULL)
                        {
						    foodCount++;
						}
						
						i = 0;
						break;
				}
				
				strtokString = strtok (NULL, ",");
			}	
	}
	
	vegfruitcaloriesAvg = vegfruitCalories / vegfruitCount;
	meatcaloriesAvg = meatCalories / meatCount;
	dariycaloriesAvg = dariyCalories / dairyCount;
	grainscaloriesAvg = grainsCalories / grainsCount;
	fatcaloriesAvg = fatCalories / fatCount;
	
	printf("%d\n", totalCalories); 
	printf("%.2f\n", vegfruitcaloriesAvg);
	printf("%.2f\n", meatcaloriesAvg);
	printf("%.2f\n", dariycaloriesAvg);
	printf("%.2f\n", grainscaloriesAvg);
	printf("%.2f\n", fatcaloriesAvg);
	printf("%d\n", foodCount);
	printList(foodList);
	destroyRecord(foodItem);
	destroyList(foodList);
	
	fclose(testFile);
	 
    return 0;
}

