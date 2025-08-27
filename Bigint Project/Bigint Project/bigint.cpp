// Function Definitions for class bigint.
// Parker Franklin
// 1/23/2024

#include "bigint.hpp"
#include <iostream>

// 
// bigint Functions
//

// Default consturctor that initializes all elements of bigint to 0.
bigint::bigint() {
	for (int i = 0; i < CAPACITY; ++i) {
		biArray[i] = 0;
	}
}

// Consturctor that assigns integer value to bigint array.
bigint::bigint(int num) : bigint() {
	int position = 0;
	while (num != 0) {
		int digit = num % 10;
		biArray[position] = digit;
		++position;
		num = num / 10;
	}
}

// Constructor that assigns a character to the value of bigint array.
bigint::bigint(const char charValue[]) : bigint() {
	int num, len = 0, position = 0;
	while (charValue[len] != 0) {
		++len;
	}
	for (int i = len - 1; i >= 0; --i) {
		num = int(charValue[i]) - int('0');
		biArray[position] = num;
		++position;
	}
}

// Prints all values of bigint for debugging.
void bigint::debugPrint(std::ostream& stream) const {
	for (int i = CAPACITY - 1; i >= 0; --i) {
		stream << biArray[i];
		if (i != 0) { std::cout << " | "; }
	}
}

// Operator overload that writes bigint to an ostream.
std::ostream& operator<< (std::ostream& stream, bigint num) {
	int numTrack = 0, zeroTrack = 0;
	for (int i = CAPACITY - 1; i >= 0; --i) {
		if (num.biArray[i] != 0) {
			for (int j = i; j >= 0; --j) {
				if (numTrack == 80) { stream << std::endl; numTrack = 0; }
				stream << num.biArray[j];
				++numTrack;
			}
		}
		else {
			++zeroTrack;
			continue;
		}
		break;
	}
	if (zeroTrack == CAPACITY) { stream << "0"; }
	return stream;
}

// Operator overload that compares if two bigint values are equal.
bool operator== (bigint valOne, bigint valTwo) {
	for (int i = 0; i < CAPACITY; ++i) {
		if (valOne.biArray[i] == valTwo.biArray[i]) {
			continue;
		}
		else {
			return false;
		}
	}
	return true;
}

// Overload subscript to return decimal position of a bigint number.
// REQUIRES: i >= 0 && i < CAPACITY
int bigint::operator[] (int i) {
	if (i < 0 || i >= CAPACITY) {
		return 0;
	}
	else {
		return biArray[i];
	}
}

// Overload addition to add two bigint arrays.
bigint bigint::operator+ (const bigint& rhs) const {
	bigint addNum;
	for (int i = 0; i < CAPACITY; ++i) {
		addNum.biArray[i] += biArray[i] + rhs.biArray[i];
		if (addNum.biArray[i] > 9) {
			int quotient = addNum.biArray[i] / 10;
			int remainder = addNum.biArray[i] % 10;
			addNum.biArray[i] = remainder;
			addNum.biArray[i + 1] += quotient;
		}
	}
	return addNum;
}

// Overload of input operator.
std::istream& operator>> (std::istream& in, bigint& rhs) {
	char ch;
	int intBi[CAPACITY], len = 0;
	while (in.get(ch) && ch != ';') {
		if (ch != '\n' && ch != ' ') {
			intBi[len] = int(ch) - int('0');
			++len;
		}
	}
	for (int i = 0; i < len; ++i) {
		rhs.biArray[i] = intBi[len - (i + 1)];
	}
	return in;
}

// Multiplies a bigint by a digit from 0 to 9.
bigint bigint::timesDigit(int num) const {
	if (num > 9) { return -1; }
	bigint multNum;
	for (int i = 0; i < CAPACITY; ++i) {
		multNum.biArray[i] += biArray[i] * num;
		if (multNum.biArray[i] > 9) {
			int quotient = multNum.biArray[i] / 10;
			int remainder = multNum.biArray[i] % 10;
			multNum.biArray[i] = remainder;
			multNum.biArray[i + 1] += quotient;
		}
	}
	return multNum;
}

// Shifts bigint values to the left and multiplies it by 10^n.
bigint bigint::times10(int n) const {
	bigint shiftNum;
	if (n < 0) { return shiftNum; }
	for (int i = 0; i < CAPACITY; ++i) {
		shiftNum.biArray[i] = biArray[i];
	}
	int track = 1;
	for (int j = 0; j < n; ++j) {
		for (int k = 0; k < CAPACITY; ++k) {
			shiftNum.biArray[k + track] = biArray[k];
		}
		shiftNum.biArray[j] = 0;
		++track;
	}
	return shiftNum;
}

bigint bigint::operator* (const bigint& rhs) const {
	bigint product,temp;
	for (int i = 0; i < CAPACITY; ++i) {
		temp = timesDigit(rhs.biArray[i]);
		product = product + temp.times10(i);
	}
	return product;
}