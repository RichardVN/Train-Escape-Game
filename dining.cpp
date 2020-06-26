 /*****************************************************************
** 	Program name:	dining.cpp
**	Author: 		Richard Nguyen
** 	Date:			12/10/19
** 	Description:	Contains member function definitions for the class
					dining.
******************************************************************/

#include "dining.hpp"

// ***************************************************
// Default constructor						       *
// ***************************************************

dining::dining()  : space()
{
	this -> carName = "Dining Car";
}


// **********************************
// Virtual Functions to override    *
// **********************************

void dining::describeSpace()
{
	if (this -> hasItem)
	{
		cout <<"\nThe dining car contains a few tables and chairs." 
			<<" \nThe eating area is adjoined by the kitchen, which is filled with cutlery";
	}
	else
	{
		cout <<"\nThere doesn't seem to be anything else to scavenge from this room";
	}
		
}


