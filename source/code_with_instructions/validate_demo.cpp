//------------------------------------------------------------------------------
// validate_demo.cpp
// 
// Demonstrates positive int input validation
//------------------------------------------------------------------------------
#include <iostream>
#include <sstream>			// stringstream

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
// limit the number of characters accepted from the user
static constexpr int BUFFER_SIZE = 32;

//------------------------------------------------------------------------------
// globals
//------------------------------------------------------------------------------
// static means the variable name is only known to this compilation unit
static char g_input[BUFFER_SIZE];
static string g_intPrompt = "Enter a positive integer or Q to quit: ";
static string g_errorPrompt = "That's not a positive integer. Please try again.\n";

//------------------------------------------------------------------------------
// local function prototypes
//------------------------------------------------------------------------------
int getConsoleInt(int& intInput);
bool validateInput(int intInput);

//------------------------------------------------------------------------------
// entry point
//------------------------------------------------------------------------------
int main() {

	int myInt;
	while (!getConsoleInt(myInt));

	// after the while loop you have positive int input to process
}

//------------------------------------------------------------------------------
// limit the number of characters accepted from the user
//------------------------------------------------------------------------------
int getConsoleInt(int& intInput) {

	do {
		// Ask user for input
		cout << g_intPrompt;

		// it's easiest to buffer input in a string
		cin.getline(g_input, BUFFER_SIZE);

		// then use a stringstream to convert to int
		// here we want an int from the user, but they might enter
		// some non-numeric garbage so let stringstream help
		stringstream ss(g_input);

		// now ss contains whatever the user entered

		// check for user wants to quit
		if (!ss.str().compare("q") || !ss.str().compare("Q"))
			return false;

		// stringstream will try to convert the input string
		// to int but this can fail and crash your program.

		// make it safe with exception handling

		// first, register the exceptions we want to handle
		ss.exceptions(stringstream::failbit | stringstream::badbit);

		// if we don't register them, they won't be thrown when 
		// the errors we care about happen

		// we're ready to convert the input to int

		// when stringstream can't convert its string to a numeric
		// value, failbit and badbit are actual error bits that get set 
		
		// the try and catch blocks let us gracefully handle input errors
		try {
			ss >> intInput;
		}
		catch (stringstream::failure e) {
			cerr << g_errorPrompt << '\n';
			continue;
		}
		// at this point intInput has a number
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
