#pragma once

struct Tree;
struct Node;

Tree* readFromFile(const char* fileName);
void printTree(Tree* tree, Node* node);
int treeValue(Tree* tree);
int calculation(Tree* tree, Node* node);
bool isEmpty(Tree* tree);
bool isOperator(char symbol);
void deleteTree(Tree* tree, Node* node);
