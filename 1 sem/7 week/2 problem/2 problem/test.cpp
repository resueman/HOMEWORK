#include "tree.h"
#include "test.h"
#include <iostream>

bool test()
{
	Tree* tree1 = readFromFile("test1.txt");
	int result1 = treeValue(tree1);
	deleteTree(tree1);

	Tree* tree2 = readFromFile("test2.txt");
	int result2 = treeValue(tree2);
	deleteTree(tree2);

	Tree* tree3 = readFromFile("test3.txt");
	int result3 = treeValue(tree3);
	deleteTree(tree3);

	Tree* tree4 = readFromFile("test4.txt");
	int result4 = treeValue(tree4);
	deleteTree(tree4);

	system("cls");

	return result1 == 0 && result2 == -230 && result3 == 99 && result4 == -883;
}
