/*****************************************************************
** 	Program name:	player.cpp
**	Author: 		Richard Nguyen
** 	Date:			12/10/19
** 	Description:	Contains member function definitions for the class
					player. Deals with item/inventory management
******************************************************************/

#include "player.hpp"

//***************************
// Default constructor		*
//***************************

Player::Player() 
{
	for (int i = 0; i < inventorySize; ++i)
	{
		inventory[i] = nullptr;
	}
	// set names of items
	key.setName("Key");
	Ladder.setName("Ladder");
	axe.setName("Axe");
	candle.setName("Candle");
	hammer.setName("Hammer");
	knife.setName("Knife");
}

//****************************
// Destructor				 *
//****************************

Player::~Player() 
{
	
}


//****************************
// Player Member Functions   *   
//****************************
// print player item inventory
void Player::printInventory()
{
	cout << "\nYou are currently holding: \n";
	int itemCount=0;
	for (int i = 0; i < inventorySize; ++i)
	{
		if (inventory[i]!=nullptr)
		{
			itemCount++;
			cout <<"Item "<< itemCount <<": " << inventory[i] -> getName() << endl;
		}
	}
}

 // add items to inventory
void Player::addItem(space *currentCar, string itemName)
{
	cout << "\n* " << itemName << " added to Inventory! *";
	currentCar -> removeItem();

	if (itemName == "Key")
	{
		inventory[0] = &key;
		hasKey = true;
	}
	else if (itemName == "Ladder")
	{
		inventory[1] = &Ladder;
		hasLadder = true;
	}
	else if (itemName == "Axe")
	{
		inventory[2] = &axe;
		hasAxe = true;
	}
	else if (itemName == "Candle")
	{
		inventory[3] = &candle;
		hasCandle = true;
	}
	else if (itemName == "Hammer")
	{
		inventory[4] = &hammer;
		hasHammer = true;
	}
	else if (itemName == "Knife")
	{
		inventory[5] = &knife;
		hasKnife = true;
	}
}

// used to check if player has item in inventory
bool Player::gotItem(string itemName)
{
	if (itemName == "Key")
		return hasKey;
	else if (itemName == "Ladder")
		return hasLadder;
	else if (itemName == "Axe")
		return hasAxe;
	else if (itemName == "Candle")
		return hasCandle;
	else if (itemName == "Hammer")
		return hasHammer;
	else if (itemName == "Knife")
		return hasKnife;
	else return false;
}




