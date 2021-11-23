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

	Element_BST(int data, Element_BST* parent) {
		this->data = data;
		this->parent = parent;
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
				//bool check = 0;
				while (Node != NULL || Node != NULL) {
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
				//return check;
			}
		}
	}

	void insert(int x) {
		if (root == NULL) {
			Element_BST* Node = new Element_BST(x, NULL);
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
			Element_BST* newNode = new Element_BST(x, Node);
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
				if (Node->data < Node->parent->data) {
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

	class ListIterator : public Iterator {
	public:
		ListIterator(Element_BST* start);
		bool hasnext() override;
		int next() override;
	private:
		Element_BST* current;
		Stack* stack = new Stack();
	};

	BinarySearchTree() { root = NULL; }
	~BinarySearchTree() = default;
};

Iterator* BinarySearchTree::create_dft_iterator() {
	return new ListIterator(root);
}

BinarySearchTree::ListIterator::ListIterator(Element_BST* start) {
	current = start;
}

int BinarySearchTree::ListIterator::next() {
	if (!hasnext()) {
		throw out_of_range("No more elements");
	}
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

bool BinarySearchTree::ListIterator::hasnext() {
	if (current != NULL)
		return 1;
	else
		return 0;
}