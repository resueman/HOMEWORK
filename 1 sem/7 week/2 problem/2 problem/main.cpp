#define _CRT_SECURE_NO_WARNINGS 

#include "tree.h"
#include <iostream>
#include <fstream>

using namespace std;

Node* createNode(FILE *file)
{
	char symbol;
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
		cout << "File not found";
	}
	Tree* tree = createTree(file);
	fclose(file);
	return tree;
}

void printTree(Tree* tree, Node* node)
{
	if (isEmpty(tree))
	{
		std::cout << "Tree is empty";
		return;
	}
	//std::cout << node->data << "  ";
	if (isOperator(node->data))
	{
		switch (node->data)
		{
		case '+':
			std::cout << "( + ";
			break;
		case '-':
			std::cout << "( - ";
			break;
		case '*':
			std::cout << "( * ";
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
		printf(") ");
	}
}

int main()
{
	Tree* tree = readFromFile("file.txt");
	printTree(tree, tree->root);
	
	return 0;
}