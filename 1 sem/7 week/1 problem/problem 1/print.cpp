#include "print.h"
#include <iostream>

void printDescendingOrder(Set* set, Node* node, std::string &resultStr)
{
	if (isEmpty(set))
	{
		std::cout << "Set is empty";
		return;
	}
	if (node->rightChild != nullptr)
	{
		printDescendingOrder(set, node->rightChild, resultStr);
	}
	resultStr += std::to_string(node->data) + " ";
	if (node->leftChild != nullptr)
	{
		printDescendingOrder(set, node->leftChild, resultStr);
	}
}

void printAscendingOrder(Set* set, Node* node, std::string &resultStr)
{
	if (isEmpty(set))
	{
		std::cout << "Set is empty";
		return;
	}
	if (node->leftChild != nullptr)
	{
		printAscendingOrder(set, node->leftChild, resultStr);
	}
	resultStr += std::to_string(node->data) + " ";
	if (node->rightChild != nullptr)
	{
		printAscendingOrder(set, node->rightChild, resultStr);
	}
}
