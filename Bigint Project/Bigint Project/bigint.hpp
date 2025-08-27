// Header file for bigint project.
// Parker Franklin
// 1/23/2024

#ifndef BIGINT_HPP
#define BIGINT_HPP

#include <iostream>
#include <fstream>
#include <cassert>

const int CAPACITY = 200; // Bigint capacity global constant.

class bigint {
public:
    bigint();
    bigint(int);
    bigint(const char[]);

    void debugPrint(std::ostream&) const;
    bigint timesDigit(int) const;
    bigint times10(int) const;
    bigint operator+ (const bigint&) const;
    bigint operator* (const bigint&) const;
    int operator[] (int);
    friend std::ostream& operator<< (std::ostream&, bigint);
    friend std::istream& operator>> (std::istream&, bigint&);
    friend bool operator== (bigint, bigint);
private:
    int biArray[CAPACITY];
};

#endif
