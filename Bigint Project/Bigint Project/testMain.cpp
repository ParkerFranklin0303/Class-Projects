// multiply.cpp tests for Milestone 2.
// Parker Franklin

#include "bigint.hpp"
#include <iostream> 
#include <fstream>
#include <cstdlib>

int main() {
    std::ifstream in;
    in.open("data1-1.txt");
    if (!in) {
        std::cerr << "File not found: data1-1.txt" << std::endl;
        exit(1);
    }

    bigint numOne, numTwo, result;
    while (in >> numOne >> numTwo && !in.eof()) {
        result = numOne + numTwo;
        std::cout << numOne << " | " << numTwo << std::endl;
        std::cout << "Addition = " << result << std::endl;

        numOne = 0; numTwo = 0; result = 0;
    }

    in.close();
    return 0;
}