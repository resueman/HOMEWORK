#pragma once

struct Tree;
struct Node;

Tree* createTree(FILE *file);
Tree* readFromFile(const char* fileName);
void printTree(Tree* tree, Node* node);
int treeValue(Tree* tree);
void deleteTree(Tree* tree, Node* node);
