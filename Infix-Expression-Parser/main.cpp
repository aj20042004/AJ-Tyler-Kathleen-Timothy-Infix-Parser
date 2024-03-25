
// Questions for professor:
// ------------------------------------------------------------------------------------------------------------- 
// 1) Do we need to check for divide by zero error while using % ?
// 2) Questions regarding the functionality of Comparison, Equality comparison, Logical And, Logical Or

// Need to Complete:
// -------------------------------------------------------------------------------------------------------------
// Operand class and in-line comments - Tyler Blackmore
// Creating Test cases, checking the correctness of the program, in-line comments for main file ? - Kathleen Dunn
// Operator class and in-line comments - Timothy Huffman

// Bugs needs to be fixed:
// -------------------------------------------------------------------------------------------------------------
// ?

// Importing the modules
#include <string>
#include <iostream>
#include <iomanip>
#include "Expression_Parser.h"
#include <fstream>
#include <codecvt>
#include <sstream>

using namespace std;

// Main class
int main() {

	// Using wifstream to open the input file
	wifstream input_file;
	input_file.imbue(locale(locale::empty(), new codecvt_utf8<wchar_t>));
	input_file.open("Test.txt");

	// Checking whether input file can be opened or not
	if (!input_file) {
		cout << "Error! Sorry...Cannot read the file" << endl;
		return -1;
	}

	// Creating the instance for Expression_Parser
	Expression_Parser parser;

	// Initializing the variable
	wstring line_string;

	// Using getline to read the entire line
	while (getline(input_file, line_string)) {

		// Creating the infix string variable
		string infix_string;
		infix_string += ' ';

		// Iterating through the string to format it correctly with spaces
		for (int i = 0; i < line_string.size(); i++) {

			// Creating the token
			char token = line_string[i];

			// Skipping if the token is empty
			if (token == ' ') {
				continue;
			}

			// Changing the \x12 to minus sign
			if (token == '\x12') {
				token = '-';
			}

			// Adding the operators to the infix_string with appropriate spaces
			if (token == '+' || token == '-' || token == '*' || token == '/' || token == '%' || token == '^' ||
				token == '(' || token == ')') {
			
				infix_string += token;
				infix_string += ' ';
			}

			else if (isdigit(token)) {

				infix_string += token;
                
				// creating the next_token variable
				char next_token = line_string[i + 1];

				// Changing the \x12 to minus sign
				if (next_token == '\x12') {
					next_token = '-';
				}

				// Adding a space to the infix_string if next_token is minus sign
				if (i + 1 < line_string.size() && next_token == '-') {
					infix_string += ' ';
					continue;
				}

				// Adding a space to the infix string if the next token is not a digit
				else if (i + 1 < line_string.size() && !isdigit(line_string[i + 1])) {
					infix_string += ' ';
				}
			}

			else {

				// Adding the token to the infix string if the token is other operators
				infix_string += token;

				if (i + 1 < line_string.size() && line_string[i + 1] == ' ') {
					infix_string += ' ';
				}

				// Adding a space to the infix string if the next token is a digit
				if (i + 1 < line_string.size() && isdigit(line_string[i + 1])) {
					infix_string += ' ';
				}
			}

		}

		infix_string += ' ';

		// parsing and evaluating the formatted infix string using the parser instance
		int result = parser.parse_and_evaluate(infix_string);

		// Checking for Error
		if (result != -9999999) {
			cout << "The Result is: " << result << endl;
		}

	}

	// closing the input file
	input_file.close();

	// returning
	return 0;
}