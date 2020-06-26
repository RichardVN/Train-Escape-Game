/******************
 * File Name: 	space.hpp
 * Author: 		Richard Nguyen
 * Date: 		12/10/19
 * Description: header file for the parent class, space
*******************/
#ifndef SPACE_HPP
#define SPACE_HPP

#include <iostream>
using std::endl;
using std::cout;
using std::cin;

#include <string>
using std::string;

class space 
{

protected:
// member variables inherited by types of train cars

	// track if item has been taken
	bool hasItem = true;
	// track if space has been visited
	bool visited = false;
	// default car name
	string carName = "CAR NAME";

public:
	// pointers to adjacent space objects
	space *forward;
	space *back;
	
	// game is currently linear
	space *left = nullptr;
	space *right = nullptr;

	// virtual destructor
	virtual ~space(){};
	
	//Pure Virtual functions to be redefined by derived classes		
	virtual void describeSpace() = 0;

	// generalized functions to be inherited
	void setCarName(string);
	string getCarName();
	void removeItem();
	bool gotItem();
	bool hasVisited();
};
#endif