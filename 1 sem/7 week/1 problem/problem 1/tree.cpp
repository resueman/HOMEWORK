#include "tree.h"

#include <iostream>

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
		delete set;
		return;
	}
	doDeleteSet(set->root);
	delete set;
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

void deleteNoChildren(Node*& current)
{
	auto* temp = current;
	current = nullptr;
	delete temp;
}

void deleteNoLeftChild(Node*& current)
{
	auto* temp = current;
	current = current->rightChild;
	delete temp;
}

void deleteNoRightChild(Node*& current)
{
	auto* temp = current;
	current = current->leftChild;
	delete temp;
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
			deleteNoChildren(current);
		}
		else if (current->leftChild == nullptr && current->rightChild != nullptr)
		{
			deleteNoLeftChild(current);
		}
		else if (current->leftChild != nullptr && current->rightChild == nullptr)
		{
			deleteNoRightChild(current);
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

std::string printDescendingOrder(Set* set)
{
	if (isEmpty(set))
	{
		return "Set is empty";
	}
	std::string resultStr = "";
	doPrintDescendingOrder(set->root, resultStr);
	return resultStr;
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

std::string printAscendingOrder(Set* set)
{
	if (isEmpty(set))
	{
		return  "Set is empty";
	}
	std::string resultStr = "";
	doPrintAscendingOrder(set->root, resultStr);
	return resultStr;
}
