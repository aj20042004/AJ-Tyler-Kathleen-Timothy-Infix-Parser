#ifndef OPERATOR_H
#define OPERATOR_H

#include <iostream>
#include <stack>

using namespace std;

class Operator {

public:
	Operator();
	~Operator();
	int perform_operation(int, int, const string&);
};

#endif
