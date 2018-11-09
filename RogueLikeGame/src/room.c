#include "rogue.h"
 
 Room * createRoom(int grid, char * fileName, int mapPosY,  int mapPosX, int rightDoor, int leftDoor, int topDoor, int bottomDoor, 
 int stairsDown, int stairsUp, int smallGold, int bigGold, int weaponPos, int rareweaponPos, int equipment, int potionPos)
{
	Room * newRoom;
	newRoom = malloc(sizeof(Room)); 
	int lengthValue;

	switch (grid)
    {
		case 0:
			newRoom->position.x = 10;
			newRoom->position.y = 1;
			break;
			
		case 1:
			newRoom->position.x = 43;
			newRoom->position.y = 1;
			break;
			
		case 2:
			newRoom->position.x = 76;
			newRoom->position.y = 1;
			break;
			
		case 3:
			newRoom->position.x = 10;
			newRoom->position.y = 17;
			break;
			
		case 4:
			newRoom->position.x = 43;
			newRoom->position.y = 17;
			break;
			
		case 5:
			newRoom->position.x = 76;
			newRoom->position.y = 17;
			break;
			
	}
	
	newRoom->height = mapPosY;
	newRoom->width = mapPosX;
	
	
	//malloc room elements
	newRoom->doors = malloc(sizeof(Position) * 4);
	newRoom->gold = malloc(sizeof(Position) * 1);
	newRoom->bigGold = malloc(sizeof(Position) * 1);
	newRoom->weaponPos = malloc(sizeof(Position) * 6);
	newRoom->rareweaponPos = malloc(sizeof(Position) * 1);
	newRoom->equipment = malloc(sizeof(Position) * 1);
	newRoom->potionPos = malloc(sizeof(Position) * 1);
	newRoom->stairsUp = malloc(sizeof(Position) * 1);
	newRoom->stairsDown = malloc(sizeof(Position) * 1); 
	
	//top doors
	newRoom->doors[0] = malloc(sizeof(Position));
	newRoom->doors[0]->y = newRoom->position.y;
	newRoom->doors[0]->x = topDoor + newRoom->position.x; 

	//left doors
	newRoom->doors[1] = malloc(sizeof(Position));
	newRoom->doors[1]->y = leftDoor + newRoom->position.y;
	newRoom->doors[1]->x = newRoom->position.x;

	//bottom doors
	newRoom->doors[2] = malloc(sizeof(Position));
	newRoom->doors[2]->y = newRoom->position.y + newRoom->height - 1;
	newRoom->doors[2]->x = bottomDoor + newRoom->position.x;
	
	//right doors
	newRoom->doors[3] = malloc(sizeof(Position));
	newRoom->doors[3]->y = rightDoor + newRoom->position.y;
	newRoom->doors[3]->x = newRoom->position.x + newRoom->width - 1;
		
	//gold
	newRoom->gold[0] = malloc(sizeof(Position));	
	lengthValue = printLen(smallGold);
	//basically checking for x and y coordinates that are 2 digits or 1 digit
	if (lengthValue == 2)
    {
		newRoom->gold[0]->x = smallGold / 10 + newRoom->position.x; 
		newRoom->gold[0]->y = smallGold%10 + newRoom->position.y;
	}
	else if (lengthValue == 4)
    {
		newRoom->gold[0]->x = smallGold / 100 + newRoom->position.x; 
		newRoom->gold[0]->y = smallGold%100 + newRoom->position.y;
	}
	
	//big gold
	newRoom->bigGold[0] = malloc(sizeof(Position));
	lengthValue = printLen(bigGold);
	if (lengthValue == 2)
    {
		newRoom->bigGold[0]->x = bigGold / 10 + newRoom->position.x; 
		newRoom->bigGold[0]->y = bigGold%10 + newRoom->position.y;
	}
	else if (lengthValue == 4)
    {
		newRoom->bigGold[0]->x = bigGold / 100 + newRoom->position.x; 
		newRoom->bigGold[0]->y = bigGold%100 + newRoom->position.y;
	}
	
	//weaponPos
	newRoom->weaponPos[0] = malloc(sizeof(Position));
	lengthValue = printLen(bigGold);
	if (lengthValue == 2)
    {
		newRoom->weaponPos[0]->x = weaponPos / 10 + newRoom->position.x; 
		newRoom->weaponPos[0]->y = weaponPos%10 + newRoom->position.y;
	}
	else if (lengthValue == 4)
    {
		newRoom->weaponPos[0]->x = weaponPos / 100 + newRoom->position.x; 
		newRoom->weaponPos[0]->y = weaponPos%100 + newRoom->position.y;
	}
	else
    {//do nothing
	}
	
	//rare weaponPos
	newRoom->rareweaponPos[0] = malloc(sizeof(Position));
	lengthValue = printLen(rareweaponPos);
	if (lengthValue == 2)
    {
		newRoom->rareweaponPos[0]->x = rareweaponPos / 10 + newRoom->position.x; 
		newRoom->rareweaponPos[0]->y = rareweaponPos%10 + newRoom->position.y;
	}
	else if (lengthValue == 4)
    {
		newRoom->rareweaponPos[0]->x = rareweaponPos / 100 + newRoom->position.x; 
		newRoom->rareweaponPos[0]->y = rareweaponPos%100 + newRoom->position.y;
	}
	else
    {//do nothing
	}
	
	//equipment
	newRoom->equipment[0] = malloc(sizeof(Position));
	lengthValue = printLen(equipment);
	if (lengthValue == 2)
    {
		newRoom->equipment[0]->x = equipment / 10 + newRoom->position.x; 
		newRoom->equipment[0]->y = equipment%10 + newRoom->position.y;
	}
	else if (lengthValue == 4)
    {
		newRoom->equipment[0]->x = equipment / 100 + newRoom->position.x; 
		newRoom->equipment[0]->y = equipment%100 + newRoom->position.y;
	}
	else
    {//do nothing
	}
	
	//potionPos
	newRoom->potionPos[0] = malloc(sizeof(Position));
	lengthValue = printLen(potionPos);
	if (lengthValue == 2)
    {
		newRoom->potionPos[0]->x = potionPos / 10 + newRoom->position.x; 
		newRoom->potionPos[0]->y = potionPos%10 + newRoom->position.y;
	}
	else if (lengthValue == 4)
    {
		newRoom->potionPos[0]->x = potionPos / 100 + newRoom->position.x; 
		newRoom->potionPos[0]->y = potionPos%100 + newRoom->position.y;
	}
	
	//stairsUp
	newRoom->stairsUp[0] = malloc(sizeof(Position));
	lengthValue = printLen(stairsUp);
	if (lengthValue == 2)
    {
		newRoom->stairsUp[0]->x = stairsUp / 10 + newRoom->position.x; 
		newRoom->stairsUp[0]->y = stairsUp%10 + newRoom->position.y;
	}
	else if (lengthValue == 4)
    {
		newRoom->stairsUp[0]->x = stairsUp / 100 + newRoom->position.x; 
		newRoom->stairsUp[0]->y = stairsUp%100 + newRoom->position.y;
	}
	
	//stairsDown
	newRoom->stairsDown[0] = malloc(sizeof(Position));
	lengthValue = printLen(stairsDown);
	if (lengthValue == 2)
    {
		newRoom->stairsDown[0]->x = stairsDown / 10 + newRoom->position.x; 
		newRoom->stairsDown[0]->y = stairsDown%10 + newRoom->position.y;
	}
	else if (lengthValue == 4)
    {
		newRoom->stairsDown[0]->x = stairsDown / 100 + newRoom->position.x; 
		newRoom->stairsDown[0]->y = stairsDown%100 + newRoom->position.y;
	}
	
	return newRoom;
}

