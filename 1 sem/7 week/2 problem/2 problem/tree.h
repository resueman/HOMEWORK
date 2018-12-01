#pragma once

#include <stdio.h>

struct Tree;

///creates tree
Tree* createTree(FILE *file);

///reads data from file, builds a tree
Tree* readFromFile(const char* fileName);

///prints tree's elements
void printTree(Tree* tree);

///calculates value of expression by tree traversal
int treeValue(Tree* tree);

///removes tree
void deleteTree(Tree* tree);
