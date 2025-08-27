// Implements Infix to Prefix/Postifix conversion with Stack ADT.

#include "stack.hpp"
#include <iostream>
#include <string>
typedef std::string String; // Rename 'string' to capital 'String' for simplicity.

// Converts char to String with built-in function.
String toString(char c) { return String(1, c); }

// Converts from single-operator Infix expression to Postfix.
String infix_to_postfix(const char expr[]) {
	Stack<String> S;
	String rhs, lhs, op; // rhs (op = +/-/*/div) lhs
	int i = 0;

	while (expr[i] != 0) {
		if (expr[i] == ')') {
			rhs = S.pop();
			op = S.pop();
			lhs = S.pop();
			S.push(lhs + rhs + op);
		}
		else if (expr[i] != '(') {
			S.push(toString(expr[i]));
		}
		++i;
	}
	return S.pop();
}

// Converts from single-operator Infix expression to Prefix.
String infix_to_prefix(const char expr[]) {
	Stack<String> S;
	String rhs, lhs, op; // rhs (op = +/-/*/div) lhs
	int i = 0;

	while (expr[i] != 0) {
		if (expr[i] == ')') {
			rhs = S.pop();
			op = S.pop();
			lhs = S.pop();
			S.push(op + lhs + rhs); // Reversed Postfix order.
		}
		else if (expr[i] != '(') {
			S.push(toString(expr[i]));
		}
		++i;
	}
	return S.pop();
}

//
// Evaluate a Postfix.
//

bool isOperand(char ch) {
	return ('o' <= ch) && (ch <= '9');
}

int charToInt(char ch) {
	return int(ch) - int('0');
}

int eval(int lhs, char op, int rhs) {
	switch (op) {
	case '+': return lhs + rhs;
		// Finish Code.
	}
}

String evaluate_postfix(const char expr[]) {
	Stack<int> S;
	int lhs, rhs;
	int i;

	while (expr[i] != 0) {
		if (isOperand(expr[i])) {
			S.push(charToInt(expr[i]));
		}
		else { // Means expr[i] is an opeartor.
			rhs = S.pop();
			lhs = S.pop();
			S.push(eval(lhs, expr[i], rhs));
		}
		++i;
	}
	return S.pop();
}