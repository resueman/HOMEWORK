/*#include "print.h"
#include "tree.h"
#include <iostream>

void doPrintDescendingOrder(Node* node, std::string &resultStr)
{
	if (node->rightChild != nullptr)
	{
		doPrintDescendingOrder(node->rightChild, resultStr);
	}
	resultStr += std::to_string(node->data) + " ";
	if (node->leftChild != nullptr)
	{
		doPrintDescendingOrder(node->leftChild, resultStr);
	}
}

void printDescendingOrder(Set* set, std::string &resultStr)
{
	if (isEmpty(set))
	{
		std::cout << "Set is empty";
		return;
	}
	doPrintDescendingOrder(set->root, resultStr);
}

void doPrintAscendingOrder(Node* node, std::string &resultStr)
{
	if (node->leftChild != nullptr)
	{
		doPrintAscendingOrder(node->leftChild, resultStr);
	}
	resultStr += std::to_string(node->data) + " ";
	if (node->rightChild != nullptr)
	{
		doPrintAscendingOrder(node->rightChild, resultStr);
	}
}

void printAscendingOrder(Set* set, std::string &resultStr)
{
	if (isEmpty(set))
	{
		std::cout << "Set is empty";
		return;
	}
	doPrintAscendingOrder(set->root, resultStr);
}

*/
