#ifndef ROGUE_H 
#define ROGUE_H

#include <math.h>
#include <string.h>
#include <ncurses.h>
#include <stdlib.h>
#include <time.h>

typedef struct Level
{ 
	char ** tiles;
	int level;
	int numRooms;
	struct Room ** rooms;
	struct Monster ** monsters;
	int numMonsters; 
	struct Player * user;
	int doorCount;

} Level;

typedef struct Position
{
	int x;
	int y;

} Position;

typedef struct Room
{
	Position position; 
	int height;
	int width;	
	Position ** doors;
	Position ** gold;
	Position ** bigGold;
	Position ** weaponPos;
	Position ** rareweaponPos;
	Position ** potionPos;
	Position ** equipment;
	Position ** stairsUp;
	Position ** stairsDown;

} Room;

typedef struct Player //attributes go here
{
	Position * position;
	int health;
	int attack;
	int gold;
	int inventory;
	int potionPoss;
	int defense;

} Player; 

typedef struct Monster 
{
	char string[2];
	char symbol; 
	int health;
	int attack;
	int speed;
	int pathfinding;
	int alive;
	Position * position; 
	int x;
	int y;
	int monsterRoom[5];

} Monster;

 /**
* screenSetUp
* Sets up screen for the ncurses game
* IN: None
* OUT: Initializes the screen and refreshes at periodic intervals
*/
int screenSetUp();

/**
* gameDisplay
* Displays a status bar with the player stats
* IN: Takes in the Level struct
* OUT: Returns a neatly printed out status bar with player stats
*/
int gameDisplay(Level * level);

   /**
* createLevel
* Creates level one with rooms, player position and everything within the room
* IN: Takes in the level number and filename
* OUT: Returns the newly created newLevel
*/
Level * createLevel(int level, char * fileName);

   /**
* roomSetup
* Parses through file and stores room elements for room creation
* IN: Takes in filename
* OUT: Returns rooms
*/
Room ** roomSetup(char * fileName);

 /**
* saveLevelPositions
* Algorithm that determines how the hallways are generated
* IN: None
* OUT: Returns positions
*/
char ** saveLevelPositions();

/**
* playerSetUp
* Sets up player on map and at certain position
* IN: Takes in the y and x position where the player will be
* OUT: Returns a newPlayer with these values stored in it
*/
Player * playerSetup();

/**
* handleInput
* Controls the player's movement and makes use of potionPoss if any
* IN: Takes in character inputted by user and user struct
* OUT: Returns the player's poisition
*/
Position * handleInput(int input, Player * user);

/**
* checkPostion
* Checks player position at each specific location and performs location specific commands
* IN: Takes in character location and user struct
* OUT: Returns 1
*/
int checkPosition(Position * newPosition, Level * level);

/**
* playerMove
* Controls the player's movement
* IN: Takes in the player's location and user struct and char level
* OUT: Returns 1
*/
int playerMove(Position * newPosition, Player * user, char ** level);

/**
* placePlayer
* Places player based on specified location on file
* IN: Takes in Room struct, Player struct and approriate filename
* OUT: Returns 1
*/
int placePlayer(Room ** rooms, Player * user, char * fileName);

/**
* teleportPlayer
* Teleports player to the next room based on door count number
* IN: Takes in the player's location, user struct, char level and the door count
* OUT: Returns 1
*/
int teleportPlayer(Position * newPosition, Player * user, char ** level, int doorCount);

 /**
* createRoom
* Creates a room based on file input
* IN: Takes in every element within a room
* OUT: Returns a newRoom variable that contains all these elements
* POST: If one or more of these elements are missing, strange things happen
*/
Room * createRoom(int grid, char * fileName, int mapPosY,  int mapPosX, int rightDoor, int leftDoor, int topDoor, int bottomDoor, 
int stairsDown, int stairsUp, int smallGold, int bigGold, int weaponPos, int rareweaponPos, int equipment, int potionPos);

/**
* drawRoom
* Draws the room with the elements that exist
* IN: Takes in the struct values of room
* OUT: Prins out the dimensions of the room and containing elements
*/
int drawRoom(Room * room);

 /**
* addMonsters
* adds Monsters to the specified level
* IN: Takes in the level struct and fileName for monster parsing
* OUT: Places monsters in specified rooms
*/
int addMonsters(Level * level, char * fileName);

 /**
* createMonster
* Creates the monster with specified stats and is stored within a struct
* IN: Takes in monster symbol, health, attack, speed, patrol parameters and it's position in x and y
* OUT: Returns the monster values as a struct
*/
Monster * createMonster(char symbol, int health, int attack, int speed, int pathfinding, int x, int y, int z);

 /**
* setStartPos
* Sets the starting position of the monster
* IN: Takes in monster struct and room struct
* OUT: Places monster in specified location and returns 1
*/
int setStartPos(Monster * monster, Room * room);

/**
* checkFile
* Checks file for its existence
* IN: Takes in the filename
* OUT: Returns an error message if file could not be found
*/
int checkFile(char fileName[]);

/**
* removeChar
* Removes a single character from a string
* IN: Takes in the string and the character to remove from string
* OUT: Returns the string with the removed character
*/
void removeChar(char *string, char trash);

/**
* strtokData
* Finds a specified character within the string
* IN: Takes in the string and the variable to find
* OUT: Returns the found variable from the string
*/
char * strtokData(const char * pch, char * var);

/**
* lenHelper
* Determines length of an integer
* IN: Takes in the integer
* OUT: Returns number of digits within integer
*/
int lenHelper(unsigned x);

/**
* printLen
* Prints out the number of integers based on lenHelper
* IN: Takes in the integer x
* OUT: Prints out the number of digits within integer
*/
int printLen(int x);

/**
* RemoveSpaces
* Removes spaces from a file line 
* IN: Takes in the character array as source
* OUT: Returns the array source back without any spaces
*/
void RemoveSpaces(char* source);

/**
* replace
*  Replaces single character from string
* IN: Takes in the string and the character to replace with
* OUT: Returns the string with the replaced character in string
*/
char *replace(const char *s, char ch, const char *repl);

#endif
