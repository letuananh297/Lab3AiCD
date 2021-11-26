#pragma once
#include <iostream>
#include "Iterator.h"
#include "Stack.h"
#include "Queue.h"

using namespace std;

class Element_BST {
public:
	int data;
	Element_BST* parent;
	Element_BST* left;
	Element_BST* right;

	Element_BST() {
		this->data = 0;
		this->parent = NULL;
		this->left = NULL;
		this->right = NULL;
	}
};

class BinarySearchTree {
public:
	Element_BST* root;

	bool contains(int x) {
		if (root == NULL)
			throw runtime_error("Tree is empty.");
		else {
			if (root->data == x)
				return true;
			else {
				Element_BST* Node = root;
				while (Node != NULL) {
					if (x > Node->data) {
						if (Node->right != NULL)
							Node = Node->right;
						else {
							return false;
							break;
						}
					}
					else if (x < Node->data) {
						if (Node->left != NULL)
							Node = Node->left;
						else {
							return false;
							break;
						}
					}
					else {
						return true;
						break;
					}
				}
			}
		}
	}

	void insert(int x) {
		if (root == NULL) {
			Element_BST* Node = new Element_BST;
			Node->data = x;
			root = Node;
		}
		else {
			Element_BST* Node = root;
			while (Node->left != NULL || Node->right != NULL) {
				if (x > Node->data) {
					if (Node->right != NULL)
						Node = Node->right;
					else break;
				}
				else {
					if (Node->left != NULL)
						Node = Node->left;
					else break;
				}
			}
			Element_BST* newNode = new Element_BST;
			newNode->data = x;
			newNode->parent = Node;
			newNode->left = NULL;
			newNode->right = NULL;
			if (newNode->data > Node->data)
				Node->right =  newNode;
			else
				Node->left = newNode;
		}
	}

	void remove(int x) {
		if (root == NULL)
			throw runtime_error("Tree is empty.");
		else if (!contains(x))
			throw logic_error("There is not element x in the tree.");
		else {
			Element_BST* Node = root;
			while (Node != NULL) {
				if (x > Node->data)
					Node = Node->right;
				else if (x < Node->data)
					Node = Node->left;
				else
					break;
			}
			if ((Node->left == NULL) && (Node->right == NULL)) {
				if (Node->data <= Node->parent->data) {
					Node->parent->left = NULL;
					delete Node;
				}
				else {
					Node->parent->right = NULL;
					delete Node;
				}
			}
			else if ((Node->left == NULL) && (Node->right != NULL)) {
				Element_BST* temporary = Node->right;
				Node->data = temporary->data;
				Node->right = NULL;
				delete temporary;
			}
			else if ((Node->left != NULL) && (Node->right == NULL)){
				Element_BST* temporary = Node->left;
				Node->data = temporary->data;
				Node->left = NULL;
				delete temporary;
			}
			else if ((Node->left != NULL) && (Node->right != NULL)) {
				Element_BST* temporary = Node->right;
				while (temporary->left != NULL)
					temporary = temporary->left;
				Node->data = temporary->data;
				temporary->parent->left = NULL;
				delete temporary;
			}
		}
	}

	Iterator* create_dft_iterator();

	Iterator* create_bft_iterator();

	class DFT : public Iterator {
	public:
		friend class BinarySearhTree;
		DFT(Element_BST*);
		bool hasnext() override;
		int next() override;
	private:
		Element_BST* current;
		Stack<Element_BST*>* stack;
	};

	class BFT : public Iterator {
	public:
		friend class BinarySearchTree;
		BFT(Element_BST*);
		bool hasnext() override;
		int next() override;
	private:
		Element_BST* current;
		Queue<Element_BST*>* queue;
	};

	BinarySearchTree() { root = NULL;}
	~BinarySearchTree() = default;
};

Iterator* BinarySearchTree::create_bft_iterator() {
	BFT* new_bft = new BFT(root);
	return new_bft;
}

BinarySearchTree::BFT::BFT(Element_BST* start) {
	current = start;
	queue = new Queue<Element_BST*>();
}

int BinarySearchTree::BFT::next() {
	if (!hasnext())
		throw out_of_range("No more elements in binary tree search.");
	else {
		int temp = current->data;
		if (current->left != NULL)
			queue->enQueue(current->left);
		if (current->right != NULL)
			queue->enQueue(current->right);
		if (!queue->isEmpty())
			current = queue->deQueue();
		else
			current = NULL;
		return temp;
	}
}

bool BinarySearchTree::BFT::hasnext() {
	if (current != NULL)
		return 1;
	else
		return 0;
}

Iterator* BinarySearchTree::create_dft_iterator() {
	DFT* new_dft = new DFT(root);
	return new_dft;
}

BinarySearchTree::DFT::DFT(Element_BST* start) {
	current = start;
	stack = new Stack<Element_BST*>();
}

int BinarySearchTree::DFT::next() {
	if (!hasnext()) {
		throw out_of_range("No more elements");
	}
	int current_data = current->data;

	if (current->right != NULL) {
		stack->push(current->right);
    }

	if (current->left != NULL)
		current = current->left;
	else {
		if (!stack->isEmpty())
			current = stack->pop();
		else
			current = NULL;
	}
	return current_data;
}

bool BinarySearchTree::DFT::hasnext() {
	if (current != NULL)
		return 1;
	else
		return 0;
}