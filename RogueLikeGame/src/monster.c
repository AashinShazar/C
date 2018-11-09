 #include "rogue.h"

int addMonsters(Level * level, char * fileName)
{
	level->monsters = malloc(sizeof(Monster * ) * 6);
	level->numMonsters = 0;
	char monsterBuffer[150];
	int randWeakMonster;
	int weakMonster;
	int strongMonster;
	FILE * levelFile;
	int weakMonsterX;
	int weakMonsterY;
	int strongMonsterX;
	int strongMonsterY;
	int z = 0;
	int lengthValue;

	//gets monster locations
	levelFile = fopen(fileName, "r");
	while (fgets (monsterBuffer, sizeof(monsterBuffer), levelFile))
    {
	removeChar(monsterBuffer, ',');
	RemoveSpaces(monsterBuffer);
	char *capitalM = replace(monsterBuffer, 'M', "S");
	
	if (strstr(capitalM, "S") != NULL)
    {
		strongMonster = atoi(strtokData(capitalM, "S"));	
		lengthValue = printLen(strongMonster);
	
	if (lengthValue == 2)
    {
		strongMonsterX = strongMonster / 10;
		strongMonsterY = strongMonster%10;
	}
	else if (lengthValue == 4)
    {
		strongMonsterX = strongMonster / 100;
		strongMonsterY = strongMonster%100;
	}

	level->monsters[level->numMonsters] =  createMonster('T', 50, 5, 3, 41, strongMonsterX, strongMonsterY, z);
	setStartPos(level->monsters[level->numMonsters], level->rooms[z]);
	level->numMonsters++;
	}

	else if (strstr(capitalM, "m") != NULL)
    {
		weakMonster = atoi(strtokData(capitalM, "m"));	
		lengthValue = printLen(weakMonster);
	if (lengthValue == 2)
    {
	   weakMonsterX = weakMonster / 10;
	   weakMonsterY = weakMonster%10;
	}
	else if (lengthValue == 4)
    {
		weakMonsterX = weakMonster / 100;
		weakMonsterY = weakMonster%100;
	}

	randWeakMonster = (rand() % 4) + 1;

	switch(randWeakMonster)
    {
		case 1: //aquator	
			level->monsters[level->numMonsters] =  createMonster('A', 5, 1, 2, 0, weakMonsterX, weakMonsterY, z);
			setStartPos(level->monsters[level->numMonsters], level->rooms[z]);
			level->numMonsters++;
			break;
				
		case 2: //bat
			level->monsters[level->numMonsters] =  createMonster('B', 2, 1, 4, 1, weakMonsterX, weakMonsterY, z);
			setStartPos(level->monsters[level->numMonsters], level->rooms[z]);
			level->numMonsters++;
			break;
				
		case 3: //snake
			level->monsters[level->numMonsters] =  createMonster('S', 5, 5, 4, 4, weakMonsterX, weakMonsterY, z);	
			setStartPos(level->monsters[level->numMonsters], level->rooms[z]);
			level->numMonsters++;
			break;
				
		case 4: //zombie
			level->monsters[level->numMonsters] =  createMonster('Z', 15, 5, 2, 2, weakMonsterX, weakMonsterY, z);	
			setStartPos(level->monsters[level->numMonsters], level->rooms[z]);
			level->numMonsters++;
			break;
			
	}

	}

	z++;
	}
	fclose(levelFile);  

	return 1;
}
  
Monster * createMonster(char symbol, int health, int attack, int speed, int pathfinding, int x, int y, int z)
{
	Monster * newMonster; 
	newMonster = malloc(sizeof(Monster));

	newMonster->symbol = symbol;
	newMonster->health = health;
	newMonster->attack = attack;
	newMonster->speed = speed;
	newMonster->pathfinding = pathfinding;
	newMonster->alive = 1;
	newMonster->x = x;
	newMonster->y = y; 
	newMonster->monsterRoom[z] = z;

	sprintf(newMonster->string, "%c", symbol);

	newMonster->position = malloc(sizeof(Position));

	return newMonster;
}
  
 int setStartPos(Monster * monster, Room * room)
 {	 
	monster->position->x = monster->x + room->position.x;
	monster->position->y =  monster->y + room->position.y; 

	mvprintw(monster->position->y, monster->position->x, monster->string);

	return 1;
 }
 
