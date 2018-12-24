#include "tree.h"
#include <iostream>

struct Node
{
	int data = 0;
	int reiterations = 1;
	Node* leftChild = nullptr;
	Node* rightChild = nullptr;
};

struct Set
{
	Node* root = nullptr;
};

Set* createSet()
{
	return new Set;
}

void doDeleteSet(Node* node)
{
	if (node->leftChild != nullptr)
	{
		doDeleteSet(node->leftChild);
	}
	if (node->rightChild != nullptr)
	{
		doDeleteSet(node->rightChild);
	}
	delete node;
}

void deleteSet(Set* set)
{
	if (isEmpty(set))
	{
		return;
	}
	doDeleteSet(set->root);
	delete set;
	set = nullptr;
}

void addNode(Node* node, int const data)
{
	if (node->data > data)
	{
		if (node->leftChild != nullptr)
		{
			addNode(node->leftChild, data);
		}
		else
		{
			node->leftChild = new Node{ data, 1, nullptr, nullptr };
		}
	}
	else
	{
		if (node->rightChild != nullptr)
		{
			addNode(node->rightChild, data);
		}
		else
		{
			node->rightChild = new Node{ data, 1, nullptr, nullptr };
		}
	}
}

bool addToSet(Set* set, int const data)
{
	if (isEmpty(set))
	{
		set->root = new Node{ data, 1, nullptr, nullptr };
	}
	else
	{
		if (!exists(set, data))
		{
			addNode(set->root, data);
		}
		else
		{
			return false;
		}
	}
	return true;
}

bool exists(Set* set, int const data)
{
	if (isEmpty(set))
	{
		return false;
	}
	else
	{
		auto temp = set->root;
		while (true)
		{
			if (data < temp->data)
			{
				if (temp->leftChild != nullptr)
				{
					temp = temp->leftChild;
				}
				else
				{
					return false;
				}
			}
			else if (data > temp->data)
			{
				if (temp->rightChild != nullptr)
				{
					temp = temp->rightChild;
				}
				else
				{
					return false;
				}
			}
			else
			{
				++temp->reiterations;
				return true;
			}
		}
	}
}

bool isEmpty(Set* set)
{
	return set->root == nullptr;
}

void doPrintAscendingOrder(Node* node)
{
	if (node->leftChild != nullptr)
	{
		doPrintAscendingOrder(node->leftChild);
	}
	std::cout << node->data << " - " << node->reiterations << std::endl;
	if (node->rightChild != nullptr)
	{
		doPrintAscendingOrder(node->rightChild);
	}
}

void printAscendingOrder(Set* set)
{
	if (isEmpty(set))
	{
		return;
	}
	doPrintAscendingOrder(set->root);
}
