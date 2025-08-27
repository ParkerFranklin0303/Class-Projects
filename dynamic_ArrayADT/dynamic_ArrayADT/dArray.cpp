// Functions for Dynamic Array ADT.

#include "dArray.hpp"
#include <iostream>

// Initializes array capacity to integer.
Darray::Darray(int newCap) {
	if (newCap < 0) { newCap = 0; }
	cap = newCap;
	ptr = new int[cap];
}

// Destructor.
Darray::~Darray() {
	delete[] ptr;
}

// Copy Consturctor invoked explicitely or implicitely when a bigint is called by value.
Darray::Darray(const Darray& actual) {
	cap = actual.cap;
	ptr = new int[cap];
	for (int i = 0; i < cap; ++i) {
		ptr[i] = actual.ptr[i];
	}
}

// Old version of Overloaded Assignment Operator.
Darray& Darray::operator= (const Darray& rhs) {
	if (ptr == rhs.ptr) { return *this; } // Checks if a = a.
	
	delete[] ptr;
	cap = rhs.cap;
	ptr = new int[cap];
	for (int i = 0; i < cap; ++i) {
		ptr[i] = rhs.ptr[i];
	}
	return *this;
}

// Const Time Swap that reassigns the pointers of each array.
void Darray::swap(Darray& rhs) {
	int *temp = ptr;
	ptr = rhs.ptr;
	rhs.ptr = temp;

	int ctemp = cap;
	cap = rhs.cap;
	rhs.cap = ctemp;
}

// New version of Overloaded Assignment Operator that is
// called by value and implements const time swap.
Darray& Darray::operator= (Darray rhs) {
	swap(rhs);
	return *this;
}

// Resizes an existing Darrray.
void Darray::resizeCapacity(int newCapacity) {
	int smaller = (cap < newCapacity) ? cap : newCapacity; // Ternary Operator that returns 'cap'
														   // if true and 'newCapacity' if false.
	cap = newCapacity;
	int* temp = new int[cap];

	for (int i = 0; i < smaller; ++i) {
		temp[i] = ptr[i];
	}
	delete[] ptr;
	ptr = temp;
}