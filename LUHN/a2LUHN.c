/******************************************
Luhn's Algorithm
Aashin Shazar
November 29/2015
This is the C code version of
Luhn's Algorithm (credit card checker)
******************************************/

#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int readCC (char cardNumber[]);
int runLuhn (int validCard[]);
void isValid (int validCard[]);

int main(void) {
    
    int returnValue[15];
    char cardNumber [50];
    
    printf("Please enter the credit card number: ");
    scanf("%s", cardNumber);
    
    returnValue[15] = readCC(cardNumber); //value returned from readCC is stored in int variable, returnValue
    
    isValid(returnValue); //above int variable, returnValue,is then passed to next function
    
    return 0;
}

/*******************************************************************************
readCC: Checks for valid card number length and converts char array to int array
In: char cardNumber[]
Out: validCard[15]
Post: Returns validCard[15] as integer array
*******************************************************************************/
int readCC (char cardNumber[]){
    
    int validCard[15];
    int i;
    
    printf("\n");
    
    if (strlen(cardNumber) == 16) //strlen functions checks string length
    {
        printf("The credit card number you entered is of correct length! Proceeding...\n");
        
        for (i = 0; i < 16; ++i) //equates every position in char array to int array
        {
            validCard[i] = cardNumber[i];
        }
        return validCard[15]; //returns the final int array for use for next function
    }
    
    else
    {
        printf("The Credit Card number you just entered is invalid.\n");
        printf("Exiting the program now!");
        exit(0);
        
        return 0;
    }
    
}

/**************************************************************************************
runLuhn: Runs a calculation on whether the sum of the card number is divisible by 10
In: int validCard[]
Out: finalSum % 10 == 0
Post: Returns finalSum to be passed on to next function
**************************************************************************************/
int runLuhn (int validCard[]){
    
    int oddSum;
    int evenSum;
    int finalSum;
    int partialSum;
    int i;
    int a;
    
    
    for (i = 15; i > 0; i--) //reverses array
    {
        for (a = 1; a < 15; a++)
        {
            validCard[i] = validCard[a];
        }
    }
    
    for (i = 1; i < 16; i++) //code to sum the even digits
    {
        if( i % 2 == 0)
        {
            validCard[i] = validCard[i] * 2;
            
            if (validCard[i] > 9) //code to sum the even partial digits
            {
                partialSum =  partialSum + (validCard[i] - 9);
            }
            
            else
            {
                evenSum = evenSum + validCard[i];
            }
        }
        
        else // code to sum odd digits
        {
            oddSum = oddSum + validCard[i];
        }
    }
    
    finalSum = partialSum + evenSum + oddSum;
    
    return finalSum % 10 == 0;
}

/*******************************************************************************
isValid: Based on runLuhn's output, checks if credit card is a valid one
In: int validCard[]
Out: None
Post: Prints if credit card is valid or invalid
*******************************************************************************/
void isValid (int validCard[]){
    
    int returnValue2;
    
    returnValue2 = runLuhn(validCard); //references another returnValue to the output of runLuhn's function
    
    if (returnValue2 == 0) //if it is 0, meaing it was divisible by 10, it is a valid number
    {
        printf("The credit card number entered is valid!\n");
    }
    else
    {
        printf("The credit card number entered is invalid!\n");
    }
    
    
    return;
}