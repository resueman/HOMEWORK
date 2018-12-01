#include "tree.h"
#include <iostream>

struct Node;

const std::string emptyString = "";

struct Tree
{
	Node* root = nullptr;
};

struct Node
{
	int key = 0;
	std::string data = "";
	int height = 0;
	Node* left = nullptr;
	Node* right = nullptr;
};

bool isEmpty(Tree* tree)
{
	return tree->root == nullptr;
}

Tree* createTree()
{
	return new Tree;
}

Node* searchKey(Node* node, int desiredKey)//search node by key
{
	if (node == nullptr)
	{
		return nullptr;
	}
	else if (node->key > desiredKey)
	{
		return searchKey(node->left, desiredKey);
	}
	else if (node->key == desiredKey)
	{
		return node;
	}
	else if (node->key < desiredKey)
	{
		return searchKey(node->right, desiredKey);
	}
}

bool exists(Tree* tree, int key)
{
	if (isEmpty(tree))
	{
		return false;
	}
	return searchKey(tree->root, key) != nullptr;
}

int height(Node* node)
{
	if (node == nullptr)
	{
		return 0;
	}
	return node->height;
}

int balanceValue(Node* node)
{
	return height(node->left) - height(node->right);
}

int max(int a, int b)
{
	if (a > b)
	{
		return a;
	}
	return b;
}

int newHeight(Node* node)
{
	return max(height(node->left), height(node->right)) + 1;
}

Node* rightRotate(Node* node)
{
	Node* newHead = node->left;
	node->left = newHead->right;
	newHead->right = node;
	newHeight(newHead);
	newHeight(node);
	return newHead;
}

Node* leftRotate(Node* node)
{
	Node* newHead = node->right;
	node->right = newHead->left;
	newHead->left = node;
	newHeight(newHead);
	newHeight(node);
	return newHead;
}

Node* balance(Node* node)
{
	newHeight(node);
	if (balanceValue(node) == 2)
	{
		if (balanceValue(node->right) < 0)
		{
			node->right = rightRotate(node->right);
		}
		return leftRotate(node);
	}
	if (balanceValue(node) == -2)
	{
		if (balanceValue(node->left) > 0) 
		{
			node->left = leftRotate(node->left);
		}	
		return rightRotate(node);
	}
	return node;
}

Node* doAddRecord(Node* node, int newKey, std::string data)
{
	if (node == nullptr)
	{
		return node = new Node{ newKey, data };
	}
	else if (newKey > node->key)
	{
		node->right = doAddRecord(node->right, newKey, data);
	}
	else if ( newKey < node->key)
	{
		node->left = doAddRecord(node->left, newKey, data);
	}
	else if (newKey == node->key)
	{
		node->data = data;
		return node;
	}
	return balance(node);
}

void addRecord(Tree* tree, int key, std::string data)
{
	if (isEmpty(tree))
	{
		tree->root = new Node{ key, data };
		return;
	}
	doAddRecord(tree->root, key, data);
}

const std::string getDataByKey(Tree* tree, int key)
{
	if (!exists(tree, key))
	{
		return emptyString;
	}
	return searchKey(tree->root, key)->data;
}

void doDeleteTree(Node* node)
{
	if (node->left != nullptr)
	{
		doDeleteTree(node->left);
	}
	if (node->right != nullptr)
	{
		doDeleteTree(node->right);
	}
	delete node;
}

void deleteTree(Tree* tree)
{
	if (!isEmpty(tree))
	{
		doDeleteTree(tree->root);
	}
	delete tree;
}

/*void doDeleteRecord(Node* node)
{

}

void deleteRecord(Tree* tree, int key)
{
	if (exists(tree, key))
	{
		doDeleteRecord(searchKey(tree->root, key));
	}
}*/

void build(Node* node, std::string &result)
{
	if (node->left != nullptr)
	{
		build(node->left, result);
	}
	result += node->data;
	if (node->right != nullptr)
	{
		build(node->right, result);
	}
}

void resultOfTreeBuilding(Tree* tree, std::string &result)
{
	if (isEmpty(tree))
	{
		return;
	}
	build(tree->root, result);
}