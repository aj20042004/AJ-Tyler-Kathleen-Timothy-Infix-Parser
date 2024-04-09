#ifndef EVALUATE_POSTFIX_H
#define EVALUATE_POSTFIX_H

// Importing the modules
#include <string>

using namespace std;

// Creating the Evaluate Postfix class
class Evaluate_postfix {

public:

	// Constructor
	Evaluate_postfix();

	// Destructor
	~Evaluate_postfix();

	// evaluate_postfix to get the result
	int postfix_evaluator(const string&);

};

#endif
