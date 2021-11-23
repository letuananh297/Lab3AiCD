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

	/*Element_BST* cur = tree.root;
	while (cur != NULL) {
		cout << cur->data << " ";
		cur = cur->left;
	}
	cout << endl;
	cout << tree.contains(1) << endl;

	tree.remove(3);

	cout << tree.contains(3) << endl;
	cout << tree.contains(0) << endl;

	cur = tree.root;
	while (cur != NULL) {
		cout << cur->data << " ";
		cur = cur->left;
	}*/

	/*Iterator* tree_bft = tree.create_bft_iterator();
	while (tree_bft->hasnext())
		cout << tree_bft->next() << " " << endl;*/

	Iterator* tree_dft = tree.create_dft_iterator();
	while (tree_dft->hasnext())
		cout << tree_dft->next() << " " << endl;
}