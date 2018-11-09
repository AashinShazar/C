  #include "rogue.h"
  
 Level * createLevel(int level, char * fileName)
 {
    Level * newLevel;
	newLevel = malloc(sizeof(Level));
	 
	newLevel->level = level;
	newLevel->numRooms = 6;
	newLevel->rooms = roomSetup(fileName);
	newLevel->tiles = saveLevelPositions();
	 
	newLevel->user = playerSetup();
	placePlayer(newLevel->rooms, newLevel->user, fileName);
	 
	addMonsters(newLevel, fileName);
	 
	return newLevel;
	 
 }
  
 Room ** roomSetup(char * fileName)
{
    Room  ** rooms;
	rooms = malloc(sizeof(Room) * 6);

	char roomBuffer[150];
	char mapBuffer[150];
	FILE * levelFile;
	int y = 0;
	int a = 0; 
    int mapPosXArray[5];
    int mapPosYArray[5];
	int mapPos;
	int mapPosX;
	int mapPosY;
	int topDoor;
	int leftDoor;
	int rightDoor;
	int bottomDoor;
	int lengthValue;
	int stairsDown;
	int stairsUp;
	int smallGold;
	int bigGold;
	int weaponPos;
	int rareweaponPos;
	int equipmentPos;
	int potionPos;
	char wordFind[150];
	
	//gets the room dimensions
    levelFile = fopen(fileName, "r");	
	while(fgets(mapBuffer, 150, levelFile) != NULL) 
    {
    wordFind[0] = '\0';
    sscanf(mapBuffer, "%s", wordFind);
	removeChar(wordFind, 'X');
	mapPos = atoi(wordFind);
    lengthValue = printLen(mapPos);
	
    if (lengthValue == 2)
    {
		mapPosXArray[a] = mapPos / 10;
		mapPosYArray[a] = mapPos%10;
	}
    else 
    {
		mapPosXArray[a] = mapPos / 100;
		mapPosYArray[a] = mapPos%100;
	}
	
	a++;
	}
	
    fclose(levelFile);

	//gets the room elements
	levelFile = fopen(fileName, "r");
	while (fgets (roomBuffer, sizeof(roomBuffer), levelFile))
    {
		char *removeComma = replace(roomBuffer, ',', "");
				
		if (strstr(removeComma, "de") != NULL)
        {
			rightDoor = atoi(strtokData(removeComma, "de"));
		}
		if (strstr(removeComma, "dw") != NULL)
        {
			leftDoor = atoi(strtokData(removeComma, "dw"));
		}
		if (strstr(removeComma, "dn") != NULL)
        {
			topDoor = atoi(strtokData(removeComma, "dn"));
		}
		if (strstr(removeComma, "ds") != NULL)
        {
			bottomDoor = atoi(strtokData(removeComma, "ds"));
		}
		if (strstr(removeComma, "z") != NULL)
        {
			stairsDown = atoi(strtokData(removeComma, "z"));	
		}
		if (strstr(removeComma, "a") != NULL)
        {
			stairsUp = atoi(strtokData(removeComma, "a"));	
		}
		if (strstr(removeComma, "g") != NULL)
        {
			smallGold = atoi(strtokData(removeComma, "g"));	
		}
		if (strstr(removeComma, "G") != NULL)
        {
			bigGold = atoi(strtokData(removeComma, "G"));	
		}
		if (strstr(removeComma, "w") != NULL) //careful not to get door west values instead
        {
			weaponPos = atoi(strtokData(removeComma,"w"));	
		}
		if (strstr(removeComma, "W") != NULL)
        {
			rareweaponPos = atoi(strtokData(removeComma, "W"));	
		}
		if (strstr(removeComma, " e") != NULL) //careful not to get door east values instead
        {
			equipmentPos = atoi(strtokData(removeComma, " e"));	
		}
		if (strstr(removeComma, "p") != NULL)
        {
			potionPos = atoi(strtokData(removeComma, "p"));	
		}

		mapPosX = mapPosXArray[y];
		mapPosY = mapPosYArray[y];

		rooms[y] = createRoom(y, fileName , mapPosY, mapPosX, rightDoor, leftDoor, topDoor, bottomDoor, 
		stairsDown, stairsUp, smallGold, bigGold, weaponPos, rareweaponPos, equipmentPos, potionPos);
		drawRoom(rooms[y]);

		y++;
	}
	
	fclose(levelFile);  
		
	return rooms;
}

char ** saveLevelPositions()
{
	int x, y;
	char ** positions;
	positions = malloc(sizeof(char *) * 25 );

	for (y= 0; y < 25; y++)
    {
		positions[y] = malloc(sizeof(char) * 100);
		
		for (x = 0; x < 100; x++)
        {
			positions[y][x] = mvinch(y, x);
		}
	}
	
	return positions;
}
