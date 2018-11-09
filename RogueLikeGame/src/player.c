#include "rogue.h"
 
 Player * playerSetup()
{
	Player * newPlayer;
	newPlayer = malloc(sizeof(Player));
	newPlayer->position = malloc(sizeof(Position));

	newPlayer->health = 50;
	newPlayer->attack = 5;
	newPlayer->gold = 0; 
	newPlayer->potionPoss = 1;
	newPlayer->inventory = 0;
	newPlayer->defense = 0;

	return newPlayer;
	
}

int placePlayer(Room ** rooms, Player * user, char * fileName)
{
	char buffer[150];
	FILE * levelFile;
	char * findMe;
	int heroPos;
	int heroPosX;
	int heroPosY;
	int lengthValue;

	levelFile = fopen(fileName, "r");

	//gets hero position
	while (fscanf(levelFile,"%s",buffer) != EOF)
    {
	removeChar(buffer, ',');
	findMe = strtok (buffer, " ");

	if (strstr(findMe, "h") != NULL)
    {
		heroPos = atoi(strtokData(findMe, "h"));
		//gets the length to know if position is a single or double digit
		lengthValue = printLen(heroPos);
		if (lengthValue == 2)
        {
			heroPosX = heroPos / 10;
			heroPosY = heroPos%10;
		}
		else if (lengthValue == 4)
        {
			heroPosX = heroPos / 100;
			heroPosY = heroPos%100;
		}
	}

	}

	fclose(levelFile);  
		
	user->position->x = heroPosX + 10;
	user->position->y = heroPosY + 1;

	mvprintw(user->position->y, user->position->x, "@");
	move(user->position->y, user->position->x);

	return 1;
	
}

Position * handleInput(int input, Player * user)
{
	Position * newPosition; 
	newPosition = malloc(sizeof(Position));
		
	switch (input)
    {
		case 'p':
		case 'P':
			if ((user->potionPoss > 0))
            {
				user->potionPoss--;
				user->health = 50;
				mvprintw(0, 40 , "Player recovered full health!");
				getch();
				mvprintw(0, 40 , "                                                          ");
			 }
			else if  ((user->potionPoss < 1))
            {
				mvprintw(0, 40 , "Player is out of potionPoss!");
				getch();
				mvprintw(0, 40 , "                                                          ");
			 }
			 break;
			 
		case 'w': 
		case 'W':
			newPosition->y = user->position->y - 1;
			newPosition->x = user->position->x;
			break;
			
		case 'a': 
		case 'A':
			newPosition->y = user->position->y;
			newPosition->x = user->position->x - 1;
			break;
			
		case 's': 
		case 'S':
			newPosition->y = user->position->y + 1;
			newPosition->x = user->position->x;	
			break;
			
		case 'd': 
		case 'D':
			newPosition->y = user->position->y;
			newPosition->x = user->position->x + 1;
			break;
			
		default:
			break;
				
	}

	return newPosition;
}

