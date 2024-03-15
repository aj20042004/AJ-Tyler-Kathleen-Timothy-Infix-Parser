#ifndef INFIX_H
#define INFIX_H
#include <iostream>
#include <string>
#include <stack>
#include <cctype>

using namespace std;

// Function to determine precedence of operators
int precedence(char op) {
    if (op == '^')
        return 3;
    else if (op == '*' || op == '/' || op == '%')
        return 2;
    else if (op == '+' || op == '-')
        return 1;
    else
        return 0;
}

int evaluate_infix(const string& expression) {
    
    stack<int> operands;
    stack<char> operators;

    for (size_t i = 0; i < expression.length(); ++i) {
        
        if (isspace(expression[i])) {
            continue; // Skip whitespaces
        }
        else if (isdigit(expression[i])) {
            int operand = 0;
            while (i < expression.length() && isdigit(expression[i])) {
                operand = operand * 10 + (expression[i] - '0');
                ++i;
            }
            --i; // Move back one step after the loop
            operands.push(operand);
        }
        else if (expression[i] == '(') {
            operators.push(expression[i]);
        }
        else if (expression[i] == ')') {
            while (!operators.empty() && operators.top() != '(') {
                int op2 = operands.top();
                operands.pop();
                int op1 = operands.top();
                operands.pop();
                char op = operators.top();
                operators.pop();

                if (op == '+') {
                    operands.push(op1 + op2);
                }
                else if (op == '-') {
                    operands.push(op1 - op2);
                }
                else if (op == '*') {
                    operands.push(op1 * op2);
                }
                else if (op == '/') {
                    if (op2 == 0) {
                        cout << "Error: Division by zero" << endl;
                        return 0;
                    }
                    operands.push(op1 / op2);
                }
                // Add logic for other operators
            }
            operators.pop(); // Pop '('
        }
        else {
            while (!operators.empty() && operators.top() != '(' && precedence(operators.top()) >= precedence(expression[i])) {
                int op2 = operands.top();
                operands.pop();
                int op1 = operands.top();
                operands.pop();
                char op = operators.top();
                operators.pop();

                if (op == '+') {
                    operands.push(op1 + op2);
                }
                else if (op == '-') {
                    operands.push(op1 - op2);
                }
                else if (op == '*') {
                    operands.push(op1 * op2);
                }
                else if (op == '/') {
                    if (op2 == 0) {
                        cout << "Error: Division by zero" << endl;
                        return 0;
                    }
                    operands.push(op1 / op2);
                }
                // Add logic for other operators
            }
            operators.push(expression[i]);
        }
    }

    while (!operators.empty()) {
        int op2 = operands.top();
        operands.pop();
        int op1 = operands.top();
        operands.pop();
        char op = operators.top();
        operators.pop();

        if (op == '+') {
            operands.push(op1 + op2);
        }
        else if (op == '-') {
            operands.push(op1 - op2);
        }
        else if (op == '*') {
            operands.push(op1 * op2);
        }
        else if (op == '/') {
            if (op2 == 0) {
                cout << "Error: Division by zero" << endl;
                return 0;
            }
            operands.push(op1 / op2);
        }
        // Add logic for other operators
    }

    return operands.top();
}





#endif
