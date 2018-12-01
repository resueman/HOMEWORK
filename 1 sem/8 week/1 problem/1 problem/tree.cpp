#include "tree.h"

struct Node;

struct Tree
{
	Node* root = nullptr;
};

struct Node
{
	int key = 0;
	std::string data = "";
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

bool exists(Node* node, int key)
{

}

void deleteRecord(Tree* tree, int key)
{
	if (!exists(tree->root, key))
	{
		return;
	}



}

void addRecord(Tree* tree, int key, std::string data)
{
	if(exists(tree->root, key))
	{
	
		return;
	}



}

std::string* getDataByKey(Tree* tree, int key)
{

}

void doDeleteTree(Node* node)
{

}

void deleteTree(Tree* tree)
{
	if (!isEmpty(tree))
	{
		doDeleteTree(tree->root);
	}
	delete tree;
}