int checkPosition(Position * newPosition, Level * level) 
{
	Player * user;
	user = level->user;
	
	
	switch(mvinch(newPosition->y, newPosition->x))
    {		
		case '<':
		case '>':
			playerMove(newPosition, user, level->tiles);
			mvprintw(0, 40 , "Player stepped on stairs. Game quitting.");
			getch();
			mvprintw(0, 40 , "                                                          ");
			gameDisplay(level);
			getch();
			endwin();
			exit(0);
			break;
			
		case '*':
			playerMove(newPosition, user, level->tiles);
			int goldValue = rand() % 51;
			level->user->gold = level->user->gold + goldValue;
			mvprintw(0, 40 , "Player has collected %d gold!", goldValue);
			getch();
			mvprintw(0, 40 , "                                                          ");
			break;
			
		case '8':
			playerMove(newPosition, user, level->tiles);
			int bigGoldValue = (rand() % 200) + 50;
			level->user->gold = level->user->gold + bigGoldValue;
			mvprintw(0, 40 , "Player has collected %d gold!", bigGoldValue);
			getch();
			mvprintw(0, 40 , "                                                          ");
			break;
			
		case ')':
			playerMove(newPosition, user, level->tiles);		
			if ((level->user->inventory < 5))
            {
				int commonweaponPosValue = rand() % 10 + 1;
				level->user->inventory = level->user->inventory + 1;
				level->user->attack = level->user->attack + commonweaponPosValue;
				mvprintw(0, 40 , "Player has collected picked up ) !");
				getch();
				mvprintw(0, 40 , "                                                          ");
			}
			else if ((level->user->inventory = 5))
            {
				mvprintw(0, 40 , "Player stepped on ) and broke it!");
				getch();
				mvprintw(0, 40 , "                                                          ");
			}
			break;
			
		case '(':
			playerMove(newPosition, user, level->tiles);
			if ((level->user->inventory < 5))
            {
				int rareweaponPosValue = rand() % 5 + 10;
				level->user->inventory = level->user->inventory + 1;
				level->user->attack = level->user->attack + rareweaponPosValue;
				mvprintw(0, 40 , "Player has collected picked up ( !");
				getch();
				mvprintw(0, 40 , "                                                          ");
			}
			else if ((level->user->inventory = 5))
            {
				mvprintw(0, 40 , "Player stepped on ( and broke it!");
				getch();
				mvprintw(0, 40 , "                                                          ");
			}
			break;
			
		case ']':
			playerMove(newPosition, user, level->tiles);
			if ((level->user->inventory < 5))
            {
				int equipmentValue = rand() % 21;
				level->user->inventory = level->user->inventory + 1;
				level->user->defense = level->user->defense + equipmentValue;
				mvprintw(0, 40 , "Player has collected picked up ] !");
				getch();
				mvprintw(0, 40 , "                                                          ");
			}
			else if ((level->user->inventory = 5))
            {
				mvprintw(0, 40 , "Player stepped on ] and broke it!");
				getch();
				mvprintw(0, 40 , "                                                          ");
			}
			break;
			
		case '!':
			playerMove(newPosition, user, level->tiles);
			level->user->potionPoss = level->user->potionPoss + 1;
			mvprintw(0, 40 , "Player has collected picked up a potionPos!");
			getch();
			mvprintw(0, 40 , "                                                          ");
			break;
			
		case '.':
			playerMove(newPosition, user, level->tiles);
			break;
			
		case '+':
			teleportPlayer(newPosition, user, level->tiles, level->doorCount);
			level->doorCount++;
			mvprintw(0, 40 , "Player has opened a door!");
			getch();
			mvprintw(0, 40 , "                                                          ");
			break;
			
		case 'A':
		case 'S':
		case 'B':
		case 'Z':
		case 'T':
		default:
			move(user->position->y, user->position->x); //prevents cursor from moving away from character
			break;
			
	}
	
	return 1;
}

int playerMove(Position * newPosition, Player * user, char ** level)
{		
	char buffer[8];
	sprintf(buffer, "%c", level[user->position->y][user->position->x]);
	mvprintw(user->position->y, user->position->x, ".");

	user->position->y = newPosition->y;
	user->position->x = newPosition->x;
	mvprintw(user->position->y, user->position->x, "@");
	move(user->position->y, user->position->x);
	return 1;
}

int teleportPlayer(Position * newPosition, Player * user, char ** level, int doorCount)
{		
	char buffer[8];
	sprintf(buffer, "%c", level[user->position->y][user->position->x]);
	mvprintw(user->position->y, user->position->x, ".");

	switch (doorCount)
    {
		case 0: //room 1 to room 2
			newPosition->x = 44;
			newPosition->y = 2;
			break;
			
		case 1: //room 2 to room 3
		    newPosition->x = 77;
			newPosition->y = 2;
			break;
			
		case 2: //room 3 to room 4
		    newPosition->x = 11;
			newPosition->y = 18;
			break;
			
		case 3: //room 4 to room 5
		    newPosition->x = 44;
			newPosition->y = 18;
			break;
			
		case 4: //room 5 to room 6
		    newPosition->x = 77;
			newPosition->y = 18;
			break;
			
		case 5: //room 6 to room 1
		    newPosition->x = 11;
			newPosition->y = 2;
			break;
		
	}
	
	user->position->y = newPosition->y;
	user->position->x = newPosition->x;
	mvprintw(user->position->y, user->position->x, "@");
	move(user->position->y, user->position->x);
	return 1;
}


