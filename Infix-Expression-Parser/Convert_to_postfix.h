#ifndef CONVERT_TO_POSTFIX_H
#define CONVERT_TO_POSTFIX_H

// Importing the modules
#include <string>
#include <iostream>

using namespace std;


// Creating Convert to Postfix class
class Convert_to_postfix {

public:

	// Constructor
	Convert_to_postfix();

	// Destructor
	~Convert_to_postfix();

	// Convert to postfix method for converting the infix into postfix expression
	string infix_to_postfix(const string&);

};

#endif