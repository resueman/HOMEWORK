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

///////// G E T   D A T A   B Y   K E Y /////////
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

///////// E X I S T E N C E /////////
bool exists(Tree* tree, int key)
{
	return getDataByKey(tree, key) != "";
}

///////// B A L A N C E /////////
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

///////// A D D   R E C O R D /////////
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

///////// D E L E T E    W H O L E   T R E E /////////
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
	tree = nullptr;
}

///////// G E T   C H I L D'S   K E Y  ( R I G H T   O R   L E F T) /////////
int doGetLeftChild(Node* node)
{
	return node->left->key;
}

int doGetRightChild(Node* node)
{
	return node->right->key;
}

Node* getOwner(Node* node, int desiredKey)
{
	if (node->key > desiredKey)
	{
		return getOwner(node->left, desiredKey);
	}
	else if (node->key < desiredKey)
	{
		return getOwner(node->right, desiredKey);
	}
	else
	{
		return node;
	}
}

int getRightChild(Tree* tree, int key)
{
	return doGetRightChild(getOwner(tree->root, key));
}

int getLeftChild(Tree* tree, int key)
{
	return doGetLeftChild(getOwner(tree->root, key));
}

/////////  D E L E T E    N O D E   B Y   K E Y  /////////
Node* findMinKey(Node* node)
{
	if (node->left == nullptr)
	{
		return node;
	}
	return findMinKey(node->left);
}

Node* deleteMinKey(Node* node, Tree* tree)
{
	if (node->left == nullptr)
	{
		return node->right;
	}
	node->left = deleteMinKey(node->left, tree);
	return balance(node, tree);
}

Node* doDeleteNode(Node* node, int key, Tree* tree)
{
	if (node == nullptr)
	{
		return nullptr;
	}
	if (key < node->key)
	{
		node->left = doDeleteNode(node->left, key, tree);
	}
	else if (key > node->key)
	{
		node->right = doDeleteNode(node->right, key, tree);
	}
	else
	{
		Node* leftSubTree = node->left;
		Node* rightSubTree = node->right;

		if (rightSubTree == nullptr)
		{
			delete node;
			return leftSubTree;
		}

		Node* min = findMinKey(rightSubTree);
		if (tree->root == node)
		{
			tree->root = min;
		}
		delete node;

		min->right = deleteMinKey(rightSubTree, tree);
		min->left = leftSubTree;
		return balance(min, tree);
	}
	return balance(node, tree);
}

void deleteNode(Tree* tree, int key)
{
	if (isEmpty(tree))
	{
		return;
	}
	if (!exists(tree, key))
	{
		return;
	}		
	doDeleteNode(tree->root, key, tree);
}
