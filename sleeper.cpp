 /*****************************************************************
** 	Program name:	sleeper.cpp
**	Author: 		Richard Nguyen
** 	Date:			12/10/19
** 	Description:	Contains member function definitions for the class
					sleeper.
******************************************************************/

#include "sleeper.hpp"

// *********************************
// Default constructor			   *
// *********************************

sleeper::sleeper()  : space()
{
	this -> carName = "Sleeper Car";
}


// **********************************
// Virtual Functions to override    *
// **********************************

void sleeper::describeSpace()
{
	if (this -> hasItem)
	{
		cout <<"\nThe sleeper car is filled with mattresses."
		<< "\nThere is a bunk bed but the ladder is bound tightly to the bedpost with rope.";
	}
	else
	{
		cout << "\nAfter taking the ladder, there does not appear to be any useful items"
		<< "\nor means of escape in the sleeper car.";
	}	

}

