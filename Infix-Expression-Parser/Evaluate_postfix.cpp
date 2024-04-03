#include "Evaluate_postfix.h"
#include "Expression_Parser.h"
#include <iostream>
#include <string>
#include <cctype>
#include <sstream>
#include <stack>

using namespace std; 

Evaluate_postfix::Evaluate_postfix() {}

Evaluate_postfix::~Evaluate_postfix() {}


/** Evaluates the postfix expression and returns the result
	@param: postfix
	@return: operand_stk.top();
*/
int Evaluate_postfix::postfix_evaluator(const string& postfix) {

	Expression_Parser exp_parser_obj;

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
				operand_stk.push(exp_parser_obj.power_function(left_operand, right_operand));
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

