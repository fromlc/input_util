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

	int myInt = getConsoleInt();

	// process positive int input

	cout << "\nYou entered: " << myInt << '\n';

	return 0;
}

