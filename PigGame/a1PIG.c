/**********************
The Game of Pig
Aashin Shazar
Oct 17/2015
This is the C code version
of the game of Pig
************************/

#include <stdio.h> //Used for printf
#include <stdlib.h>
#include <time.h> //Used for random dice value generation

/******
PrintMsg: Prints diceRoll value and corresponding dice image
In: int diceRoll
Out: int
Post: diceRoll value is printed in text and image
*******/
void showDice (int diceRoll) //showDice function
{
    
    printf("The dice rolls a %d\n", diceRoll);
    
    if (diceRoll == 1){
        printf("+-------+\n");
        printf("|       |\n");
        printf("|   O   |\n");
        printf("|       |\n");
        printf("+-------+\n");
    }
    
    else if (diceRoll == 2) {
        printf("+-------+\n");
        printf("| o     |\n");
        printf("|       |\n");
        printf("|     o |\n");
        printf("+-------+\n");
    }
    
    else if (diceRoll == 3) {
        printf("+-------+\n");
        printf("| o     |\n");
        printf("|   o   |\n");
        printf("|     o |\n");
        printf("+-------+\n");
    }
    
    else if (diceRoll == 4) {
        printf("+-------+\n");
        printf("| o   o |\n");
        printf("|       |\n");
        printf("| o   o |\n");
        printf("+-------+\n");
    }
    
    else if (diceRoll == 5) {
        printf("+-------+\n");
        printf("| o   o |\n");
        printf("|   o   |\n");
        printf("| o   o |\n");
        printf("+-------+\n");
    }
    
    else if (diceRoll == 6) {
        printf("+-------+\n");
        printf("| o   o |\n");
        printf("| o   o |\n");
        printf("| o   o |\n");
        printf("+-------+\n");
    }
    
    
}

