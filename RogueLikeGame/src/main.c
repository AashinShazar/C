#include "rogue.h"

 /**
* main
* Sets up and controls the entire game
* IN: Takes in file argument for level loading
* OUT: Sets up the entire game based on the parameters specified in the level file
*/
int main (int argc, char**argv)
{
    int ch; 
	Level * level;
	Position  * newPosition;
	screenSetUp();
	char * fileName = argv[1];
	
	//checks for file proper usage and existence
    if (argc != 2) 
    {
         printf("Usage: ./rogue ./assets/yourLevelFileName.txt\n");
         exit(1);
    }
	else 
    {
	    checkFile(fileName);
	}

	//starts the first level
    level = createLevel(1, fileName);

	//enters the game loop
	while ((ch = getch()) != 'q' )
    {  
		newPosition = handleInput(ch, level->user);
		checkPosition(newPosition, level);
		move(level->user->position->y, level->user->position->x);
	} 
	
	gameDisplay(level);
	getch();
	
	endwin();
	
	return 0;
}









