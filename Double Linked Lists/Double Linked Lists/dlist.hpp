// Double Linked List and Iterator ADT.

#ifndef DLIST_HPP
#define DLIST_HPP

#include <iostream>
#include <cassert>

// Dynamic Node ADT.
template <typename T>
class Dnode {
public:
	Dnode() : next(0), prev(0) {};
	Dnode(const T& x) : data(x), prev(0) {}; // Copy Constructor.
	T data;
	Dnode<T>* next, * prev;
};

// "Forward Declaration" - Initializes the 'List' Class for other classes because they need it before its defined.
template <typename T> class List;

// Iterator ADT.
template <typename T>
class Itr {
public:
	Itr() : current(0) {};
	Itr(Dnode<T>* ptr) : current(ptr) {};

	Itr<T>& operator++() { if (current) current = current->next; return *this; }; // Pre ++i // "if (current)" = If current is not null.
	Itr<T> operator++(int) { Itr<T> original(current); if (current) current = current->next; return original; };// Post i++ // the 'int' parameter is a dummy for the compiler.
	Itr<T>& operator--() { if (current) current = current->prev; return *this; } // Pre --i
	Itr<T> operator--(int) { Itr<T> original(current); if (current) current = current->prev; return original; } // Post i--

	T operator*() const { assert(current); return current->data; }; // Const Dereference Operator Overload.
	T& operator*() { assert(current); return current->data; }; // Dereference Operator Overload.

	const Dnode<T>* operator->() const { return current; }; // Const -> Operator Overload.
	Dnode<T>* operator->() { return current; }; // -> Operator Overload. // Must be a method that returns a pointer or object of the class.

	bool operator== (Dnode<T>* rhs) const { return current == rhs.current; }; // == Operator Overload.
	bool operator!= (Dnode<T>* rhs) const { return current != rhs.current; }; // != Operator Overloads.

	friend class List;

private:
	Dnode<T>* current;
};

// List ADT.
template <typename T>
class List {
public:
	List() : beginning(0), ending(0) {}; // Default Constructor.
	List(const List<T>&); // Copy Constructor.
	~List(); // Destructor.
	void swap(List<T>&); // Const Time Swap.
	List<T>& operator= (List<T> rhs) { swap(rhs); return *this; }; // Overloaded Assignment.

	int length() const;
	int isEmpty() const { return beginning == 0; };
	int isFull() const;

	Itr<T> begin() const { return Itr<T>(beginning); };
	Itr<T> begin() { return Itr<T>(beginning); };
	Itr<T> end() const { return Itr<T>(ending); };
	Itr<T> end() { return Itr<T>(ending); };
	T front() const { return beginning->data; };
	T front() { return beginning->data; };
	T back() const { return ending->data; };
	T back() { return ending->data; };
	Itr<T> operator[](int) const;
	Itr<T> find(const T&) const;

	void remove(Itr<T>);
	void insertAfter(Itr<T>, const T&);
	void insertBefore(Itr<T>, const T&);

private:
	Dnode<T>* beginning, * ending;
};

// Inserts a new node before the current node.
template <typename T>
void List<T>::insertBefore(Itr<T> ptr, const T& item) {
	Dnode<T>* temp = new Dnode<T>(item);
	if (beginning == 0) { // Empty List.
		beginning = temp;
		ending = temp;
	}
	else if (ptr == beginning) { // Place new node before beginning.
		temp->next = beginning;
		beginning->prev = temp;
		beginning = temp;
	}
	else { // General Case.
		temp->next = ptr.current;
		temp->prev = ptr->prev;
		ptr->prev->next = temp;
		ptr->prev = temp;
	}
}

// Inserts a new node after the current node.
template <typename T>
void List<T>::insertAfter(Itr<T> ptr, const T& item) {
	Dnode<T>* temp = new Dnode<T>(item);
	if (!beginning) { // Empty List.
		beginning = temp;
		ending = temp;
	}
	else if (ptr == ending) { // After Ending.
		ending->next = temp;
		temp->prev = ending;
		ending = temp;
	}
	else { // General Case.
		temp->next = ptr->next;
		temp->prev = ptr.current;
		ptr->next->prev = temp;
		ptr->next = temp;
	}
}

// Deletes the node at ptr's location.
template <typename T>
void List<T>::remove(Itr<T> ptr) {
	// Reassigns Beginning.
	if (ptr == beginning) {
		beginning = beginning->next;
	}
	else { // General Case
		ptr->prev->next = ptr->next;
	}

	// Reassigns Ending.
	if (ptr == ending) {
		ending = ending->prev;
	}
	else { // General Case
		ptr->next->prev = ptr->prev;
	}
	delete ptr.current;
}

// [] Operator Overload.
template <typename T>
Itr<T> List<T>::operator[](int n) const {
	Itr<T> ptr = beginning;
	int i = 0;
	while ((i < n) && (ptr != 0)) {
		++i;
		++ptr;
	}
	return ptr;
}

// Find Function to find a specific data element.
template <typename T>
Itr<T> List<T>::find(const T& key) const {
	Itr<T> ptr = beginning;
	while ((ptr != 0) && (ptr->data != key)) { ++ptr; }
	return ptr;
}

// Returns the length of the list.
template <typename T>
int List<T>::length() const {
	int n = 0;
	Itr<T> ptr = beginning;
	while (ptr != 0) {
		++n;
		++ptr;
	}
	return n;
}

// Checks if the list has used all available heap memory.
template <typename T>
int List<T>::isFull() const {
	Node<T>* temp = new(std::nothrow) Node<T>(); //if we ran out of heap memory it will point to zero instead of implementating an exception.
	if (temp == 0) //No memory remaining
		return 1;
	delete temp;
	return 0;
}

// Destructor.
template <typename T>
List<T>::~List() {
	while (beginning) {
		Dnode<T>* temp = beginning;
		beginning = beginning->next;
		delete temp;
	}
}

// Copy Constructor.
template <typename T>
List<T>::List(const List<T>& actual) : List() {
	Itr<T> ptr(actual.beginning);
	while (ptr != 0) {
		if (beginning == 0) {
			beginning = new Dnode<T>(ptr->data);
			ending = beginning;
		}
		else {
			ending->next = new Dnode<T>(ptr->data);
			ending->next->prev = ending;
			ending = ending->next;
		}
		++ptr;
	}
}

// Const Time Swap.
template <typename T>
void List<T>::swap(List<T>& rhs) {
	Dnode<T> *temp = beginning;
	beginning = rhs.beginning;
	rhs.beginning = temp;

	temp = ending;
	ending = rhs.ending;
	rhs.ending = temp;
}

#endif
