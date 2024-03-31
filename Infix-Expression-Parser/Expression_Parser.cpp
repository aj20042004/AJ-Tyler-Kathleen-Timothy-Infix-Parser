
// Importing the modules
#include "Expression_Parser.h"
#include "Operator_Precedence.h"
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

		// Converting the infix to postfix
		string postfix_string = convert_to_postfix(infix_string);

		// Evaluating the postfix
		int result_num = evaluate_postfix(postfix_string);

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

	Operator_Precedence obj_operator_precedence;

	// precedence of power
	if (str_operator == "^") {
		return obj_operator_precedence = POWER;
	}

	// precedence of multiply, divide and mod
	if (str_operator == "*" || str_operator == "/" || str_operator == "%") {
		return obj_operator_precedence = MULTIPLY_DIVIDE_MOD;
	}

	// precedence of add and subtract
	if (str_operator == "+" || str_operator == "-") {
		return obj_operator_precedence = ADD_SUBTRACT;
	}

	// precedence of comparison
	if (str_operator == ">" || str_operator == ">=" || str_operator == "<" || str_operator == "<=") {
		return obj_operator_precedence = COMPARISON;
	}

	// precedence of equality
	if (str_operator == "==" || str_operator == "!=") {
		return obj_operator_precedence = EQUALITY;
	}

	// precedence of logical and
	if (str_operator == "&&") {
		return obj_operator_precedence = LOGICAL_AND;
	}

	// precedence of logical or
	if (str_operator == "||") {
		return obj_operator_precedence = LOGICAL_OR;
	}

	throw exception("Unsupported operator");
}

/** Converts an infix expression to postfix expression.
	@param infix_string: infix expression to convert
	@return: postfix expression converted from the infix expression
*/
string Expression_Parser::convert_to_postfix(const string& infix_string) {

	// Initializing the variables
	istringstream iss(infix_string);
	ostringstream output_string;
	stack<string> operand_stk;
	string token , new_token;

	// Creating a while loop to parse the infix string
	for (int i = 0; i < infix_string.size(); i++) {

		// Adding the character to the token
		token = infix_string[i];

		// Checking whether the token is empty
		if (token == " ") {
			continue;
		}

		// Checking if token's next character is either '=', '&', '|'
		if (token == ">" || token == "<" || token == "=" || token == "!" || token == "&" || token == "|") {

			if (i < infix_string.size() && (infix_string[i + 1] == '=' || infix_string[i + 1] == '&' || infix_string[i + 1] == '|')) {
				token += infix_string[i + 1];
			}

		}

		// Adding token to the output string if the token is digit
		if (isdigit(token.front())) {

			// Setting the index variable equal to i
			int index = i;

			string operand;

			// Creating a digit operand
			while (isdigit(infix_string[index])) {
				operand += infix_string[index];
				index++;
			}

			output_string << ' ' << operand;

			// Setting the correct index
			i = index - 1;
		}

		// Adding token to the stack if the token is "("
		else if (token == "(") { operand_stk.push(token); }

		// Adding elements from stack to output string if the token is ")"
		else if (token == ")") {

			while (operand_stk.top() != "(") {
				output_string << ' ' << operand_stk.top();
				operand_stk.pop();
			}

			operand_stk.pop();
		}

		else {

			// Adding the elements to the output string if it matches the conditions
			while (!operand_stk.empty() && operand_stk.top() != "(" && token != "=" && token != "|" && token != "&" && precedence(token) <= precedence(operand_stk.top())) {
				output_string << ' ' << operand_stk.top();
				operand_stk.pop();
			}

			if (token != "=" && token != "|" && token != "&") {
				operand_stk.push(token);
			}
		}
	}

	// Adding all the remaining elements to the output string
	while (!operand_stk.empty()) {
		output_string << ' ' << operand_stk.top();
		operand_stk.pop();
	}

	return output_string.str();
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


/** Evaluates the postfix expression and returns the result
	@param: postfix
	@return: operand_stk.top();
*/
int Expression_Parser::evaluate_postfix(const string& postfix) {

	// Initializing the variables
	istringstream iss(postfix);
	stack<int> operand_stk;
	string current_token;

	// Creating a while loop 
	while (iss >> current_token) {

		// Adding the token to the operand stack if the token is digit
		if (isdigit(current_token.front())) { operand_stk.push(stoi(current_token)); }

		else {

			// storing the right and left operand
			int right_operand = operand_stk.top();
			operand_stk.pop();
			int left_operand = operand_stk.top();
			operand_stk.pop();

			// Supported operators
			// Addition operator
			if (current_token == "+") { operand_stk.push(left_operand + right_operand); }

			// Subtraction operator
			if (current_token == "-") { operand_stk.push(left_operand - right_operand); }

			// Multiplication operator
			if (current_token == "*") { operand_stk.push(left_operand * right_operand); }

			// Division operator
			if (current_token == "/") {

				// Checking whether the denominator is 0 and throwing error message
				if (!right_operand) {
					throw exception("Divide by zero");
				}
				operand_stk.push(left_operand / right_operand);
			}

			// Mod operator
			if (current_token == "%") {
				if (!right_operand) { throw exception("Divide by zero"); }
				operand_stk.push(left_operand % right_operand);
			}

			// power operator
			if (current_token == "^") {
				if (!right_operand) { operand_stk.push(1); }
				operand_stk.push(power_function(left_operand, right_operand));
			}

			// greater than operator
			if (current_token == ">") {
				if (left_operand > right_operand) { operand_stk.push(1); }
				else { operand_stk.push(0); }
			}

			// greater than or equal operator
			if (current_token == ">=") {
				if (left_operand >= right_operand) { operand_stk.push(1); }
				else { operand_stk.push(0); }
			}

			// less than operator
			if (current_token == "<") {
				if (left_operand < right_operand) { operand_stk.push(1); }
				else { operand_stk.push(0); }
			}

			// less than or equal operator
			if (current_token == "<=") {
				if (left_operand <= right_operand) { operand_stk.push(1); }
				else { operand_stk.push(0); }
			}

			// Equal equal operator
			if (current_token == "==") {
				if (left_operand == right_operand) { operand_stk.push(1); }
				else { operand_stk.push(0); }
			}

			// Not equal operator
			if (current_token == "!=") {
				if (left_operand != right_operand) { operand_stk.push(1); }
				else { operand_stk.push(0); }
			}

			// Logical and operator
			if (current_token == "&&") {
				if (left_operand && right_operand) { operand_stk.push(1); }
				else { operand_stk.push(0); }
			}

			// Logical or operator
			if (current_token == "||") {
				if (left_operand || right_operand) { operand_stk.push(1); }
				else { operand_stk.push(0); }
			}

		}
	}

	// returning the top of the operand stack
	return operand_stk.top();

}


/** handles the error and throws the error message
	@param: error_message
*/
void Expression_Parser::handle_error(const string& error_message) {
	cerr << "Error: " << error_message << endl;
}



