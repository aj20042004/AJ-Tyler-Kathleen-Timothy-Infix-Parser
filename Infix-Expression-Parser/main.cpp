#include <string>
#include <iostream>
#include <iomanip>
#include "Expression_Parser.h"
#include <fstream>
#include <codecvt>
#include <sstream>

using namespace std;

int main() {

	std::wifstream input_file;
	input_file.imbue(std::locale(std::locale::empty(), new std::codecvt_utf8<wchar_t>));
	input_file.open("Test.txt");

	if (!input_file) {
		cout << "Error! Sorry...Cannot read the file" << endl;
		return 1;
	}

	Expression_Parser parser;

	std::wstring line_string;

	while (getline(input_file, line_string)) {

		string infix_string;
		infix_string += ' ';

		for (int i = 0; i < line_string.size(); i++) {

			char token = line_string[i];

			if (token == ' ') {
				continue;
			}

			if (token == '\x12') {
				token = '-';
			}


			if (token == '+' || token == '-' || token == '*' || token == '/' || token == '%' || token == '^' ||
				token == '(' || token == ')') {
				//infix_string += ' ';
				infix_string += token;
				infix_string += ' ';
			}

			else if (isdigit(token)) {

				infix_string += token;

				char next_token = line_string[i + 1];
				if (next_token == '\x12') {
					next_token = '-';
				}

				if (i + 1 < line_string.size() && next_token == '-') {
					infix_string += ' ';
					continue;
				}

				else if (i + 1 < line_string.size() && !isdigit(line_string[i + 1])) {
					infix_string += ' ';
				}
			}

			else {
				infix_string += token;

				if (i + 1 < line_string.size() && line_string[i + 1] == ' ') {
					infix_string += ' ';
				}

				if (i + 1 < line_string.size() && isdigit(line_string[i + 1])) {
					infix_string += ' ';
				}
			}

		}

		infix_string += ' ';

		int result = parser.parse_and_evaluate(infix_string);

		if (result != -9999999) {
			cout << "The Result is: " << result << endl;
		}

	}

	input_file.close();

	return 0;
}