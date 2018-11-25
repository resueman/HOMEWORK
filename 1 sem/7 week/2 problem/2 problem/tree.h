#pragma once

struct Node;

struct Tree
{
	Node* root = nullptr;
};

struct Node
{
	char data = 0;
	Node* leftChild = nullptr;
	Node* rightChild = nullptr;
};
///function that creates tree
Tree* createTree();
void addToTree(Tree* tree, const char data);
void addNode(Node* node, const char data);
bool isEmpty(Tree* tree);
bool isOperator(const char symbol);

