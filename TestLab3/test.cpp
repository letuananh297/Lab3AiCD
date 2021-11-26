#include "pch.h"
#include "gtest/gtest.h"
#include "..\Lab3\BinarySearchTree.h"
#include "..\Lab3\Stack.h"
#include "..\Lab3\Queue.h"

class Test_BinarySearchTree : public ::testing::Test {
public:
	void SetTree(BinarySearchTree* tree) {
		tree->insert(8);
		tree->insert(3);
		tree->insert(10);
		tree->insert(1);
		tree->insert(6);
		tree->insert(14);
		tree->insert(4);
		tree->insert(7);
	}
};

TEST_F(Test_BinarySearchTree, Test_BreadthFirstTraversal) {
	BinarySearchTree* tree = new BinarySearchTree();
	SetTree(tree);
	Iterator* tree_bft = tree->create_bft_iterator();
	//8 3 10 1 6 14 4 7
	ASSERT_EQ(tree_bft->next(), 8);
	ASSERT_TRUE(tree_bft->hasnext());
	ASSERT_EQ(tree_bft->next(), 3);
	ASSERT_TRUE(tree_bft->hasnext());
	ASSERT_EQ(tree_bft->next(), 10);
	ASSERT_TRUE(tree_bft->hasnext());
	ASSERT_EQ(tree_bft->next(), 1);
	ASSERT_TRUE(tree_bft->hasnext());
	ASSERT_EQ(tree_bft->next(), 6);
	ASSERT_TRUE(tree_bft->hasnext());
	ASSERT_EQ(tree_bft->next(), 14);
	ASSERT_TRUE(tree_bft->hasnext());
	ASSERT_EQ(tree_bft->next(), 4);
	ASSERT_TRUE(tree_bft->hasnext());
	ASSERT_EQ(tree_bft->next(), 7);
	ASSERT_FALSE(tree_bft->hasnext());
	ASSERT_THROW(tree_bft->next(), out_of_range);
}

TEST_F(Test_BinarySearchTree, Test_DepthFirstTraversal) {
	BinarySearchTree* tree = new BinarySearchTree();
	SetTree(tree);
	Iterator* tree_dft = tree->create_dft_iterator();
	//8 3 1 6 4 7 10 14
	ASSERT_EQ(tree_dft->next(), 8);
	ASSERT_TRUE(tree_dft->hasnext());
	ASSERT_EQ(tree_dft->next(), 3);
	ASSERT_TRUE(tree_dft->hasnext());
	ASSERT_EQ(tree_dft->next(), 1);
	ASSERT_TRUE(tree_dft->hasnext());
	ASSERT_EQ(tree_dft->next(), 6);
	ASSERT_TRUE(tree_dft->hasnext());
	ASSERT_EQ(tree_dft->next(), 4);
	ASSERT_TRUE(tree_dft->hasnext());
	ASSERT_EQ(tree_dft->next(), 7);
	ASSERT_TRUE(tree_dft->hasnext());
	ASSERT_EQ(tree_dft->next(), 10);
	ASSERT_TRUE(tree_dft->hasnext());
	ASSERT_EQ(tree_dft->next(), 14);
	ASSERT_FALSE(tree_dft->hasnext());
	ASSERT_THROW(tree_dft->next(), out_of_range);
}

TEST_F(Test_BinarySearchTree, Test_contains) {
	//When tree1 is empty
	BinarySearchTree* tree1 = new BinarySearchTree();
	ASSERT_THROW(tree1->contains(7), runtime_error);

	BinarySearchTree* tree2 = new BinarySearchTree();
	SetTree(tree2);
	ASSERT_NO_THROW(tree2->contains(8));
	ASSERT_TRUE(tree2->contains(8));
	ASSERT_NO_THROW(tree2->contains(9));
	ASSERT_FALSE(tree2->contains(9));
}

