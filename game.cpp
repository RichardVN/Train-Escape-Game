/*****************************************************************
** 	Program name:	game.cpp
**	Author: 		Richard Nguyen
** 	Date:			12/10/19
** 	Description:	Contains member function definitions for the class
					game. Contains function definitions for gameplay flow
******************************************************************/


#include "game.hpp"

// Default Constructor
game::game() 
{
	// dynamically allocate player 
	player = new Player;

	// create train, array of pointers to spaces
		// cout << "\nconstructing Train array";
		for (int i = 0; i < trainSize; ++i)
		{
			train[i] = nullptr;
		}
	
	// initialize the train array of space ptrs with specific child classes
	// go into each car node and link the nodes with pointers to one another
	train[0] = &conductorCar;
	train[0]->back = &passengerCar1;
	train[0]->forward = nullptr;

	train[1] = &passengerCar1;
	train[1] -> setCarName("Front Passenger Car");
	train[1]->back = &passengerCar2;
	train[1]->forward = &conductorCar;
	
	train[2] = &passengerCar2;
	train[2] -> setCarName("Rear Passenger Car");
	train[2]->back = &diningCar;
	train[2]->forward = &passengerCar1;
	

	train[3] = &diningCar;
	train[3]->back = &sleeperCar;
	train[3]->forward = &passengerCar2;
	
	train[4] = &sleeperCar;
	train[4]->back = &cabooseCar;
	train[4]->forward = &diningCar;
	
	train[5] = &cabooseCar;
	train[5] -> setCarName("Caboose");
	train[5]->back = nullptr;
	train[5]->forward = &sleeperCar;
	
	// set player's initial location to rear passenger car
	player -> location = &passengerCar2;

	// Initial game rounds: 
	while(!player->gotItem("Candle"))
	{
	int startChoice = menu("\n\n\n\n\n** GAME OPTIONS **\n1. View Train Layout\n2. View Item Inventory\n3. Move towards head of the train.\n4. Move towards rear of the train.\n5. Search room for item. \n6. Attempt Escape from this room.\n7. Where am I?\n8. Examine surroundings.\n9. Exit the game.\n\nChoose an Option: ",1,9);
	if (startChoice == 1)
	{
		cout << "\n----------\n";
		cout << "\nLAYOUT:\nYou recall the mapping of the train structure.\n";
		printCars();
		cout << "\n----------\n";
	}
	else if (startChoice == 2)
	{
		cout << "\n----------\n";
		cout <<"\nINVENTORY:\nYou look inside your bag. Everything has been stolen.\nYou only have a pair of matchsticks in your pockets.\n";
		cout << "\n----------\n";
	}
	else if (startChoice == 3 || startChoice == 4)
	{
		cout << "\n----------\n";
		cout << "\nIt is too dark to find your way to another room!\n";
		cout << "\n----------\n";
	}
	else if(startChoice == 5)
	{
		cout << "\n----------\n";
		cout << "\nSEARCH:\nSearching the ground with your hands, you find a dusty old candle.\nIt takes a couple of tries but you light it with your matchsticks.\n";
		getItem(player -> location, player);
		cout << "\n\nAdjusting your eyes to the sudden light, you find yourself in the rear passenger car.\n"
				<<"\nYou are unsettled as you realize that there is no one around you.\n"
				<<"\nYou approach the window and see that it is snowing heavily.\n"
				<<"\nTo your alarm, the train has derailed and is rapidly approaching the side of a mountain.\n";
		cout << "\n----------\n";
	}
	else if (startChoice == 6)
	{
		cout << "\n----------\n";
		cout << "\nESCAPE:\nYou fumble around in the darkness and find what seems to be a window. \nBut it is too strong to break by hand...\n";
		cout << "\n----------\n";
	}
	else if (startChoice == 7)
	{
		cout << "\n----------\n";
		cout << "\nLOCATION:\nThe last thing you can remember is that you were boarding the train. \nYou felt a sharp impact from behind and everything went black.\n";
		cout << "\n----------\n";
	}
	else if (startChoice==8)
	{	
		cout << "\n----------\n";
		cout << "\nEXAMINE ROOM:\nIt is pitch black and the only noise you hear is from the rumbling movement of the train.\n";
		cout << "\n----------\n";;
	}
	else if (startChoice == 9)
	{
		cout << "\nExiting game.." << endl;
		exit(0);
	}
}

	// Gameplay Turn loop until time runs out or player escapes
	while(checkGameOver()==false && checkGameWin() == false)
	{
		turnMenu();
	}

	// free player ptr memory
	delete player;
}

