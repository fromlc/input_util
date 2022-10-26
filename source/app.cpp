//------------------------------------------------------------------------------
// app.cpp
// 
// get one positive integer value from console input
//------------------------------------------------------------------------------
#include "input_util.h"		// input util function prototypes

//------------------------------------------------------------------------------
// entry point
//------------------------------------------------------------------------------
int main() {
	// set up ctrl-c handler
	signal(SIGINT, handleCtrlC);

	int myInt;
	while (!getConsoleInt(myInt));

	// after the while loop you have positive int input to process

	return 0;
}

