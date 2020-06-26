/*****************************************************************
** Program: 	Final Project Game
** Author: 		Richard Nguyen
** Date:		12/9/2019
** Description: Contains main function. Train Escape Game.
				Player moves to separate train cars (linked nodes)
				to collect items. Certain items may be used to escape.
				Player loses if time runs out. 
******************************************************************/

#include <iostream>

#include "menu.hpp"
#include "game.hpp"
#include "item.hpp"

using std::cout;
using std::cin;
using std::endl;

int main()
{
	// start menu
	while (true)
	{
		// Get user menu choice
		int startingChoice = menu("\n\n** START MENU **\n1. Start new game\n2. Exit\n\nChoose an Option: ",1,2);
		if (startingChoice==2)
		{
			cout << "\nexiting.." << endl;
			exit(0);
		}
		else if (startingChoice == 1)
		{
			// Start dialogue
			cout << "\n\n\n\n-------\nGAME INSTRUCTIONS:\nIn this game, your goal is to escape from the runaway train before it crashes."
					<<"\nMove to different areas of the train to find useful items to aid in your escape."
					<<"\nThere are limited escape options that work only if you collected the right items."
					<<"\nMoving between cars, searching for items, and failed escapes will run your time down."
					<<"\nExamining surroundings, checking location/map/inventory does not use time."
					<<"\nGood luck!\n--------\n";
			// Start game
			game game1;
		}
	} 
	return 0;
}