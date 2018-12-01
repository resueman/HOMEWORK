#include "tree.h"
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
	std::string result1 = "";
	resultOfTreeBuilding(tree, result1);
	
	if (result1 != "abbbcdefghi")
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

	std::string result3 = "";
	resultOfTreeBuilding(tree, result3);

	if (result3 != "bbbdeh")
	{
		deleteTree(tree);
		return false;
	}
	std::cout << "Test 3 passed\n";*/

	
	
	deleteTree(tree);
	std::cout << "Tests are passed successfully!";
}

int main()
{
	if (!test())
	{
		std::cout << "Tests aren't passed";
		return -1;
	}
	
	return 0;
}