TEST_F(Test_BinarySearchTree, Test_insert) {
	BinarySearchTree* tree1 = new BinarySearchTree();
	tree1->insert(7);
	ASSERT_TRUE(tree1->contains(7));
	Iterator* tree_bft1 = tree1->create_bft_iterator();
	ASSERT_EQ(tree_bft1->next(), 7);
	ASSERT_FALSE(tree_bft1->hasnext());
	ASSERT_THROW(tree_bft1->next(), out_of_range);

	BinarySearchTree* tree2 = new BinarySearchTree();
	SetTree(tree2);
	tree2->insert(9);
	ASSERT_TRUE(tree2->contains(9));
	Iterator* tree_bft2 = tree2->create_bft_iterator();
	//8 3 10 1 6 9 14 4 7
	ASSERT_EQ(tree_bft2->next(), 8);
	ASSERT_TRUE(tree_bft2->hasnext());
	ASSERT_EQ(tree_bft2->next(), 3);
	ASSERT_TRUE(tree_bft2->hasnext());
	ASSERT_EQ(tree_bft2->next(), 10);
	ASSERT_TRUE(tree_bft2->hasnext());
	ASSERT_EQ(tree_bft2->next(), 1);
	ASSERT_TRUE(tree_bft2->hasnext());
	ASSERT_EQ(tree_bft2->next(), 6);
	ASSERT_TRUE(tree_bft2->hasnext());
	ASSERT_EQ(tree_bft2->next(), 9);
	ASSERT_TRUE(tree_bft2->hasnext());
	ASSERT_EQ(tree_bft2->next(), 14);
	ASSERT_TRUE(tree_bft2->hasnext());
	ASSERT_EQ(tree_bft2->next(), 4);
	ASSERT_TRUE(tree_bft2->hasnext());
	ASSERT_EQ(tree_bft2->next(), 7);
	ASSERT_FALSE(tree_bft2->hasnext());
	ASSERT_THROW(tree_bft2->next(), out_of_range);
}

TEST_F(Test_BinarySearchTree, Test_remove) {
	//When tree1 is empty
	BinarySearchTree* tree1 = new BinarySearchTree();
	ASSERT_THROW(tree1->remove(7), runtime_error);

	BinarySearchTree* tree2 = new BinarySearchTree();
	SetTree(tree2);
	tree2->remove(3);
	tree2->remove(1);
	tree2->remove(10);
	ASSERT_FALSE(tree2->contains(3));
	ASSERT_FALSE(tree2->contains(1));
	ASSERT_FALSE(tree2->contains(10));
	Iterator* tree_dft = tree2->create_dft_iterator();
	//8 4 6 7 14
	ASSERT_EQ(tree_dft->next(), 8);
	ASSERT_TRUE(tree_dft->hasnext());
	ASSERT_EQ(tree_dft->next(), 4);
	ASSERT_TRUE(tree_dft->hasnext());
	ASSERT_EQ(tree_dft->next(), 6);
	ASSERT_TRUE(tree_dft->hasnext());
	ASSERT_EQ(tree_dft->next(), 7);
	ASSERT_TRUE(tree_dft->hasnext());
	ASSERT_EQ(tree_dft->next(), 14);
	ASSERT_FALSE(tree_dft->hasnext());
	ASSERT_THROW(tree_dft->next(), out_of_range);
}

class Test_Stack : public ::testing::Test {
public:
	void SetStack(Stack<int>* stack) {
		for (int i = 1; i <= 5; i++)
			stack->push(i);
	}
};

TEST_F(Test_Stack, Test_isEmpty) {
	Stack<int>* stack = new Stack<int>;
	ASSERT_TRUE(stack->isEmpty());
	ASSERT_EQ(stack->getsize(), 0);

	SetStack(stack);
	ASSERT_FALSE(stack->isEmpty());
	ASSERT_NE(stack->getsize(), 0);
}

TEST_F(Test_Stack, Test_getsize) {
	Stack<int>* stack1 = new Stack<int>;
	ASSERT_EQ(stack1->getsize(), 0);

	SetStack(stack1);
	ASSERT_EQ(stack1->getsize(), 5);
}

