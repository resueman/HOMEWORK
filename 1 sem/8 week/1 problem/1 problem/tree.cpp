#include "tree.h"
#include <iostream>

struct Node;

struct Tree
{
	Node* root = nullptr;
};

struct Node
{
	int key = 0;
	std::string data = "";
	int height = 1;
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

std::string doGetDataByKey(Node* node, int desiredKey)
{
	if (node == nullptr)
	{
		return "";
	}
	else if (node->key > desiredKey)
	{
		return doGetDataByKey(node->left, desiredKey);
	}
	else if (node->key < desiredKey)
	{
		return doGetDataByKey(node->right, desiredKey);
	}
	else
	{
		return node->data;
	}
}

std::string getDataByKey(Tree* tree, int key)
{
	return doGetDataByKey(tree->root, key);
}

bool exists(Tree* tree, int key)
{
	return getDataByKey(tree, key) != "";
}

int max(int a, int b)
{
	if (a > b)
	{
		return a;
	}
	return b;
}

int height(Node* node)
{
	if (node == nullptr)
	{
		return 0;
	}
	return node->height;
}

void newHeight(Node* node)
{
	node->height = max(height(node->left), height(node->right)) + 1;
}

int balanceValue(Node* node)
{
	return height(node->right) - height(node->left);
}

Node* rightRotate(Node* node, Tree* tree)
{
	if (tree->root == node)
	{
		tree->root = node->left;
	}
	Node* newHead = node->left;
	node->left = newHead->right;
	newHead->right = node;
	newHeight(node);
	newHeight(newHead);
	return newHead;
}

Node* leftRotate(Node* node, Tree* tree)
{
	if (tree->root == node)
	{
		tree->root = node->right;
	}
	Node* newHead = node->right;
	node->right = newHead->left;
	newHead->left = node;
	newHeight(node);
	newHeight(newHead);
	return newHead;
}

Node* balance(Node* node, Tree* tree)
{
	newHeight(node);
	if (balanceValue(node) == 2)
	{
		if (balanceValue(node->right) < 0)
		{
			node->right = rightRotate(node->right, tree);
		}
		return leftRotate(node, tree);
	}
	if (balanceValue(node) == -2)
	{
		if (balanceValue(node->left) > 0) 
		{
			node->left = leftRotate(node->left, tree);
		}	
		return rightRotate(node, tree);
	}
	return node;
}

Node* doAddRecord(Node* node, int newKey, std::string data, Tree* tree)
{
	if (node == nullptr)
	{
		return node = new Node{ newKey, data };
	}
	else if (newKey > node->key)
	{
		node->right = doAddRecord(node->right, newKey, data, tree);
	}
	else if ( newKey < node->key)
	{
		node->left = doAddRecord(node->left, newKey, data, tree);
	}
	else
	{
		node->data = data;
		return node;
	}
	return balance(node, tree);
}

void addRecord(Tree* tree, int key, std::string data)
{
	if (isEmpty(tree))
	{
		tree->root = new Node{ key, data };
		return;
	}
	doAddRecord(tree->root, key, data, tree);
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

void doDeleteNode(Node* node, int key)
{
	
}

void deleteNodeByKey(Tree* tree, int key)
{
	if (isEmpty(tree))
	{
		return;
	}
	doDeleteNode(tree->root, key);
}

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
