 /*****************************************************************
** 	Program name:	passenger.cpp
**	Author: 		Richard Nguyen
** 	Date:			12/10/19
** 	Description:	Contains member function definitions for the class
					passenger.
******************************************************************/



#include "passenger.hpp"

// **********************************
// Default constructor				*
// **********************************

passenger::passenger()  : space()
{
	this -> carName = "Passenger Car";
}


// **********************************
// Virtual Functions to override    *
// **********************************

void passenger::describeSpace()
{
	cout <<"\nThe passenger cars are for the most part empty.\nYou woke up in the rear car, which contains large windows."
		<<"\nThe front passenger car is windowless but has an escape hatch at the top ...";
}



