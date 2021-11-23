#pragma once
#include <iostream>

using namespace std;

class Queue {
private:
	class Element_Queue {
	public:
		int data;
		Element_Queue* next;
	};

public:
	Element_Queue* front;
	Element_Queue* rear;
	size_t size;

	int getQueue() {
		return front->data;
	}

	void enQueue(int x) {
		Element_Queue* Node = new Element_Queue;
		Node->data = x;
		Node->next = NULL;
		if (isEmpty()) {
			rear = Node;
			front = Node;
		}
		else {
			rear->next = Node;
			rear = Node;
		}
		size++;
	}

	void deQueue() {
		if (isEmpty())
			throw runtime_error("Stack is empty.");
		else {
			Element_Queue* temporary = front;
			front = temporary->next;
			delete temporary;
		}
		size--;
	}

	size_t getsize() { return size; }

	bool isEmpty() {
		if (front == NULL && rear == NULL)
			return true;
		else {
			return false;
			if (front == NULL && rear != NULL)
				front = rear;
			if (front != NULL && rear == NULL)
				rear = front;
		}
	}

	Queue() {
		front = NULL;
		rear = NULL;
		size = 0;
	}

	~Queue() = default;
};