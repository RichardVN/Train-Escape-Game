/******************
 * File Name: 	conductor.hpp
 * Author: 		Richard Nguyen
 * Date: 		12/10/19
 * Description: header file for the class, conductor
*******************/
#ifndef conductor_HPP
#define conductor_HPP

#include <iostream>
using std::endl;
using std::cout;
using std::cin;

#include <string>
using std::string;

#include "space.hpp"

class conductor  : public space
{
	public: //public member functions
		// default constructor
		conductor();

		// Virtual functions from space to override
		void describeSpace();
};
#endif