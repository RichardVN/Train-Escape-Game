/******************
 * Program: menu.cpp
 * Author: Richard Nguyen
 * Date: 10/27/19
 * Description: Definition for function menu().
*******************/
#include<iostream> 
#include <string>

using std::string;
using std::endl;
using std::cout;
using std::cin;

string menuString(string displayPrompt)
{
	// string var holds user input
	string userInputStr = " ";
	//int var holds user input, after conversion from string

	bool validInput = true;

	do
	{
		// display prompt from parameters
		cout << "\n" << displayPrompt << endl;
		// cout << "Enter a value between " << min << " and " << max << ": ";
		
		//get user value as a string
		getline(cin, userInputStr);
		//cin >> userInputStr;

	}
	while (validInput != true);

	return userInputStr;
}


int menu(string displayPrompt, int min, int max)
{
	// string var holds user input
	string userInputStr = " ";
	//int var holds user input, after conversion from string
	int userInputInt = -55;

	bool validInput = true;

	do
	{
		// display prompt from parameters
		cout << "\n" << displayPrompt << endl;
		// cout << "Enter a value between " << min << " and " << max << ": ";
		
		//get user value as a string
		cin >> userInputStr;
		
		// check if string has only digits
		// http://www.cplusplus.com/reference/string/string/find_first_not_of/
			// returns position of first character that does not match
			//returns string::npos if no matching char found

		//digit_string true if only positive digits found in string, NO FLOATS
		//https://stackoverflow.com/questions/8888748/how-to-check-if-given-c-string-or-char-contains-only-digits
		bool digit_string = (userInputStr.find_first_not_of( "0123456789" ) == string::npos);

		if (digit_string == false)
		{
			cout << "Error!: Your input is invalid! Try again." << endl;
			validInput = false;
		}
		else if (digit_string == true)
		{
			userInputInt = stoi(userInputStr);
			
			// check if integer is outside of bounds
			if(userInputInt < min || userInputInt > max)
			{
				cout << "Error!: Your input value is outside the valid bounds!" << endl;
				validInput = false;
			}

			// passed both only digit_string test, and bounds test
			else
			{
				validInput = true;
			}
			
		}
		else
		{
			cout << "something else happened!";
		}


	}
	while (validInput != true);

	return userInputInt;
}