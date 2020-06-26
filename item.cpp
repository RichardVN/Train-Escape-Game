/*****************************************************************
** 	Program name:	item.cpp
**	Author: 		Richard Nguyen
** 	Date:			12/10/19
** 	Description:	Contains member function definitions for the class
					item.
******************************************************************/

#include "item.hpp"

// **********************
// Default constructor  *
// **********************

item::item() 
{
	
}

// **********************
// Setter Functions     *
// **********************
void item::setQuantity(int quantity)
{
	this -> quantity = quantity;
}
void item::setName(string name)
{
	this -> name = name;
}
void item::setDescription(string description)
{
	this -> description = description;
}

// **********************
// Getter functions 	*
// **********************
string item::getName()
{
	return this -> name;
}

string item::getDescription()
{
	return this -> description;
}

int item::getQuantity()
{
	return this -> quantity;
}



