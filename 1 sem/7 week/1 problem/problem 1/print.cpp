#include "print.h"
#include <iostream>

void printAscendingOrder(Set* set, Node* node)
{
	if (isEmpty(set))
	{
		std::cout << "Set is empty";
		return;
	}
	if (node->rightChild != nullptr)
	{
		printAscendingOrder(set, node->rightChild);
	}
	std::cout << node->data << "  ";
	if (node->leftChild != nullptr)
	{
		printAscendingOrder(set, node->leftChild);
	}
}

void printDescendingOrder(Set* set, Node* node)
{
	if (isEmpty(set))
	{
		std::cout << "Set is empty";
		return;
	}
	if (node->leftChild != nullptr)
	{
		printDescendingOrder(set, node->leftChild);
	}
	std::cout << node->data << "  ";
	if (node->rightChild != nullptr)
	{
		printDescendingOrder(set, node->rightChild);
	}
}
