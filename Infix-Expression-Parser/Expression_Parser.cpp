
// Importing the modules
#include "Expression_Parser.h"
#include "Convert_to_postfix.h"
#include "Evaluate_postfix.h"
#include <iostream>
#include <cctype>
#include <sstream>
#include <string>
#include <stack>

using namespace std;

// Constructor
Expression_Parser::Expression_Parser() {}

// Destructor
Expression_Parser::~Expression_Parser() {}

/** Returns the result of the infix expression after evaluating
	@param infix_string: expression to be converted into postfix
	@return: result number
	@throws exception: error message
*/
int Expression_Parser::parse_and_evaluate(const string& infix_string) {

	// Try and catch block
	try {

		Convert_to_postfix convert_postfix_obj;
		Evaluate_postfix evaluate_postfix_obj;

		// Converting the infix to postfix
		string postfix_string = convert_postfix_obj.infix_to_postfix(infix_string);

		// Evaluating the postfix
		int result_num = evaluate_postfix_obj.postfix_evaluator(postfix_string);

		// returning the result
		return result_num;
	}
	catch (const exception& err) {

		// catching the error message
		handle_error(err.what());
		return -9999999;
	}
}


/** Returns the precedence of an operator.
	@param str_operator: operator to return its precedence
	@return: precedence
	@throws exception: operator unsupported
*/
int Expression_Parser::precedence(const string& str_operator) {

	// precedence of power
	if (str_operator == "^") {
		return 7;
	}

	// precedence of multiply, divide and mod
	if (str_operator == "*" || str_operator == "/" || str_operator == "%") {
		return 6;
	}

	// precedence of add and subtract
	if (str_operator == "+" || str_operator == "-") {
		return 5;
	}

	// precedence of comparison
	if (str_operator == ">" || str_operator == ">=" || str_operator == "<" || str_operator == "<=") {
		return 4;
	}

	// precedence of equality
	if (str_operator == "==" || str_operator == "!=") {
		return 3;
	}

	// precedence of logical and
	if (str_operator == "&&") {
		return 2;
	}

	// precedence of logical or
	if (str_operator == "||") {
		return 1;
	}

	// Throw error if operator is not supported
	throw exception("Unsupported operator");
}


/** Calculates {left_operand} ^ {right_operand}.
	@param left_operand: base
	@param right_operand: exponent
	@return: result of {left_operand} ^ {right_operand}
*/
int Expression_Parser::power_function(int left_operand, int right_operand) {
	if (right_operand == 0) { return 1; }
	return left_operand * power_function(left_operand, right_operand - 1);
}


/** handles the error and throws the error message
	@param: error_message
*/
void Expression_Parser::handle_error(const string& error_message) {
	cerr << "Error: " << error_message << endl;
}



