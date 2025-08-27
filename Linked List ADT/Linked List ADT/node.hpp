// Node ADT.

#ifndef NODE_HPP
#define NODE_HPP

#include <iostream>
#include <cassert>

template <typename T>
class Node {
public:
	Node() : next(0) {};
	Node(const T& item) : data(item), next(0) {};
	T data; // The Data. / PUBLIC!
	Node<T> *next; // Pointer to a Data Node. / PUBLIC!
};

#endif
