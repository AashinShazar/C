 #include "rogue.h"
 
 int screenSetUp()
{
	initscr();
	noecho();
	refresh();

	srand(time(NULL));

	return 1;
}

int gameDisplay(Level * level)
{
	mvprintw(0, 0 , "                                                          ");
	mvprintw(40, 10 , "    Health: %d", level->user->health);
	printw("    Potions: %d", level->user->potionPoss);
	printw("    Attack: %d", level->user->attack);
	printw("    Inventory: %d/5", level->user->inventory); 
	printw("    Gold: %d", level->user->gold);
	printw("                 "); //blank one


	return 1;
}
