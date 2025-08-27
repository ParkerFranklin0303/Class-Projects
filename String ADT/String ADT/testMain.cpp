// Test functions for String ADT.

#include "string.hpp"
#include <iostream>

int main() {
	String numOne("123"), numTwo("1234"), sub;
	sub = numTwo.substr(0, 3);
	std::cout << sub;
}