#include "tree.h"

struct Node
{
	int data = 0;
	Node* leftChild;
	Node* rightChild;
};

struct Set
{
	Node* root;
};

Set* createSet()
{
	return new Set;
}

void deleteSet(Set* set, Node* node)
{
	if (isEmpty(set))
	{
		return;
	}
	else
	{
		if (node->leftChild != nullptr)
		{
			deleteSet(set, node->leftChild);
		}
		if (node->rightChild != nullptr)
		{
			deleteSet(set, node->rightChild);
		}
		delete node;
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
		if(!exists(set, data))
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

bool isEmpty(Set* set)
{
	return set->root == nullptr;
}