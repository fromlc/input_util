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
// local function prototypes
//------------------------------------------------------------------------------
bool getConsoleIntLoop(int& intInput);
bool validateInput(int intInput);

//------------------------------------------------------------------------------
// handler for ctrl-c console input
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
	while (!getConsoleIntLoop(intInput));

	return intInput;
}

//------------------------------------------------------------------------------
// loop to get positive integer input
//------------------------------------------------------------------------------
bool getConsoleIntLoop(int& intInput) {

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
			if (keepRunning) {
				cerr << g_errorPrompt << '\n';
				continue;
			}
			else {
				cerr << "^C\n";
				exit(IU_CONTROL_C);
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


