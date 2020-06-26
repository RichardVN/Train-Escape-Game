/******************
 * File Name: 	dining.hpp
 * Author: 		Richard Nguyen
 * Date: 		12/10/19
 * Description: header file for the class, dining
*******************/
#ifndef dining_HPP
#define dining_HPP

#include <iostream>
using std::endl;
using std::cout;
using std::cin;

#include <string>
using std::string;

#include "space.hpp"

class dining  : public space
{
	public: 
		// default constructor
		dining();
		// Virtual functions from space class to override
		void describeSpace();
};
#endif