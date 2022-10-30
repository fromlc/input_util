//------------------------------------------------------------------------------
// app.cpp
// 
// get one positive integer value from console input
//------------------------------------------------------------------------------
#include "input_util.h"		// input util function prototypes

//------------------------------------------------------------------------------
// globals
//------------------------------------------------------------------------------
const string g_intPrompt = "\nEnter a positive integer (Q quits): ";
const string g_errorPrompt = "That's not a positive integer.";

//------------------------------------------------------------------------------
// entry point
//------------------------------------------------------------------------------
int main() {

	// getConsoleInt() displays this string on bad input
	setErrorPrompt(g_errorPrompt);

	// prompt for int input with this string
	int myInt = getConsoleInt(g_intPrompt);

	// process positive int input

	cout << "\nYou entered: " << myInt << '\n';

	return 0;
}
