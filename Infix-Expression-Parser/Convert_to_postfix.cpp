#include "Convert_to_postfix.h"
#include "Expression_Parser.h"
#include <iostream>
#include <string>
#include <cctype>
#include <sstream>
#include <stack>

using namespace std;

Convert_to_postfix::Convert_to_postfix() {}

Convert_to_postfix::~Convert_to_postfix() {}


/** Converts an infix expression to postfix expression.
	@param infix_string: infix expression to convert
	@return: postfix expression converted from the infix expression
*/
string Convert_to_postfix::infix_to_postfix(const string& infix_string) {

	Expression_Parser exp_parser_obj;

	// Initializing the variables
	istringstream iss(infix_string);
	ostringstream output_string;
	stack<string> operand_stk;
	string token;
	
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
			while (!operand_stk.empty() && operand_stk.top() != "(" && token != "=" && token != "|" && token != "&" && 
				exp_parser_obj.precedence(token) <= exp_parser_obj.precedence(operand_stk.top())) {
				
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
