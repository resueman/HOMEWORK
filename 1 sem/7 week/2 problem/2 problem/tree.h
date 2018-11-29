#pragma once

#include <stdio.h>

struct Tree;

Tree* createTree(FILE *file);
Tree* readFromFile(const char* fileName);
void printTree(Tree* tree);
int treeValue(Tree* tree);
void deleteTree(Tree* tree);
