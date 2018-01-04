// arrayQ.cpp - implements queue as array
// NAME(S), DATE

#include "arrayQ.h"

Queue::Queue() {
 	front = 0;
	rear = 0;
	size=0;
	data[10] = {0};
}  // IMPLEMENT CONSTRUCTOR

void Queue::enqueue(int n) {
    if (isFull()){
        throw FullQueue();
}
    else{
	data[rear]=n;
	rear = (rear + 1) % CAPACITY;
	size++;

}
    // COMPLETE THIS IMPLEMENTATION
}

int Queue::dequeue() {
	int a;
    if (isEmpty()){
        throw EmptyQueue();
}
    else{
	if (front == CAPACITY-1){
		a = data[front];
		front = 0;
		size--;
}
	else{
		a = data[front];
		front++;
		size--;
}
}
    // COMPLETE THIS IMPLEMENTATION
    return a; // AND REPLACE THIS RETURN STATEMENT
}

void Queue::clear() {
	front = 0;
	rear = 0;
	size = 0;
    // IMPLEMENT
}

bool Queue::isEmpty() const {
	if (size == 0)
		return true;
	else
		return false;
    // IMPLEMENT
    // AND REPLACE THIS RETURN STATEMENT
}

bool Queue::isFull() const {
	if (size == 10)
		return true;
	else
		return false; // AND REPLACE THIS RETURN STATEMENT
}

int Queue::getSize() const {
    // IMPLEMENT
    return size; // AND REPLACE THIS RETURN STATEMENT
}
