#ifndef EVALUATE_POSTFIX_H
#define EVALUATE_POSTFIX_H
#include <string>

using namespace std;


class Evaluate_postfix {

public:

	Evaluate_postfix();

	~Evaluate_postfix();

	// evaluate_postfix to get the result
	int postfix_evaluator(const string&);

};

#endif
