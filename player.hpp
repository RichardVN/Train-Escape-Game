/******************
 * File Name: 	player.hpp
 * Author: 		Richard Nguyen
 * Date: 		12/10/19
 * Description: header file for the class, player
*******************/
#ifndef PLAYER_HPP
#define PLAYER_HPP

#include <iostream>
using std::endl;
using std::cout;
using std::cin;

#include <string>
using std::string;

#include "item.hpp"
#include "space.hpp"

class Player 
{
private:
	// inventory to carry items with capacity limit
	item* inventory[6];
	int inventorySize = 6;

	// create discoverable items
	item key;
	item Ladder;
	item axe;
	item candle;
	item hammer;
	item knife;

	// bool var for items
	bool hasKey = false;
	bool hasLadder = false;
	bool hasAxe = false;
	bool hasCandle = false;
	bool hasHammer = false;
	bool hasKnife = false;

public:
	// default constructor
	Player();
	// destructor
	~Player();
	// pointer to space
	space *location = nullptr;

	// print player's current items
	void printInventory();

	// add item to inventory
	void addItem(space *, string);

	// check if player has item
	bool gotItem(string);

};
#endif