//******************************
// Default destructor		   *
//******************************

game::~game() 
{

}

//******************************
// Gameplay Functions  		   *
//******************************
// check if time ran out
bool game::checkGameOver()
{
	if (minutes == 0)
	{
		cout << "\nYou were not able to escape in time.\nThe train crashes into the side of the mountain leading to your unfortunate demise."
				<< "\nGAME OVER\n";
		return true;
	}
	else return false;
}

// check if game was won
bool game::checkGameWin()
{
	if (wonGame)
	{
		cout << "\nYou successfully escaped the runaway train! You live to ride another day. \nGAME OVER\n";
		return true;
	}
	else return false;
}

// set to wonGame to true if successful escape
void game::winGame()
{
	this -> wonGame = true;
}

// repeating menu of player options
void game::turnMenu()
{
	cout << "\n\n\n\n-- TIME BEFORE IMPACT: " << minutes << " MINUTES --\n** GAME OPTIONS **"; 


	int choice = menu("1. View Train Layout\n2. View Item Inventory\n3. Move towards head of the train.\n4. Move towards rear of the train.\n5. Search room for item. \n6. Attempt Escape from this room.\n7. Where am I?\n8. Examine surroundings\n9. Exit the game.\n\nChoose an Option:",1,9);
	if (choice == 1)
	{
		cout << "\n----------\nLAYOUT:\n";
		printCars();
		cout << "\n----------\n";
	}
	else if (choice == 2)
	{
		cout << "\n----------\nINVENTORY:\n";
		player->printInventory();
		cout << "\n----------\n";
	}
	else if (choice == 3)
	{
		cout << "\n----------\nMOVE TOWARDS FRONT:\n";
		moveForward();
		cout << "\n----------\n";
	}
	else if(choice == 4)
	{
		cout << "\n----------\nMOVE TOWARDS BACK:\n";
		moveBack();
		cout << "\n----------\n";
	}
	else if(choice == 5)
	{
		cout << "\n----------\nSEARCH:\n";
		getItem(player -> location, player);
		cout << "\n----------\n";
	}
	else if (choice == 6)
	{
		cout << "\n----------\nESCAPE:\n";
		escape();
		cout << "\n----------\n";
	}
	else if (choice == 7)
	{
		cout << "\n----------\nLOCATION:\n";
		findPlayer();
		cout << "\n----------\n";
	}
	else if (choice==8)
	{
		cout << "\n----------\nEXAMINE ROOM:\n";
		describe(player->location);
		cout << "\n----------\n";
	}
	else if (choice == 9)
	{
		cout << "\nExiting game..\n" << endl;
		exit(0);
	}
}

// print order of cars
void game::printCars()
{
	cout << "\nThe train layout from front to back: \n";
	int itemCount=0;
	for (int i = 0; i < trainSize; ++i)
	{
		if (train[i]!=nullptr)
		{
			itemCount++;
			cout <<" - "<< train[i] -> getCarName() << endl;
		}
	}
}

// print player location
void game::findPlayer()
{
	cout <<"\nYou are now at the " << player -> location -> getCarName();
}

