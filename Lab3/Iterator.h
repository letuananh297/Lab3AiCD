#pragma once
#include<iostream>
#include "BinarySearchTree.h"
#include "Queue.h"
#include "Stack.h"

using namespace std;

class Iterator {
public:
	virtual int next() = 0;
	virtual bool hasnext() = 0;
};

/*class BreadthFirstTraverse : public Iterator {
private:
	Element_BST* current;
	Queue* queue;

public:
	BreadthFirstTraverse(Element_BST* Node) {
		current = Node;
		queue = new Queue();
	};

	int next() override;
	bool hasnext() override;

	bool hasnext() {
		if ((current != NULL) && (queue->front != NULL))
			return 1;
		else
			return 0;
	}

	int next() {
		if (!hasnext())
			throw out_of_range("No more elements in binary tree search.");
		else {
			current->data = queue->front->data;
			queue->deQueue();
			if (current->left != NULL)
				queue->enQueue(current->left->data);
			if (current->right != NULL)
				queue->enQueue(current->right->data);
			return current->data;
		}
	}
};*/

/*class DepthFirstTraverse : public Iterator {
private:
	Element_BST* current;
	Stack* stack;

public:

	DepthFirstTraverse(Element_BST* Node) {
		current = Node;
		stack = new Stack();
	};

	/*int next() override;
	bool hasnext() override;

	bool hasnext() {
		if ((current != NULL) && (stack->top != NULL))
			return 1;
		else
			return 0;
	}

	int next() {
		if (!hasnext())
			throw out_of_range("No more elements in binary tree search.");
		else {
			int current_data = current->data;

			if (current->right != NULL)
				stack->push(current->right->data);

			if (current->left != NULL)
				current = current->left;
			else {
				current->data = stack->peek();
				stack->pop();
			}
			return current_data;
		}
	}
};*/