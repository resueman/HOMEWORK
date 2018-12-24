#include "tree.h"
#include "test.h"
#include <iostream>

int main()
{
	if (!test())
	{
		std::cout << "Program doesn't work";
		return -1;
	}
	
	Tree* tree = readFromFile("file.txt");
	printTree(tree);
	std::cout << std::endl;
	std::cout << treeValue(tree);
	deleteTree(tree);

	return 0;
}
