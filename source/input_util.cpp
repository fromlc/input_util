//------------------------------------------------------------------------------
// input_util.cpp
// 
// console input tools
//------------------------------------------------------------------------------
#include <iostream>
#include <sstream>			// stringstream for string to int conversion

#include "input_util.h"		// input util function prototypes

//------------------------------------------------------------------------------
// using symbols
//------------------------------------------------------------------------------
using std::cerr;			// console error output
using std::cin;				// flushes cout buffer then gets console input
using std::cout;			// console output
using std::endl;			// new line and flush cout buffer
using std::string;
using std::stringstream;	// for string to int conversion

//------------------------------------------------------------------------------
// constants
//------------------------------------------------------------------------------
static constexpr int BUFFER_SIZE = 32;

//------------------------------------------------------------------------------
// globals
//------------------------------------------------------------------------------
static char g_input[BUFFER_SIZE];
static string g_intPrompt = "Enter a positive integer or Q to quit: ";
static string g_errorPrompt = "That's not a positive integer. Please try again.\n";

//------------------------------------------------------------------------------
// limit the number of characters accepted from the user
//------------------------------------------------------------------------------
int getConsoleInt(int& intInput) {

	do {
		cout << g_intPrompt;
		cin.getline(g_input, BUFFER_SIZE);
		stringstream ss(g_input);

		// check for user wants to quit
		if (!ss.str().compare("q") || !ss.str().compare("Q"))
			return false;

		// register the exceptions we want to handle
		ss.exceptions(stringstream::failbit | stringstream::badbit);

		try {
			ss >> intInput;
		}
		catch (stringstream::failure e) {
			cerr << g_errorPrompt << '\n';
			continue;
		}

		if (validateInput(intInput)) {
			return true;
		}
		cerr << g_errorPrompt << '\n';

	} while (true);
}

//------------------------------------------------------------------------------
// positive int input validation
//------------------------------------------------------------------------------
bool validateInput(int intInput) {
	
	return (intInput >= 0) ? true : false;
}