TEST_F(Test_Stack, Test_push) {
	Stack<int>* stack1 = new Stack<int>;
	stack1->push(7);
	ASSERT_EQ(stack1->getsize(), 1);
	ASSERT_EQ(stack1->pop(), 7);

	Stack<int>* stack2 = new Stack<int>;
	SetStack(stack2);
	ASSERT_EQ(stack2->getsize(), 5);
	ASSERT_EQ(stack2->pop(), 5);
	ASSERT_EQ(stack2->pop(), 4);
	ASSERT_EQ(stack2->pop(), 3);
	ASSERT_EQ(stack2->pop(), 2);
	ASSERT_EQ(stack2->pop(), 1);
}

TEST_F(Test_Stack, Test_pop) {
	Stack<int>* stack = new Stack<int>;
	ASSERT_THROW(stack->pop(), runtime_error);

	SetStack(stack);
	ASSERT_EQ(stack->pop(), 5);
	ASSERT_EQ(stack->getsize(), 4);
	ASSERT_EQ(stack->pop(), 4);
	ASSERT_EQ(stack->getsize(), 3);
	ASSERT_EQ(stack->pop(), 3);
	ASSERT_EQ(stack->getsize(), 2);
	ASSERT_EQ(stack->pop(), 2);
	ASSERT_EQ(stack->getsize(), 1);
	ASSERT_EQ(stack->pop(), 1);
	ASSERT_TRUE(stack->isEmpty());
}

class Test_Queue : public ::testing::Test {
public:
	void SetQueue(Queue<int>* queue) {
		for (int i = 1; i <= 5; i++)
			queue->enQueue(i);
	}
};

TEST_F(Test_Queue, Test_isEmpty) {
	Queue<int>* queue1 = new Queue<int>;
	ASSERT_TRUE(queue1->isEmpty());
	ASSERT_EQ(queue1->getsize(), 0);

	SetQueue(queue1);
	ASSERT_FALSE(queue1->isEmpty());
	ASSERT_NE(queue1->getsize(), 0);
}

TEST_F(Test_Queue, Test_getsize) {
	Queue<int>* queue1 = new Queue<int>;
	ASSERT_EQ(queue1->getsize(), 0);

	SetQueue(queue1);
	ASSERT_EQ(queue1->getsize(), 5);
}

TEST_F(Test_Queue, Test_enQueue) {
	Queue<int>* queue1 = new Queue<int>;
	queue1->enQueue(7);
	ASSERT_EQ(queue1->getsize(), 1);
	ASSERT_EQ(queue1->deQueue(), 7);

	Queue<int>* queue2 = new Queue<int>;
	SetQueue(queue2);
	ASSERT_EQ(queue2->getsize(), 5);
	ASSERT_EQ(queue2->deQueue(), 1);
	ASSERT_EQ(queue2->deQueue(), 2);
	ASSERT_EQ(queue2->deQueue(), 3);
	ASSERT_EQ(queue2->deQueue(), 4);
	ASSERT_EQ(queue2->deQueue(), 5);
}

TEST_F(Test_Queue, Test_deQueue) {
	Queue<int>* queue1 = new Queue<int>;
	ASSERT_THROW(queue1->deQueue(), runtime_error);

	Queue<int>* queue2 = new Queue<int>;
	SetQueue(queue2);
	ASSERT_EQ(queue2->deQueue(), 1);
	ASSERT_EQ(queue2->getsize(), 4);
	ASSERT_EQ(queue2->deQueue(), 2);
	ASSERT_EQ(queue2->getsize(), 3);
	ASSERT_EQ(queue2->deQueue(), 3);
	ASSERT_EQ(queue2->getsize(), 2);
	ASSERT_EQ(queue2->deQueue(), 4);
	ASSERT_EQ(queue2->getsize(), 1);
	ASSERT_EQ(queue2->deQueue(), 5);
	ASSERT_TRUE(queue2->isEmpty());
}

int main(int argc, char** argv)
{
	::testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();
}