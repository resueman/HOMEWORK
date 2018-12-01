#pragma once

#include <string>

struct Tree;

///
bool isEmpty(Tree* tree);

///
Tree* createTree();

///
void deleteRecord(Tree* tree, int key);

///
void addRecord(Tree* tree, int key, std::string data);

///
std::string* getDataByKey(Tree* tree, int key);

///
void deleteTree(Tree* tree);
