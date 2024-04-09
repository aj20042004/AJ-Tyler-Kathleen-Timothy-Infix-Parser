
// Questions for professor:
// ------------------------------------------------------------------------------------------------------------------------------------------------------------------ 
// 1) 
// 2) 


// Need to Complete:
// -------------------------------------------------------------------------------------------------------------------------------------------------------------------
// Creating Test cases, checking the correctness of the program, Test cases documentation in report, future requirements ( 4 ideas )  - Kathleen Dunn
// System design, data structures, 4 ideas for future improvements part in report. Convert_to_postfix and Evaluate_postfix files in-line comments - Timothy Huffman
		
// Bugs needs to be fixed:
// --------------------------------------------------------------------------------------------------------------------------------------------------------------------
// 1)

// Notes:
// In the input file, use "Hyphen" for minus sign

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

	// Using ifstream to open the input file
	ifstream input_file;

	input_file.open("Test_case_1.txt");

	// Checking whether input file can be opened or not
	if (!input_file) {
		cout << "Error! Sorry...Cannot read the file" << endl;
		return -1;
	}

	// Creating the instance for Expression_Parser
	Expression_Parser parser;

	// Initializing the variable
	string line_string;

	// Using getline to read the entire line
	while (getline(input_file, line_string)) {

		if (line_string == "") {
			break;
		}

		// parsing and evaluating the formatted infix string using the parser instance
		int result = parser.parse_and_evaluate(line_string);

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