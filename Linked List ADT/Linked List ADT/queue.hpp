// Linked List Queue ADT.

#ifndef QUEUE_HPP
#define QUEUE_HPP

#include "node.hpp"
#include <new>
#include <cassert>

template<typename T>
class Queue {
public:
    Queue() : beggining(0), ending(0);
    Queue(const Queue<T>&); // Copy Constructor
    ~Queue(); // Destructor
    void swap(Queue<T>&); // Const Time Swap
    Queue<T>& operator=(Queue<T> rhs) { swap(rhs); return *this; }; // Overloaded Assignemnt

    bool isEmpty() const { return beginning == 0; };
    bool isFull() const;
    void enqueue(const T&);
    T dequeue();

private:
    Node<T>* beginning, * ending;
};

template<typename T>
void Queue<T>::enqueue(const T& item) {
    if (beginning == 0) {
        beginning = new Node<T>(item);
        ending = beginning;
    }
    else {
        ending->next = new Node<T>(item);
        ending = ending->next;
    }
}

template<typename T>
T Queue<T>::dequeue() {
    assert(!isEmpty());
    Node<T>* temp = beginning;
    T result = beginning->data;
    beginning = beginning->next;

    if (beginning == 0) { ending == 0; }
    delete temp;

    return result;
}

// Destructor
template<typename T>
Queue<T>::~Queue() {
    Node<T>* temp;
    while (beginning != 0) {
        temp = beginning;
        beginning = beginning->next;
        delete temp;
    }
}

// Copy Constructor
template<typename T>
Queue<T>::Queue(const Queue<T>& actual) {
    Node<T>* temp = actual.beginning;
    while (temp != 0) {
        if (!beginning) {
            ending = new Node<T>(temp->data);
            beginning = ending;
        }
        else {
            ending->next = new Node<T>(temp->data);
            ending = ending->next;
        }
        temp = temp->next;
    }
}

// Const Time Swap
template<typename T>
void Queue<T>::swap(Queue<T>& rhs) {
    Node<T>* temp = beginning;
    beginning = rhs.beginning;
    rhs.beginning = temp;

    temp = ending;
    ending = rhs.ending;
    rhs.ending = temp;
}

#endif
