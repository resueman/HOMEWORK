#include "tree.h"
#include <iostream>

struct Tree
{
	Node* root = nullptr;
};

int main()
{
	Tree* tree = readFromFile("file.txt");
	printTree(tree, tree->root);
	std::cout << std::endl;
	std::cout << treeValue(tree);
	deleteTree(tree, tree->root);
	
	return 0;
}