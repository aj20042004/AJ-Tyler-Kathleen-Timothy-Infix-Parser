#ifndef EXPRESSION_PARSER_H
#define EXPRESSION_PARSER_H

// Importing the modules
#include <iostream>
#include <stack>
#include <string>

using namespace std;

// Creating the Expression Parser class
class Expression_Parser {

public:

	// Constructor
	Expression_Parser();
	
	// Destructor
	~Expression_Parser();

	// power function to calculate exponents
	int power_function(int, int);

	// parsing the infix string and evaluating the result
	int parse_and_evaluate(const string&);

	// precedence method to evaluate the expression by orders of operation
	int precedence(const string&);

private:

	// handle_error method for any exception
	void handle_error(const string&);

};

#endif
