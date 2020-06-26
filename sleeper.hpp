/******************
 * File Name: 	sleeper.hpp
 * Author: 		Richard Nguyen
 * Date: 		12/10/19
 * Description: header file for the class, sleeper
*******************/
#ifndef sleeper_HPP
#define sleeper_HPP

#include <iostream>
using std::endl;
using std::cout;
using std::cin;

#include <string>
using std::string;

#include "space.hpp"

// sleeper inherits from space class
class sleeper  : public space
{
	public: 
		// default constructor
		sleeper();
		// Virtual functions from space to override
		void describeSpace();
};
#endif