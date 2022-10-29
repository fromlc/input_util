//------------------------------------------------------------------------------
// input_util.cpp
// 
// console input tools
//------------------------------------------------------------------------------
#include "input_util.h"

//------------------------------------------------------------------------------
// globals
//------------------------------------------------------------------------------
string g_input;

//------------------------------------------------------------------------------
// local function prototypes
//------------------------------------------------------------------------------
bool _getConsoleInt(int& intInput);

//------------------------------------------------------------------------------
// handler for ctrl-c console input
// 
// sets keepRunning 0 on ctrl-c entered
//------------------------------------------------------------------------------
namespace {
	volatile sig_atomic_t keepRunning = 1;

	void handleCtrlC(int x) {
		if (x == SIGINT) {
			keepRunning = 0;
		}
	}
}

//------------------------------------------------------------------------------
// get one positive integer from console input
//------------------------------------------------------------------------------
int getConsoleInt() {
	// set up ctrl-c handler
	signal(SIGINT, handleCtrlC);

	int intInput;
	while (!_getConsoleInt(intInput)) {
		cerr << g_errorPrompt << '\n';
	}

	// return validated int
	return intInput;
}

//------------------------------------------------------------------------------
// loop to get positive integer input
//------------------------------------------------------------------------------
bool _getConsoleInt(int& intInput) {

	// ask user to enter an int
	cout << g_intPrompt;
	getline(cin, g_input);
	stringstream ss(g_input);

	// register exceptions we handle in catch blocks
	ss.exceptions(stringstream::failbit | stringstream::badbit);

	// check for user wants to quit
	if (!ss.str().compare("q") || !ss.str().compare("Q"))
		exit(IU_OK);

	try {
		ss >> intInput;
		return validateInt(intInput);
	}
	catch (stringstream::failure e) {
		// timing loop
		for (int i = 0; i < IU_WAIT; i++);

		if (!keepRunning) {
			// signal was set
			cerr << "^C\n";
			exit(IU_CONTROLC);
		}
		return false;
	}
}

//------------------------------------------------------------------------------
// positive integer input validation
//------------------------------------------------------------------------------
bool validateInt(int intInput) {

	return (intInput >= 0) ? true : false;
}
