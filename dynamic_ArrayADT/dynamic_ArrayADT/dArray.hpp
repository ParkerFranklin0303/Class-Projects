// Header file for Dynamic Array ADT.

#ifndef DARRAY_HPP
#define DARRAY_HPP

#include <iostream>
#include <cassert>

class Darray {
public:
	Darray () : ptr(0), cap() {}; // Initializes ptr and cap when constructor is called.
	Darray(int); // Initializes Darray with a new cap.
	Darray(const Darray&); // Copy Constructor.
	~Darray();			   // Destructor.
	Darray& operator= (const Darray&); // Overloaded Assignment (Old Version).
	Darray& operator= (Darray); // Overloaded Assignment (Standard Version).
	void swap(Darray&); // Const Time Swap.

	int operator[] (int);
	int operator[] (int) const;

	int capacity() const { return cap; }
	void resizeCapacity(int);

private:
	int *ptr;
	int cap;
};

#endif
