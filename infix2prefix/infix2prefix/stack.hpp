//
// File: stack.hpp
//
// Programmer:
// Date:        Spring 2024
//
//
// Do not change the names of the classes or methods.  Otherwise, instructor
//  tests will not work.
//
#ifndef CS2_STACK_HPP_
#define CS2_STACK_HPP_

#include "string.hpp"
#include <new>
#include <cassert>

template<typename T>
class Node {
public:
    Node() : next(0) {};
    Node(const T& item) : data(item), next(0) {};
    T data; // The Data. / PUBLIC!
    Node<T>* next; // Pointer to a Data Node. / PUBLIC!
};


// CLASS INV:
//
template <typename T>
class stack {
public:
    stack() : tos(0) {};
    stack(const stack<T>&); // Copy Constructor
    ~stack(); // Destructor
    void      swap(stack<T>&); // Const Time Swap
    stack<T>& operator= (stack<T> rhs) { swap(rhs); return *this; }; // Overloaded Assignment

    bool      empty() const { return tos == 0; };
    bool      full() const;
    T         top() const { assert(!empty()); return tos->data; };
    T         pop();
    void      push(const T&);

private:
    Node<T>* tos;
};

//REQUIRES: tos->x1->x2 -> ... xN -> 0
// ENSURE: tos -> item -> x1 -> x2 -> ... xN -> 0
template <typename T>
void stack<T>::push(const T& item) {
    assert(!full());
    Node<T>* temp = new Node<T>(item);
    temp->next = tos;
    tos = temp;
}

// REQUIRES: tos-> x1 -> x2 -> ... xN->0 && tos != 0
// ENSURE:   tos-> x2 -> ... xN -> 0
template <typename T>
T stack<T>::pop() {
    assert(!empty());
    T result = tos->data;
    Node<T>* temp = tos;
    tos = tos->next;
    delete temp;
    return result;
}

// Destructor
template <typename T>
stack<T>::~stack() {
    Node<T>* temp;
    while (tos != 0) {
        temp = tos;
        tos = tos->next;
        delete temp;
    }
}

// Copy Constructor
template <typename T>
stack<T>::stack(const stack<T>& actual) {
    Node<T>* temp = actual.tos;
    Node<T>* bottom = 0;
    tos = 0;
    while (temp != 0) {
        if (tos == 0) {
            tos = new Node<T>(temp->data);
            bottom = tos;
        }
        else {
            bottom->next = new Node<T>(temp->data);
            bottom = bottom->next;
        }
        temp = temp->next;
    }
}

// Constant Time Swap
template <typename T>
void stack<T>::swap(stack<T>& rhs) {
    Node<T>* temp = tos;
    tos = rhs.tos;
    rhs.tos = temp;
}

template <typename T>
bool stack<T>::full() const {
    Node<T>* temp = new(std::nothrow) Node<T>(); //if we ran out of heap memory it will point to zero. Instead of implementating an exception.
    if (temp == 0) //No memory remaining
        return true;
    delete temp;
    return false;
}

#endif
