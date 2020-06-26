 /*****************************************************************
** 	Program name:	caboose.cpp
**	Author: 		Richard Nguyen
** 	Date:			12/10/19
** 	Description:	Contains member function definitions for the class
					caboose.
******************************************************************/


#include "caboose.hpp"

// ***************************************************
// Default constructor						       *
// ***************************************************
 
caboose::caboose()  : space()
{
	this -> carName = "Caboose Car";
}


// **********************************
// Virtual Functions to override    *
// **********************************

void caboose::describeSpace()
{
	if (this -> hasItem)
	{
		cout <<"\nThe caboose is empty aside from a heavy silver safe to store personal"
			<< "belongs or equipment. \nIt is locked with a padlock";
	}
	else
	{
		cout <<"\nThe open safe contains various jewelry, but it's no time for theivery!"
			<< "\nPerhaps the hammer could prove useful";
	}
}


