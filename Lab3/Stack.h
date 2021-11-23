#pragma once
#include <iostream>
#include "BinarySearchTree.h"

using namespace std;

class Stack {
private:
	class Element_Stack {
	public:
		int data;
		Element_Stack* next;
	};
	Element_Stack* top;
	size_t size;

public:

	/*void push(Element_BST* element_bst) {
		Element_Stack* NewNode = new Element_Stack;
		NewNode->data = element_bst->data;
		NewNode->next = top;
		top = NewNode;
	}
	*/
	void push (int x) {
		if (isEmpty()) {
			Element_Stack* Node = new Element_Stack;
			Node->data = x;
			top = Node;
		}
		else {
			Element_Stack* Node = new Element_Stack;
			Node->data = x;
			Node->next = top;
			top = Node;
		}
		size++;
	}

	int pop() {
		if (isEmpty())
			throw runtime_error("Stack is empty.");
		else {
			Element_Stack* temporary = top;
			top = temporary->next;
			int popped = temporary->data;
			free (temporary);
			size--;
			return popped;
		}
	}

	int peek() {
		if (isEmpty())
			throw runtime_error("Stack is empty.");
		else
			return top->data;
	}

	bool isEmpty() {
		if (top == NULL)
			return true;
		else
			return false;
	}

	size_t getsize() { return size; }

	Stack() { 
		top = NULL; 
		size = 0; 
	}

	~Stack() = default;
};