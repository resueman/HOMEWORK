#include "tree.h"
#include "test.h"
#include <iostream>

int GetLeftChild(Node* node)
{
	return node->left->data;
}

int GetRightChild(Node* node)
{
	return node->right->data;
}

Node* getOwner(Tree* tree, int desiredKey)
{
	if (node->key > desiredKey)
	{
		return getLeftChild(node->left, desiredKey);
	}
	else if (node->key < desiredKey)
	{
		return getLeftChild(node->right, desiredKey);
	}
	else
	{
		return node;
	}
}

int get(Tree* tree, int desiredKey)
{
	getOwner(tree->root, desiredKey);
}

bool test()
{
	//TEST 1
	Tree* tree = createTree();
	addRecord(tree, 5, "c");
	addRecord(tree, 1, "a");
	addRecord(tree, 2, "b");
	addRecord(tree, 9, "e");
	addRecord(tree, 7, "d");
	addRecord(tree, 2, "bb");
	addRecord(tree, 89, "i");
	addRecord(tree, 21, "f");
	addRecord(tree, 45, "g");
	addRecord(tree, 2, "bbb");
	addRecord(tree, 47, "h");
	addRecord(tree, 60, "j");
	addRecord(tree, 46, "h");
	std::string result1 = "";
	
	//bool result1 = getRightChild(getOwner(tree, 7)) == 9 && getLeftChild(getOwner(tree, 47)) == 45 && tree->root->key == 21
		//&& getRightChild(getOwner(tree, 21)) == 47 && getLeftChild(getOwner(tree, 21)) == 7;

	if (!result1)
	{
		deleteTree(tree);
		return false;
	}
	std::cout << "Test 1 passed\n";

	//TEST 2
	if (!(getDataByKey(tree, 5) == "c" &&
		getDataByKey(tree, 1) == "a" &&
		getDataByKey(tree, 2) == "bbb" &&
		getDataByKey(tree, 9) == "e" &&
		getDataByKey(tree, 7) == "d" &&
		getDataByKey(tree, 45) == "g" &&
		getDataByKey(tree, 89) == "i" &&
		getDataByKey(tree, 21) == "f" &&
		getDataByKey(tree, 47) == "h" &&
		getDataByKey(tree, 3) == "" &&
		getDataByKey(tree, 90) == "" &&
		getDataByKey(tree, 40) == "" &&
		getDataByKey(tree, 17) == ""))
	{
		deleteTree(tree);
		return false;
	}
	std::cout << "Test 2 passed\n";

	//TEST 3
	/*
	deleteRecord(tree, 89);
	deleteRecord(tree, 45);
	deleteRecord(tree, 17);
	deleteRecord(tree, 5);
	deleteRecord(tree, 40);
	deleteRecord(tree, 21);
	deleteRecord(tree, 5);
	
	bool result3 =  
	if (!result3)
	{
		deleteTree(tree);
		return false;
	}
	std::cout << "Test 3 passed\n";

	//TEST 4
	if (!(exists(tree, 2) == true &&
		exists(tree, 7) == true &&
		exists(tree, 9) == true &&
		exists(tree, 47) == true &&
		exists(tree, 5) == false &&
		exists(tree, 45) == false &&
		exists(tree, 17) == false &&
		exists(tree, 89) == false &&
		exists(tree, 0) == false))
	{
		deleteTree(tree);
		return false;
	}
	std::cout << "Test 4 passed\n";

	std::cout << "Tests are passed successfully!";*/
	deleteTree(tree);
	return true;
}
