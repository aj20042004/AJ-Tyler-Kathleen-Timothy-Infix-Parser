#ifndef CONVERT_TO_POSTFIX_H
#define CONVERT_TO_POSTFIX_H
#include <string>
#include <iostream>

using namespace std;


class Convert_to_postfix {

public:
	Convert_to_postfix();

	~Convert_to_postfix();

	// convert to postfix method for converting the infix into postfix expression
	string infix_to_postfix(const string&);

};

#endif