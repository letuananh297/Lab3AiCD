#include <iostream>
#include "BinarySearchTree.h"

using namespace std;

int main() {
	BinarySearchTree tree;
	tree.insert(8);
	tree.insert(3);
	tree.insert(10);
	tree.insert(1);
	tree.insert(6);
	tree.insert(14);
	tree.insert(4);
	tree.insert(7);
	tree.insert(13);

	cout << "Breadth-first traversal: ";
	Iterator* tree_bft = tree.create_bft_iterator();
	while (tree_bft->hasnext())
		cout << tree_bft->next() << " ";
	cout << endl;

	cout << "\nDepth-first traversal: ";
	Iterator* tree_dft = tree.create_dft_iterator();
	while (tree_dft->hasnext())
		cout << tree_dft->next() << " ";
	cout << endl << endl;

	if (tree.contains(7))
		cout << "There is element 7 in the tree." << endl;
	else
		cout << "There is not element 7 in the tree." << endl;

	if (tree.contains(29))
		cout << "There is element 29 in the tree." << endl;
	else
		cout << "There is not element 29 in the tree." << endl;

	tree.remove(3);

	cout << "\nBreadth-first traversal after removing 3: ";
	Iterator* tree_bft1 = tree.create_bft_iterator();
	while (tree_bft1->hasnext())
		cout << tree_bft1->next() << " ";
	cout << endl;

	cout << "\nDepth-first traversal after removing 3: ";
	Iterator* tree_dft1 = tree.create_dft_iterator();
	while (tree_dft1->hasnext())
		cout << tree_dft1->next() << " ";
	cout << endl;

	tree.remove(1);

	cout << "\nBreadth-first traversal after removing 1: ";
	Iterator* tree_bft2 = tree.create_bft_iterator();
	while (tree_bft2->hasnext())
		cout << tree_bft2->next() << " ";
	cout << endl;

	cout << "\nDepth-first traversal after removing 1: ";
	Iterator* tree_dft2 = tree.create_dft_iterator();
	while (tree_dft2->hasnext())
		cout << tree_dft2->next() << " ";
	cout << endl;

	tree.remove(6);

	cout << "\nBreadth-first traversal after removing 6: ";
	Iterator* tree_bft3 = tree.create_bft_iterator();
	while (tree_bft3->hasnext())
		cout << tree_bft3->next() << " ";
	cout << endl;

	cout << "\nDepth-first traversal after removing 6: ";
	Iterator* tree_dft3 = tree.create_dft_iterator();
	while (tree_dft3->hasnext())
		cout << tree_dft3->next() << " ";
	cout << endl;

	return 0;
}