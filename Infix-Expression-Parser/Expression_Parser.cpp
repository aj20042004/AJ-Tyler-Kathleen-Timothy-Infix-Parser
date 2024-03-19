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

// Parse and evaluate method
int Expression_Parser::parse_and_evaluate(const string& infix_string) {
	try {
		string postfix_string = convert_to_postfix(infix_string);
		int result_num = evaluate_postfix(postfix_string);
		return result_num;
	}
	catch (const exception& err) {
		handle_error(err.what());
		return -9999999;
	}
}

/** Returns the precedence of an operator.
	@param oper: operator to return its precedence
	@return: precedence
	@throws exception: operator unsupported
*/
int Expression_Parser::precedence(const string& str_operator) {

	Operator_Precedence obj_operator_precedence;

	if (str_operator == "^") {
		return obj_operator_precedence = POWER;
	}

	if (str_operator == "*" || str_operator == "/" || str_operator == "%") {
		return obj_operator_precedence = MULTIPLY_DIVIDE_MOD;
	}

	if (str_operator == "+" || str_operator == "-") {
		return obj_operator_precedence = ADD_SUBTRACT;
	}

	if (str_operator == ">" || str_operator == ">=" || str_operator == "<" || str_operator == "<=") {
		return obj_operator_precedence = COMPARISON;
	}

	if (str_operator == "==" || str_operator == "!=") {
		return obj_operator_precedence = EQUALITY;
	}

	if (str_operator == "&&") {
		return obj_operator_precedence = LOGICAL_AND;
	}

	if (str_operator == "||") {
		return obj_operator_precedence = LOGICAL_OR;
	}

	throw exception("Unsupported operator");
}

/** Converts an infix expression to postfix expression.
	@param infix_exp: infix expression to convert
	@return: postfix expression converted from the infix expression
*/
string Expression_Parser::convert_to_postfix(const string& infix_string) {

	istringstream iss(infix_string);
	ostringstream output_string;
	stack<string> operand_stk;

	string token;

	while (iss >> token) {

		if (isdigit(token.front())) { output_string << ' ' << token; }

		else if (token == "(") { operand_stk.push(token); }

		else if (token == ")") {

			while (operand_stk.top() != "(") {
				output_string << ' ' << operand_stk.top();
				operand_stk.pop();
			}

			operand_stk.pop();
		}

		else {

			while (!operand_stk.empty() && operand_stk.top() != "(" && precedence(token) <= precedence(operand_stk.top())) {
				output_string << ' ' << operand_stk.top();
				operand_stk.pop();
			}

			operand_stk.push(token);
		}
	}

	while (!operand_stk.empty()) {
		output_string << ' ' << operand_stk.top();
		operand_stk.pop();
	}

	return output_string.str();
}

int Expression_Parser::power_function(int left_operand, int right_operand) {
	if (right_operand == 0) { return 1; }
	return left_operand * power_function(left_operand, right_operand - 1);
}


// evaluate postfix method
int Expression_Parser::evaluate_postfix(const string& postfix) {

	istringstream iss(postfix);
	stack<int> operand_stk;
	string current_token;  // Current token

	while (iss >> current_token) {

		if (isdigit(current_token.front())) { operand_stk.push(stoi(current_token)); }

		else {

			int right_operand = operand_stk.top();
			operand_stk.pop();
			int left_operand = operand_stk.top();
			operand_stk.pop();

			// Supported operators
			if (current_token == "+") { operand_stk.push(left_operand + right_operand); }
			
			if (current_token == "-") { operand_stk.push(left_operand - right_operand); }
			
			if (current_token == "*") { operand_stk.push(left_operand * right_operand); }
			
			if (current_token == "/") {
				if (!right_operand) { 
					throw exception("Divide by zero");
				}
				operand_stk.push(left_operand / right_operand);
			}

			if (current_token == "%") {
				if (!right_operand) { throw exception("Divide by zero"); }
				operand_stk.push(left_operand % right_operand);
			}

			if (current_token == "^") {
				if (!right_operand) { operand_stk.push(1); }
				operand_stk.push(power_function(left_operand, right_operand));
			}

			if (current_token == ">") {
				if (left_operand > right_operand) { operand_stk.push(1); }
				else { operand_stk.push(0); }
			}

			if (current_token == ">=") {
				if (left_operand >= right_operand) { operand_stk.push(1); }
				else { operand_stk.push(0); }
			}

			if (current_token == "<") {
				if (left_operand < right_operand) { operand_stk.push(1); }
				else { operand_stk.push(0); }
			}

			if (current_token == "<=") {
				if (left_operand <= right_operand) { operand_stk.push(1); }
				else { operand_stk.push(0); }
			} 

			if (current_token == "==") {
				if (left_operand == right_operand) { operand_stk.push(1); }
				else { operand_stk.push(0); }
			}

			if (current_token == "!=") {
				if (left_operand != right_operand) { operand_stk.push(1); }
				else { operand_stk.push(0); }
			}

			if (current_token == "&&") {
				if (left_operand && right_operand) { operand_stk.push(1); }
				else { operand_stk.push(0); }
			}

			if (current_token == "||") {
				if (left_operand || right_operand) { operand_stk.push(1); }
				else { operand_stk.push(0); }
			}

		}
	}

	return operand_stk.top();

}


// handle error method
void Expression_Parser::handle_error(const string& error_message) {
	cerr << "Error: " << error_message << endl;
}



