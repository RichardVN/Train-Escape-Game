/******************
 * File Name: 	item.hpp
 * Author: 		Richard Nguyen
 * Date: 		12/10/19
 * Description: header file for the parent class, item
*******************/
#ifndef ITEM_HPP
#define ITEM_HPP

#include <iostream>
using std::endl;
using std::cout;
using std::cin;

#include <string>
using std::string;

class item 
{
	protected:
		string name = "ITEM NAME";
		string description = "ITEM DESCRIPTION";
		int quantity= 0;

	public:
		// default constructor
		 item();
		// virtual destructor
		~item(){}

		//Setter Functions
			void setQuantity(int);
			void setName(string);
			void setDescription(string);
		//Getter Functions
			string getName();
			string getDescription();
			int getQuantity();
};

#endif