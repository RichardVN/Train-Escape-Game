/******************
 * File Name: 	passenger.hpp
 * Author: 		Richard Nguyen
 * Date: 		12/10/19
 * Description: header file for the class, passenger
*******************/
#ifndef passenger_HPP
#define passenger_HPP

#include <iostream>
using std::endl;
using std::cout;
using std::cin;

#include <string>
using std::string;

#include "space.hpp"

class passenger  : public space
{
	public: 
		// default constructor
		passenger();

		// Virtual functions from space to override
		void describeSpace();
};

#endif