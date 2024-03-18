#include <string>
#include <iostream>
#include <iomanip>
#include "Expression_Parser.h"
#include <fstream>
#include <sstream>

using namespace std;

int main() {

	ifstream input_file("Test.txt");

	if (!input_file) {
		cout << "Error! Sorry...Cannot read the file" << endl;
		return 1;
	}

	Expression_Parser parser;

	string line_string;

	while (getline(input_file, line_string)) {

		string infix_string;
		infix_string += ' ';

		for (int i = 0; i < line_string.size(); i++) {

			char token = line_string[i];

			if (token == '+' || token == '-' || token == '*' || token == '/' || token == '%' || token == '^' ||
				token == '(' || token == ')') {
				//infix_string += ' ';
				infix_string += token;
				infix_string += ' ';
			}

			else if (isdigit(token)) {
				infix_string += token;
				infix_string += ' ';
			}

			else {
				infix_string += token;
				if (i + 1 < line_string.size() && isdigit(line_string[i + 1])) {
					infix_string += ' ';
				}
			}

		}

		infix_string += ' ';

		int result = parser.parse_and_evaluate(infix_string);
		cout << "The Result is: " << result << endl;
	}

	input_file.close();

	return 0;
}