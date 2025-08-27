// Queue Data Structure ADT.

#ifndef QUEUE_HPP
#define QUEUE_HPP

#include <iostream>
#include <cassert>

const int SIZE = 100;

template <typename T>
class queue {
public:
	queue() : front(0), back(0), empty(true) {};
	bool isEmtpy() const { return empty; };
	bool isFull() const { return !empty && (front == back); };
	void enqueue(const T&);
	T dequeue();

private:
	int front, back;
	bool empty;
	T q[SIZE];
};

template <typename T>
void queue<T>::enqueue(const T& item) {
	assert(!isFull());
	q[back] = item;
	back = (back + 1) % SIZE; // Modulo allows the queue to add new elements to the "Front" when you reach the end.
	empty = false;
}

template <typename T>
T queue<T>::dequeue() {
	assert(!isEmpty());
	T result = q[front];
	front = (front + 1) % SIZE; // Modulo allows the front to become element 0 if the end is reached.
	if (front == back) { empty = true; }
	return result;
}

#endif
