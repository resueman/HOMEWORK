#include "tree.h"
#include <iostream>

int main()
{
	Tree* tree = createTree();
	addRecord(tree, 5, "c");
	addRecord(tree, 1, "a");
	addRecord(tree, 2, "b");
	addRecord(tree, 9, "e");
	addRecord(tree, 7, "d");
	addRecord(tree, 89, "g");
	addRecord(tree, 21, "f");
	print(tree);

	deleteTree(tree);
	return 0;
}