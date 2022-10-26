//------------------------------------------------------------------------------
// input_util.h
// 
// console input tools
//------------------------------------------------------------------------------
#ifndef INPUT_UTIL_H
#define INPUT_UTIL_H

#include <csignal>		// for handling ctrl-c
#include <iostream>
#include <sstream>		// stringstream for string to int conversion

//------------------------------------------------------------------------------
// using symbols
//------------------------------------------------------------------------------
using std::cerr;			// console error output
using std::cin;				// flushes cout buffer then gets console input
using std::cout;			// console output
using std::endl;			// new line and flush cout buffer
using std::signal;			// handle control-c input
using std::string;
using std::stringstream;	// for string to int conversion

//------------------------------------------------------------------------------
// constants
//------------------------------------------------------------------------------
constexpr int IU_BUFFER_SIZE = 32;

//------------------------------------------------------------------------------
// function prototypes
//------------------------------------------------------------------------------
int getConsoleInt();
bool validateInput(int intInput);

#endif // !INPUT_UTIL_H
