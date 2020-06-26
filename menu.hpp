/******************
 * Program: menu.hpp
 * Author: Richard Nguyen
 * Date: 10/27/19
 * Description: header file for menu function. Declaration of menu()
*******************/
#ifndef MENU_HPP
#define MENU_HPP
#include <string>
using std::string;

// @param: prompt string, lowest option, highest option
// @return: menu choice integer
int menu(string,int,int);

// @returns valid string input
string menuString(string);

#endif