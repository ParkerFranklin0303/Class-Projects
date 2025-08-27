// Linked List Stack ADT.

#ifndef STACK_HPP
#define STACK_HPP

#include "node.hpp"
#include <iostream>
#include <cassert>

//
// CLASS INV: tos _> x1 -> x2 -> ... -> xN -> 0
//
template <typename T>
class Stack {
public:
    Stack() : tos(0) {};
    Stack(const Stack<T>&);
    ~Stack();
    void        swap(Stack<T>&);
    Stack<T>& operator=(Stack<T> rhs) { swap(rhs); return *this; }

    bool        isEmpty() const { return tos == 0; }
    bool        isFull() const;

    T           pop();
    T           top() const;
    void        push(const T&);


private:
    Node<T>* tos;
};


// REQUIRES: tos -> x1 -> x2 -> ... xN -> 0
// ENSURE: tos -> item -> x1 -> x2 -> ... xN -> 0
template <typename T>
void Stack<T>::push(const T& item) {
    assert(!isFull());
    Node<T>* temp = new Node<T>(item);
    temp->next = tos;
    tos = temp;
}

// REQUIRES: tos-> x1 -> x2 -> ... xN->0 && tos != 0
// ENSURE:   tos-> x2 -> ... xN -> 0
template <typename T>
T Stack<T>::pop() {
    assert(!isEmpty());
    T result = tos->data;
    Node<T>* temp = tos;
    tos = tos->next;
    delete temp;
    return result;
}

// Go through and find every element and deallocate it.
template <typename T>
Stack<T>::~Stack() {
    Node<T>* temp;
    while (tos != 0) {
        temp = tos;
        tos = tos->next;
        delete temp;
    }
}

template <typename T>
Stack<T>::Stack(const Stack<T>& actual) {
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

// Constant Time Swap Implementation
template <typename T>
void Stack<T>::swap(Stack<T>& rhs) {
    Node<T>* temp = tos;
    tos = rhs.tos;
    rhs.tos = temp;
}

template <typename T>
bool Stack<T>::isFull() const {
    Node<T>* temp = new(std::nothrow) Node<T>(); //if we ran out of heap memory it will point to zero. Instead of implementating an exception.
    if (temp == 0) //No memory remaining
        return true;
    delete temp;
    return false;
}

#endif
