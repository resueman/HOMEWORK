#include "tree.h"
#include <string>//////////
#include <iostream>////////
struct Node
{
	int data = 0;
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
			node->leftChild = new Node{ data, nullptr, nullptr };
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
			node->rightChild = new Node{ data, nullptr, nullptr };
		}
	}
}

bool addToSet(Set* set, int const data)
{
	if (isEmpty(set))
	{
		set->root = new Node{ data, nullptr, nullptr };
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
				return true;
			}
		}
	}
}

int maximum(Node* current)
{
	auto* temp = current;
	temp = temp->leftChild;
	while (temp->rightChild != nullptr)
	{
		temp = temp->rightChild;
	}
	return temp->data;
}

void removeNode(Node*& current, int const data)
{
	if (current->data > data)
	{
		removeNode(current->leftChild, data);
	}
	else if (current->data < data)
	{
		removeNode(current->rightChild, data);
	}
	else
	{
		if (current->leftChild == nullptr && current->rightChild == nullptr)
		{
			auto* temp = current;
			current = nullptr;
			delete temp;
			return;
		}
		else if (current->leftChild == nullptr && current->rightChild != nullptr)
		{
			auto* temp = current;
			current = current->rightChild;
			delete temp;
			return;
		}
		else if (current->leftChild != nullptr && current->rightChild == nullptr)
		{
			auto* temp = current;
			current = current->leftChild;
			delete temp;
			return;
		}
		else
		{
			current->data = maximum(current);
			removeNode(current->leftChild, current->data);
		}
	}
}

bool removeFromSet(Set* set, int const data)
{
	if (!exists(set, data))
	{
		return false;
	}
	else
	{
		removeNode(set->root, data);
	}
	return true;
}

bool isEmpty(Set* set)
{
	return set->root == nullptr;
}
/////////////////////////////////////////////////////////////////////
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

