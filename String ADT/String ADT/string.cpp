// Function definitions of String ADT.

#include "string.hpp"
#include <iostream>

String::String() {
	str[0] = 0;
}

String::String(char ch) {
	str[0] = ch;
	str[1] = 0;
}

String::String(const char s[]) {
	int i = 0;
	while (s[i] != 0) {
		if (i >= capacity()) { break; }
		str[i] = s[i];
		++i;
	}
	str[i] = 0;
}

// ENSURES: Returns i where str[i] == 0
int String::length() const {
	int result = 0;
	while (str[result] != 0) { ++result; }
	return result;
}

// REQUIRES: 0 <= i < length()
char String::operator[] (int i) const {
	assert(i >= 0);
	assert(i < length());
	return str[i];
}

// REQUIRES: 0 <= i < length()
char& String::operator[] (int i) {
	assert(i >= 0);
	assert(i < length());
	return str[i];
}


// Basic addition overload.
// Did not use because addition can be implemented
// more efficiently using += as the starting point.
/*
String String::operator+ (const String& rhs) const {
	String result(str);
	int offset = length(), i = 0;
	while (rhs.str[i] != 0) {
		result.str[offset + i] = rhs.str[i];
		++i;
	}
	result.str[offset + i] = 0;
	return result;
}
*/

// Needs to work properly for: a += a;
String& String::operator+= (const String& rhs) {
	int offset = length();
	int rhsLen = rhs.length();
	int i = 0;
	while (i < rhsLen) {
		if (offset + i >= capacity()) { break; }
		str[offset + i] = rhs.str[i];
		++i;
	}
	str[offset + i] = 0;
	return *this;
}

// Free function overload of addition that implements +=.
String operator+ (String lhs, const String& rhs) {
	return lhs += rhs;
}

// Overload equals operator.
bool String::operator== (const String& rhs) const {
	int i = 0;
	while ((str[i] != 0) && (rhs.str[i] != 0) && (str[i] == rhs.str[i])) { ++i; }
	return str[i] == rhs.str[i];
}

// Overload less than operator.
bool String::operator< (const String& rhs) const {
	int i = 0;
	while ((str[i] != 0) && (rhs.str[i] != 0) && (str[i] == rhs.str[i])) { ++i; }
	return str[i] < rhs.str[i];
}

// Overload output operator.
std::ostream& operator<< (std::ostream& out, const String& rhs) {
	out << rhs.str;
	return out;
}

// Overload input operator.
std::istream& operator>>(std::istream& in, String& rhs) {
	char buffer[STRING_SIZE];
	if (!in.eof()) {
		in >> buffer;
	}
	else {
		buffer[0] = 0;
	}
	rhs = String(buffer);
	return in;
}

// REQUIRES: 0 <= start <= end < length()
String String::substr(int start, int end) const {
	if (start < 0) { start = 0; }
	if (end >= length()) { end = length() - 1; }
	if (start > end) { return String(); }
	String result;
	int i = start;
	while (i <= end) {
		result.str[i - start] = str[i];
		++i;
	}
	result.str[i - start] = 0;
	return result;
}

//
// Free Function Overloads that implement previous overloads.
//

bool operator< (char lhs, const String& rhs) {
	return String(lhs) < rhs;
}

bool operator< (const char lhs[], const String& rhs) {
	return String(lhs) < rhs;
}

bool operator== (char lhs, const String& rhs) {
	return String(lhs) == rhs;
}

bool operator== (const char lhs[], const String& rhs) {
	return String(lhs) == rhs;
}

bool operator!= (const String& lhs, const String& rhs) {
	return !(lhs == rhs);
}

bool operator> (const String& lhs, const String& rhs) {
	return rhs  < lhs;
}

bool operator>= (const String& lhs, const String& rhs) {
	return !(lhs < rhs);
}

bool operator<= (const String& lhs, const String& rhs) {
	return !(rhs < lhs);
}