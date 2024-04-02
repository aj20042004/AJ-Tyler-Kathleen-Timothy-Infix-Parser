
// Questions for professor:
// ---------------------------------------------------------------------------------------------------------------------- 
// 1) Parsing the infix string while reading without changing it's format for efficiency ( check with prof )
// 2) Should I consider single "equalto" sign ('=') in the test case ? like 2 = 3 ( assignment operator)  
// 3) check the correctness of ((2 * 3) ^ 2) + (4 * 5) % 3 expression with prof - Test case 2
// 4) check the correctness of 2 ^ 3 ^ 2 with prof - Test case 2
// 5) check the correctness of 0 || (2 > 1) && (3 / 0 > 5) - Test case 3
// 6) check the correctness of -(-2) - Test case 3
// 7) Is it necessary to have operator and operand header and cpp, if yes, Do I need to include the power function 
//    as well and UML diagram.

// Need to Complete:
// ----------------------------------------------------------------------------------------------------------------------
// Operand class and in-line comments - Tyler Blackmore
// Creating Test cases, checking the correctness of the program, in-line comments for main file ? - Kathleen Dunn
// Operator class and in-line comments - Timothy Huffman

// Bugs needs to be fixed:
// ----------------------------------------------------------------------------------------------------------------------
// 1) For the input - 2 ^ 3 ^ 2, the program's generating wrong output. The expected result should be 512 instead of 64

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
	input_file.open("Test_case_3.txt");

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