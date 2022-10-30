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
using std::getline;
using std::signal;			// handle control-c input
using std::string;
using std::stringstream;	// for string to int conversion

//------------------------------------------------------------------------------
// constants
//------------------------------------------------------------------------------
constexpr int IU_CONTROLC = 1;		// control-c exit code
constexpr int IU_OK = 0;			// user quits exit code
constexpr int IU_WAIT = 1000000;	// timing loop waits for ctrl-c signal

//------------------------------------------------------------------------------
// function prototypes
//------------------------------------------------------------------------------
// prompt is an optional parameter, g_intPrompt used by default
int getConsoleInt(const string& promptStr = "");
bool validateInt(int intInput);
void setErrorPrompt(const string& errorStr);

#endif // !INPUT_UTIL_H