// player attempts escape from current room
// escape options only in passenger cars
// front passenger car requires ladder, rear passenger car requires hammer
void game::escape()
{

	if (player->location->getCarName()=="Conductor Car")
	{
		cout << "\nThere doesn't seem to be a feasible way to escape from the conductor's car.";
		if (hasBrake == true)
		{
			cout << "\nYou pull on the brake lever, slowing the speed of the train. This should buy some time.\n";
			minutes += 5;
			hasBrake = false;
		}
		
	}
	else if (player->location->getCarName()=="Front Passenger Car")
	{
		cout << "\nAttempting to escape from the front Passenger Car.";
		if (player->gotItem("Ladder"))
		{
			cout << "\nYou set the ladder underneath the escape hatch.\nYou climb out of the hatch and jump out onto the soft snow below.";
			wonGame = true;
		}
		else
		{
			cout << "\nThe escape hatch is far too high to reach! You need some way to climb up there..";
			minutes--;
		}
		
	}
	else if (player->location->getCarName()=="Rear Passenger Car")
	{
		cout << "\nAttempting to escape from the rear Passenger Car.";
		if (player->gotItem("Hammer"))
		{
			cout << "\nYou drive the hammer against the window with all your might. The window shatters.\n You jump out onto the soft snow below.";
			wonGame = true;
		}
		else
		{
			cout << "\nYou slam against the window with your shoulder but it won't budge. \nIt looks like you'll need a strong tool to break it.";
			minutes--;
		}
		
	}
	else if (player->location->getCarName()=="Dining Car")
	{
		cout << "There does not appear to be any escape options in the dining car.";
	}
	else if (player->location->getCarName()=="Sleeper Car")
	{
		cout << "There does not appear to be any escape options in the sleeper car.";
	}
	else if (player->location->getCarName()=="Caboose")
	{
		cout << "There does not appear to be any escape options in the caboose.";
	}
}


// player moves forward one node in the train
void game::moveForward()
{
	if (player->location->forward == nullptr)
	{
		cout << "\nCan't move forward anymore! You're at the conductor's car!";
	}
	else
	{
		minutes--;
		player->location = player->location->forward;
		cout<<"\nYou moved forwards into the " << player -> location -> getCarName() ;
	}
}

// player moves back one node in the train
void game::moveBack()
{
	if (player->location->back == nullptr)
	{
		cout << "\nCan't move back anymore! You're at the caboose!";
	}
	else
	{
		minutes--;
		player->location = player->location->back;
		cout<<"\nYou moved backwards into the " << player -> location -> getCarName();
	}
}

// player gets item depending on what car they are in
// if in conductor's car, player can use brakes once to extend timer
void game::getItem(space* currentCar, Player* p1)
{
	if (currentCar->gotItem() == false)
	{
		cout << "\nYou have already searched this area for useful items!";
	}
	else
	{
		minutes--;
		if (currentCar->getCarName()=="Conductor Car")
		{
			if (hasBrake == true)
			{
				cout <<"\nYou pull on the brake lever, slowing the speed of the train. This should buy some time.";
				minutes += 5;
				hasBrake = false;
			}
			cout << "\nYou find a silver key in one of the drawers.";
			p1 -> addItem(currentCar,"Key");
		}
		else if (currentCar->getCarName()=="Front Passenger Car")
		{
			cout << "\nThere doesn't appear to be any items of use here.";
		}
		else if (currentCar->getCarName()=="Rear Passenger Car")
		{
			cout << "\nYou hold the candle up and illuminate the room.";
			p1 -> addItem(currentCar,"Candle");
		}
		else if (currentCar->getCarName()=="Dining Car")
		{
			cout << "\nYou go over to the rack of cutlery and retrieve a very large cutting knife.";
			p1 -> addItem(currentCar,"Knife");
		}
		else if (currentCar->getCarName()=="Sleeper Car")
		{
			if (player->gotItem("Knife"))
			{
				cout << "\nYou hack into the rope with your knife to break the bindings. You manage to pull free the ladder.";
				p1 -> addItem(currentCar,"Ladder");
			}
			else
			{
				cout << "\nYou try to take the ladder from the bed but it is bound tightly against the bedpost with a thick rope. ";
			}
			

		}
		else if (currentCar->getCarName()=="Caboose")
		{
			if (player->gotItem("Key"))
			{
				cout << "\nYou try the small silver key on the safe. It Opens! Inside you find a large sledgehammer.";
				p1 -> addItem(currentCar, "Hammer");
		
			}
			else
				{
					minutes--;
					cout << "\nYou try to open the door to the safe but it won't budge. \nIt looks like you need to find the key somehow..";
				}
		}
	}
}

// describe room player is in
void game::describe(space* currentlocation)
{
	currentlocation-> describeSpace();
}


