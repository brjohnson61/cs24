// listQ.cpp - implements queue as linked list
// NAME(S), DATE

#include "listQ.h"

Queue::Queue() {
	front = 0;
	rear = 0;
	size = 0;
}  // IMPLEMENT CONSTRUCTOR

Queue::~Queue() {
	while (front != 0) {
		Node* temp = front;
		front = front->next;
		delete temp;
	}
	delete front;
	// IMPLEMENT DESTRUCTOR (delete all the nodes)
}

void Queue::enqueue(int n) {
	Node* temp = new Node(n);
	if (isEmpty()) {
		front = temp;
		rear = temp;
	}
	else {
		rear->next = temp;
		rear = rear->next;
	}
	size++;
	// IMPLEMENT (remember to consider special cases)
}

int Queue::dequeue() {
	int a;
	if (isEmpty())
		throw EmptyQueue();
	else {
		Node* tempptr = front;
		a = front->data;
		front = front->next;
		delete tempptr;
		if (size == 1) {
			front = 0;
			rear = 0;
		}
		size--;
	}
	// COMPLETE THIS IMPLEMENTATION (remember to delete node)
	return a; // AND REPLACE THIS RETURN STATEMENT
}

void Queue::clear() {
	Node* garbage;
	while (front != 0) {
		garbage = front;
		front = front->next;
		delete garbage;
	}
	front = 0;
	rear = 0;
	size = 0;
	// IMPLEMENT (delete all nodes and reset variables)
}

bool Queue::isEmpty() const {
	if (size != 0) {
		return false;
	}
	// IMPLEMENT
	return true; // AND REPLACE THIS RETURN STATEMENT
}

int Queue::getSize() const {
	// IMPLEMENT
	return size; // AND REPLACE THIS RETURN STATEMENT
}