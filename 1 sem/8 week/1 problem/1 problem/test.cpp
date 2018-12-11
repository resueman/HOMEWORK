#include "tree.h"
#include "test.h"
#include <iostream>

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

	bool result1 = getRightChild(tree, 7) == 9 && getLeftChild(tree, 47) == 45
		&& getRightChild(tree, 21) == 47 && getLeftChild(tree, 21) == 7;

	if (!result1)
	{
		deleteTree(tree);
		return false;
	}
	std::cout << "Test 1 passed\n";

	//TEST 2
	bool result2 = getDataByKey(tree, 5) == "c" &&
		getDataByKey(tree, 1) == "a" && getDataByKey(tree, 2) == "bbb" &&
		getDataByKey(tree, 9) == "e" &&	getDataByKey(tree, 7) == "d" &&
		getDataByKey(tree, 45) == "g" && getDataByKey(tree, 89) == "i" &&
		getDataByKey(tree, 21) == "f" && getDataByKey(tree, 47) == "h" &&
		getDataByKey(tree, 3) == "" && getDataByKey(tree, 90) == "" &&
		getDataByKey(tree, 40) == "" &&	getDataByKey(tree, 17) == "";
	
	if (!result2)
	{
		deleteTree(tree);
		return false;
	}
	std::cout << "Test 2 passed\n";

	//TEST 3
	deleteNode(tree, 1);
	deleteNode(tree, 5);
	deleteNode(tree, 21);
	deleteNode(tree, 5);
	deleteNode(tree, 40);
	deleteNode(tree, 47);
	deleteNode(tree, 60);
	deleteNode(tree, 45);

	bool result3 = getRightChild(tree, 46) == 89 && getLeftChild(tree, 46) == 7
		&& getRightChild(tree, 7) == 9 && getLeftChild(tree, 7) == 2;

	if (!result3)
	{
		deleteTree(tree);
		return false;
	}
	std::cout << "Test 3 passed\n"; 

	//TEST 4
	bool result4 = exists(tree, 2) == true && exists(tree, 7) == true &&
		exists(tree, 9) == true && exists(tree, 46) == true &&
		exists(tree, 5) == false && exists(tree, 45) == false &&
		exists(tree, 17) == false && exists(tree, 89) == true &&
		exists(tree, 0) == false;
	
	if(!result4)
	{
		deleteTree(tree);
		return false;
	}
	std::cout << "Test 4 passed\n";
	std::cout << "Tests are passed successfully!";

	deleteTree(tree);
	
	return true;
}
