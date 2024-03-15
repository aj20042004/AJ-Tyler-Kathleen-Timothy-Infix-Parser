#include <string>
#include <iostream>
#include <iomanip>
#include "Infix.h"

using namespace std;

int main() {

	string infix_input;
	cout << "Enter an Infix expression: " << endl;

	getline(cin, infix_input);

	int result = evaluate_infix(infix_input);

	cout << "The Result: " << result << endl;

	return 0;
}