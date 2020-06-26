 /*****************************************************************
** 	Program name:	conductor.cpp
**	Author: 		Richard Nguyen
** 	Date:			12/10/19
** 	Description:	Contains member function definitions for the class
					conductor.
******************************************************************/

#include "conductor.hpp"

// ***************************************************
// Default constructor						       *
// ***************************************************

conductor::conductor()  : space()
{
	this -> carName = "Conductor Car";
}

// **********************************
// Virtual Functions to override    *
// **********************************

void conductor::describeSpace()
{
	if (this -> hasItem)
	{
		cout <<"\nThere is no one in the conductor's car. \nAside from the brake lever, the controls are too complicated to operate."
		<< "\nThere is a desk with a couple of drawers that could hold something useful.";
	}
	else
	{
		cout << "\nThe rest of the drawers are filled with paperwork."
		<< "\nThe key must be used to open something in one of the other cars.";
	}
}


