// Stack ADT Function with Templates.

#ifndef STACK_HPP
#define STACK_HPP

#include <cassert>

const int SIZE = 100;

//
// CLASS INV: element{tos,...0] || tos == -1
//

template <typename T>
class Stack {
public:
	Stack() : tos(-1) {};
	bool isEmpty() const { return (tos == -1); };
	bool isFull() const { return (tos >= SIZE); };
	T pop() { assert(!isEmpty()); return element[tos--]; }; // Postfix -- that decrements after return.
	T top() const { assert(!isEmpty()); return element[tos]; }; // Gives element on top of Stack.
	void push(const T& item) { assert(!isFull()); element[++tos] = item; };

private:
	T element[SIZE];
	int tos; // Index of the element on the Top of Stack.

};

#endif
