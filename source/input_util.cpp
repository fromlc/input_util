//------------------------------------------------------------------------------
// input_util.cpp
// 
// console input tools
//------------------------------------------------------------------------------
#include "input_util.h"

//------------------------------------------------------------------------------
// globals
//------------------------------------------------------------------------------
static char g_input[IU_BUFFER_SIZE];
static string g_intPrompt = "Enter a positive integer or Q to quit: ";
static string g_errorPrompt = "That's not a positive integer. Please try again.\n";

//------------------------------------------------------------------------------
// get one positive integer from console input
//------------------------------------------------------------------------------
int getConsoleInt(int& intInput) {

	// loop to get positive integer input
	do {
		cout << g_intPrompt;
		cin.getline(g_input, IU_BUFFER_SIZE);
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
			//cerr << e.what() << '\n';
			if (ss.str().front() != SIGINT) {
				cerr << g_errorPrompt << '\n';
				continue;
			}
		}

		// valid numeric input was entered
		if (validateInput(intInput)) {
			return true;
		}
		// numeric value failed validation
		cerr << g_errorPrompt << '\n';

	} while (true);
}

//------------------------------------------------------------------------------
// positive integer input validation
//------------------------------------------------------------------------------
bool validateInput(int intInput) {

	return (intInput >= 0) ? true : false;
}


