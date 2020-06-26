/******************
 * File Name: 	caboose.hpp
 * Author: 		Richard Nguyen
 * Date: 		12/10/19
 * Description: header file for the class, caboose
*******************/
#ifndef caboose_HPP
#define caboose_HPP

#include <iostream>
using std::endl;
using std::cout;
using std::cin;

#include <string>
using std::string;

#include "space.hpp"

class caboose  : public space
{
	public:
		// default constructor
		caboose();

		// Virtual functions from space to override
		void describeSpace();
};
#endif