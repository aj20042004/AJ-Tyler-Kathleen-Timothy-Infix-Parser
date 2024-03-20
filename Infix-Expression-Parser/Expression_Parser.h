#ifndef EXPRESSION_PARSER_H
#define EXPRESSION_PARSER_H
#include <iostream>
#include <stack>
#include "Operator_Precedence.h"
#include <string>

using namespace std;

class Expression_Parser {

public:

	Expression_Parser();
	~Expression_Parser();

	int parse_and_evaluate(const string&);

private:

	int precedence(const string&);

	int power_function(int,int);

	string convert_to_postfix(const string&);

	int evaluate_postfix(const string&);

	void handle_error(const string&);

};

#endif
