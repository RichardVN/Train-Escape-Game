/******************
 * File Name: 	game.hpp
 * Author: 		Richard Nguyen
 * Date: 		12/10/19
 * Description: header file for the class, game
*******************/
#ifndef GAME_HPP
#define GAME_HPP

#include <iostream>
using std::endl;
using std::cout;
using std::cin;

#include <string>
using std::string;

#include "player.hpp"
#include "item.hpp"

#include "passenger.hpp"
#include "conductor.hpp"
#include "dining.hpp"
#include "sleeper.hpp"
#include "caboose.hpp"

#include "menu.hpp"


class game 
{
	private:
		// Pointer to player object
		Player *player;
		// Starting game time
		int minutes = 13;

		//create game spaces for each train car
		space* train[6];
		int trainSize = 6;

		// create train cars
		conductor conductorCar;
		passenger passengerCar1;
		passenger passengerCar2;
		dining diningCar;
		sleeper sleeperCar;
		caboose cabooseCar;

		// set to true on any escape condition
		bool wonGame = false;
		// time extension mechanic
		bool hasBrake = true;

	public:
		// default constructor
			game();
		// destructor
			~game();

		// Gameplay Flow
			void turnMenu();
			
			// Game win conditions 
			bool checkGameOver();
			bool checkGameWin();
			void winGame();

			// Game Turn menu functions
			void printCars();
			void findPlayer();
			void moveForward();
			void moveBack();
			void escape();
			void getItem(space*, Player*);
			int getMinutes();
			void describe(space*);
};
#endif