int main(void) {
    
    char playerMove; //the (r)oll or (h)old char will be stored in this character
    int gameTotal = 0; //the gameTotal as an integer
    int player1Score = 0; //player 1's score as an integer
    int player2Score = 0; //player 2's score as an integer
    int diceVal; //the value of the dice roll is stored in this integer
    char gameStatus = 'y'; //whether a player wants to play again or not is stored in this character
    int true = 1; //for the do while loop may continue
    int gameOver = 0; //a custom variable integer made to check whether or not a player's score is more than the gameTotal
    
    
    do{ //main loop that has a majority of the game code in it
        
        printf("Welcome To The Game of Pig\n"); //a little ASCII art of a pig
        printf("==========================\n");
        printf("    ,__         __,       \n");
        printf("     \\)`\\_..._/`(/        \n");
        printf("     .'  _   _  '.        \n");
        printf("    /    o\\ /o   \\        \n");
        printf("    |    .-.-.    |  _    \n");
        printf("    |   /() ()\\   | (,`)  \n");
        printf("   / \\  '-----'  / \\ .'   \n");
        printf("  |   '-..___..-'   |     \n");
        printf("  |                 |     \n");
        printf("  |                 |	  \n");
        printf("  ;                 ;     \n");
        printf("   \\      / \\      /      \n");
        printf("    \\-..-/'-'\\-..-/       \n");
        printf("     \\/\\/     \\/\\/        \n");
        
        printf("What is the game total? "); //asks the users what the gameTotal is
        scanf("%d", &gameTotal); //that integer is stored in the gameTotal variable
        
        
        do{ //a do while player 1's or 2's score does not equal the game total, game will keep running
            
            
            
            printf("------------------------------\n");  //some dashes for cleaniless and for readability
            printf("Player1 (score = %d)\n", player1Score); //prints player 1's score
            printf("------------------------------\n");
            
            printf("(R)oll or (H)old?: "); //asks player 1 to either roll or hold
            scanf(" %c%*c", &playerMove); //their choice is stored in a char variable named playerMove
            
            if (playerMove == 'R' || playerMove == 'r'){ //if player 1 selected roll, runs the showDice function
                srand(time(NULL)); //random time function
                diceVal = (rand() % 6) + 1; //assigns the random function to the diceVal integer
                showDice(diceVal); //the randomly generated dice roll is stored in diceVal and is then passed through showDice
                
                if (diceVal == 1) //if the dice value that is rolled is a one, player loses a turn
                {
                    printf("Sorry Player 1, you lose a turn. \n"); //immediately becomes player 2's turn
                    while (true == 1) {
                        
                        printf("Your turn Player2! (score = %d)\n", player2Score); //prints player 2's score
                        printf("(R)oll or (H)old?: "); //asks player 2 to either roll or hold
                        scanf(" %c%*c", &playerMove); //their choice is stored in a char variable named playerMove
                        
                        if (playerMove == 'R' || playerMove == 'r'){ //if player 2 selected roll, runs the showDice function
                            srand(time(NULL)); //random time function
                            diceVal = (rand() % 6) + 1; //assigns the random function to the diceVal integer
                            showDice(diceVal); //the randomly generated dice roll is stored in diceVal and is then passed through showDice
                            
                            if (diceVal == 1)
                            {
                                printf("Sorry Player 2, you lose a turn\n");
                                printf("Your turn Player1! (score = %d)\n", player1Score);
                                break;
                            }
                            
                            else {
                                player2Score = player2Score + diceVal; //adds the dice roll value to player 2's score
                                if (gameTotal <= player1Score) //simply checks if either player score's is greater than the gameTotal
                                {
                                    gameOver = 1; //if it is, it will asign the gameOver function a value of 1, signifing to the loop that the game has ended
                                    break;
                                }
                                
                                else if (gameTotal <= player2Score)
                                {
                                    gameOver = 1;
                                    break;
                                }
                            }
                        }
                        
                        else if(playerMove == 'h' || playerMove == 'H'){ //if player selected hold, it becomes player 1's turn
                            printf("Player2 decides to hold ! ");
                            printf("Player2 (score = %d)\n", player2Score);
                            printf("Your turn Player1 !\n");
                            break;
                        }
                        
                        else {
                            printf("Stop pigging around Player2 ! (R)oll or (H)old? \n"); //if player inputs an invalid option, it asks them to type it again
                        }
                        
                    }//end of player 2's loop
                    
                }
                
                else {
                    player1Score = player1Score + diceVal;
                    if (gameTotal <= player1Score)
                    {
                        gameOver = 1;
                        break;
                    }
                    
                    else if (gameTotal <= player2Score)
                    {
                        gameOver = 1;
                        break;
                    }
                }
            }
            
            else if(playerMove == 'H' || playerMove == 'h'){ //if player selected hold, it becomes player 2's turn
                printf("Player1 decides to hold! ");
                printf("Player1 (score = %d)\n", player1Score);
                printf("------------------------------\n");
                printf("Your turn Player2 !\n");
                
                while (true == 1) {
                    
                    printf("------------------------------\n");
                    printf("Player2 (score = %d)\n", player2Score);
                    printf("------------------------------\n");
                    
                    printf("(R)oll or (H)old?: ");
                    scanf(" %c%*c", &playerMove);
                    
                    if (playerMove == 'R' || playerMove == 'r'){
                        srand(time(NULL));
                        diceVal = (rand() % 6) + 1;
                        showDice(diceVal);
                        
                        if (diceVal == 1)
                        {
                            printf("Sorry Player 2, you lose a turn\n");
                            printf("Your turn Player1! (score = %d)\n", player1Score);
                            break;
                        }
                        
                        else {
                            player2Score = player2Score + diceVal;
                            if (gameTotal <= player1Score)
                            {
                                gameOver = 1;
                                break;
                            }
                            
                            else if (gameTotal <= player2Score)
                            {
                                gameOver = 1;
                                break;
                            }
                        }
                    }
                    
                    else if(playerMove == 'h' || playerMove == 'H'){ //if player selected hold, it becomes player 2's turn
                        printf("Player2 decides to hold ! ");
                        printf("Player2 (score = %d)\n", player2Score);
                        printf("------------------------------\n");
                        printf("Your turn Player1 !\n");
                        break;
                    }
                    
                    else {
                        printf("Stop pigging around Player2 ! (r)oll or (h)old? \n"); //if player inputs an invalid option, it asks them to type it again
                    }
                    
                }//end of player 2's loop
                
            }
            
            else {
                printf("Stop pigging around Player1 ! (R)oll or (H)old? \n"); //if player inputs an invalid option, it asks them to type it again
            }
            
            
            
        }while(gameOver == 0); //the do while loop keeps checking if the gameTotal is greater than player Score
        
        printf("Game over! ");
        
        if (player1Score >= gameTotal) //a simple if statement to congratulate the right player
        {
            printf("Congrats Player 1 on winning!\n");
        }
        
        else if (player2Score >= gameTotal) //simply compares the player score to the gameTotal
        {
            printf("Congrats Player 2 on winning!\n");
        }
        
        printf("Would you like to play again? Type (y)es or (n)o. \n"); //a simple question asking to play again
        scanf("%c%*c", &gameStatus);
        
        system("clear"); //clears screen and makes the game look tidier
		gameTotal = 0; //resets all the scores and values back to 0 in the case of rematch
		player1Score = 0; 
		player2Score = 0; 
		gameOver = 0;
    }while(gameStatus == 'y');//End of entire game loop
    
    
    return 0;
}
