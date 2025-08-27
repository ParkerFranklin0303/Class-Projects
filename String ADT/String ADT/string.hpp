// Header File for String ADT.

#ifndef STRING_HPP
#define STRING_HPP

#include <iostream>
#include <cassert>

const int STRING_SIZE = 256;

// CLASS INV: 0 <= length() <= capacity()

class String {
public:
	String();
	String(char);
	String(const char[]);

	int capacity() const { return STRING_SIZE - 1; }
	int length() const;
	char& operator[](int); // Modifier.
	char operator[] (int) const; // Const Accessor.

	// String operator+ (const String&) const;
	String& operator+= (const String&);
	bool operator== (const String&) const;
	bool operator< (const String&) const;
	String substr(int start, int end) const;
	int findChar(int start, char key) const;

	friend std::istream& operator>> (std::istream&, String&);
	friend std::ostream& operator<< (std::ostream&, const String&);

private:
	char str[STRING_SIZE];
};

String operator+ (String, const String&);
bool operator== (const char[], const String&);
bool operator== (char, const String&);
bool operator< (const char[], const String&);
bool operator< (char, const String&);
bool operator<= (const String&, const String&);
bool operator!= (const String&, const String&);
bool operator>= (const String&, const String&);
bool operator> (const String&, const String&);

#endif