int drawRoom(Room * room) 
{
	
	int x;
	int y;
	int z;
	
	//draws the room with all it's - and |
	for (x = room->position.x; x < room->position.x  + room->width; x++) //draw top and bottom
    {
		mvprintw(room->position.y, x, "-"); //top
		mvprintw(room->position.y + room->height - 1, x, "-"); //bottom
	}
	
	for (y = room->position.y + 1; y < room->position.y + room->height - 1; y++) //draws floors and side walls
    {
		mvprintw(y, room->position.x, "|"); //side
		mvprintw(y, room->position.x + room->width - 1, "|");
		
		for (x = room->position.x + 1; x <room->position.x + room->width - 1; x++)
        {
			mvprintw(y, x, "."); //floors
		}
	}
	
	
	//drawing doorss
	for (z = 0; z < 4; z++)
    {
		
	if (room->doors[z]->y != 0 || room->doors[z]->x != 0)
    {
		mvprintw(room->doors[z]->y, room->doors[z]->x, "+");
	}
	
	else 
    {
		// nothing is drawn
	}
	}

	//drawing items
	mvprintw(room->gold[0]->y, room->gold[0]->x, "*");
	mvprintw(room->bigGold[0]->y, room->bigGold[0]->x, "8");
	mvprintw(room->weaponPos[0]->y, room->weaponPos[0]->x, ")");
	mvprintw(room->rareweaponPos[0]->y, room->rareweaponPos[0]->x, "(");
	mvprintw(room->potionPos[0]->y, room->potionPos[0]->x, "!");
	mvprintw(room->stairsUp[0]->y, room->stairsUp[0]->x, ">");
	mvprintw(room->stairsDown[0]->y, room->stairsDown[0]->x, "<");
	mvprintw(room->equipment[0]->y, room->equipment[0]->x, "]");

	
	return 1; 
}
