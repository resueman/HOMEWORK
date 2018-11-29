#include "tree.h"
#include <iostream>

int main()
{
	Tree* tree = readFromFile("file.txt");
	printTree(tree);
	std::cout << std::endl;
	std::cout << treeValue(tree);
	deleteTree(tree);
	return 0;
}
