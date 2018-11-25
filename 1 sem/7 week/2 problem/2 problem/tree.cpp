#include "tree.h"
#include <iostream>

void addToTree(Tree* tree, const char data)
{
	if (isEmpty(tree))
	{
		tree->root = new Node{ data, nullptr, nullptr };
	}
	else
	{
		addNode(tree->root, data);
	}
}

bool isOperator(const char symbol)
{
	return symbol == '+' || symbol == '-' || symbol == '*' || symbol == '/';
}

void addNode(Node* node, const char data)
{
	if (node->leftChild != nullptr && isOperator(node->data))
	{
		addNode(node->leftChild, data);
	}
	else
	{
		if (isOperator(node->data))
		{ 
			node->leftChild = new Node{ data, nullptr, nullptr };
			return;
		}
	}

	if (node->rightChild != nullptr && isOperator(node->data))
	{
		addNode(node->rightChild, data);
	}
	else
	{
		if (isOperator(node->data))
		{
			node->rightChild = new Node{ data, nullptr, nullptr };
			return;
		}
	}
}

bool isEmpty(Tree* tree)
{
	return tree->root == nullptr;
}
