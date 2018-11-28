#define _CRT_SECURE_NO_WARNINGS 

#include "tree.h"
#include <iostream>
#include <fstream>

//Tree* createTree(FILE *file);
//Node* createNode(FILE *file);

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

bool isEmpty(Tree* tree)
{
	return tree->root == nullptr;
}

Node* createNode(FILE *file)
{
	char symbol = ' ';
	Node* newNode = new Node{};
	fscanf(file, "%c", &symbol);
	if (symbol == '(')
	{
		fscanf(file, "%c", &symbol);
		newNode->data = symbol;
		newNode->leftChild = createNode(file);
		newNode->rightChild = createNode(file);
		fscanf(file, "%c", &symbol);
	}
	else if (isdigit(symbol))
	{
		newNode->data = symbol;
	}
	return newNode;
}

Tree* createTree(FILE *file)
{
	return new Tree{ createNode(file) };
}

Tree* readFromFile(const char* fileName)
{
	FILE *file = fopen(fileName, "r");
	if (!file)
	{
		std::cout << "File not found";
	}
	Tree* tree = createTree(file);
	fclose(file);
	return tree;
}

bool isOperator(char symbol)
{
	return symbol == '+' || symbol == '-' || symbol == '*' || symbol == '/';
}

void printTree(Tree* tree, Node* node)
{
	if (isEmpty(tree))
	{
		std::cout << "Tree is empty";
		return;
	}
	if (isOperator(node->data))
	{
		switch (node->data)
		{
		case '+':
			std::cout << "(+ ";
			break;
		case '-':
			std::cout << "(- ";
			break;
		case '*':
			std::cout << "(* ";
			break;
		case '/':
			std::cout << " (/ ";
			break;
		}
	}
	else
	{
		std::cout << node->data << " ";
	}
	if (node->leftChild != nullptr)
	{
		printTree(tree, node->leftChild);
	}
	if (node->rightChild != nullptr)
	{
		printTree(tree, node->rightChild);
		std::cout << ") ";
	}
}

int calculation(Tree* tree, Node* node)
{
	switch (node->data)
	{
	case '+':
		return calculation(tree, node->leftChild) + calculation(tree, node->rightChild);
		break;
	case '-':
		return calculation(tree, node->leftChild) - calculation(tree, node->rightChild);
		break;
	case '*':
		return calculation(tree, node->leftChild) * calculation(tree, node->rightChild);
		break;
	case '/':
		return calculation(tree, node->leftChild) / calculation(tree, node->rightChild);
		break;
	}
	return node->data - '0';
}

int treeValue(Tree* tree)
{
	if (isEmpty(tree))
	{
		std::cout << "Tree is empty";
		return 0;
	}
	return calculation(tree, tree->root);
}

void deleteTree(Tree* tree, Node* node)
{
	if (isEmpty(tree))
	{
		return;
	}
	else
	{
		if (node->leftChild != nullptr)
		{
			deleteTree(tree, node->leftChild);
		}
		if (node->rightChild != nullptr)
		{
			deleteTree(tree, node->rightChild);
		}
		delete node;
	}
}