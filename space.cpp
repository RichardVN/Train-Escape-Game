/*****************************************************************
** 	Program name:	space.cpp
**	Author: 		Richard Nguyen
** 	Date:			12/10/19
** 	Description:	Contains member function definitions for the class
					space.
******************************************************************/

#include "space.hpp"


// *********************
// Setter Functions    *
// *********************
void space::setCarName(string name)
{
	this -> carName = name;
}

void space::removeItem()
{
	this -> hasItem = false;
}

// *********************
// Getter functions    *
// *********************
string space::getCarName()
{
	return this -> carName;
}
bool space::gotItem()
{
	return this -> hasItem;
}
bool space::hasVisited()
{
	return this -> visited;
}



