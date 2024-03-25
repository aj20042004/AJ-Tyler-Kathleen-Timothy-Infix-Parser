#ifndef EXPRESSION_PARSER_H
#define EXPRESSION_PARSER_H

// Importing the modules
#include <iostream>
#include <stack>
#include "Operator_Precedence.h"
#include <string>

using namespace std;

// Creating the Expression Parser class
class Expression_Parser {

public:

	// Constructor
	Expression_Parser();
	
	// Destructor
	~Expression_Parser();

	// parsing the infix string and evaluating the result
	int parse_and_evaluate(const string&);

private:

	// precedence method to evaluate the expression by orders of operation
	int precedence(const string&);

	// power function to calculate exponents
	int power_function(int,int);

	// convert to postfix method for converting the infix into postfix expression
	string convert_to_postfix(const string&);

	// evaluate_postfix to get the result
	int evaluate_postfix(const string&);

	// handle_error method for any exception
	void handle_error(const string&);

};

#endif
