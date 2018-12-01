#include "tree.h"

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
	if (node->key < desiredKey)
	{
		searchKey(node->right, desiredKey);
	}
	else if (node->key > desiredKey)
	{
		searchKey(node->left, desiredKey);
	}
	else if (node->key == desiredKey)
	{
		return node;
	}
	return nullptr;
}

bool exists(Tree* tree, int key)
{
	if (isEmpty(tree))
	{
		return false;
	}
	return searchKey(tree->root, key) != nullptr;
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

void balance(Tree* tree)
{


}

void doAddRecord(Node* node, int newKey, std::string data)
{
	if (node == nullptr)
	{
		node = new Node{ newKey, data };
	}
	else if (newKey > node->key)
	{
		doAddRecord(node->right, newKey, data);
	}
	else if ( newKey < node->key)
	{
		doAddRecord(node->left, newKey, data);
	}
}

void addRecord(Tree* tree, int key, std::string data)
{
	if (isEmpty(tree))
	{
		tree->root = new Node{ key, data };
		return;
	}
	if (exists(tree, key))
	{
		searchKey(tree->root, key)->data = data;//excess tree traversal, include it in doAddRecord?
		return;
	}
	doAddRecord(tree->root, key, data);
	balance(tree);
}

const std::string* getDataByKey(Tree* tree, int key)
{
	if (!exists(tree, key))
	{
		return &emptyString;
	}
	return &searchKey(tree->root, key)->data;
}
