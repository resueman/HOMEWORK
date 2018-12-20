#pragma once

#include <string>

struct Tree;

///if tree is empty function returns true, else returns false
bool isEmpty(Tree* tree);

///create tree
Tree* createTree();

///delete tree
void deleteTree(Tree* tree);

///check existence of record by key
bool exists(Tree* tree, const int key);

///reurn string by key
std::string getDataByKey(Tree* tree, const int key);

///add record by key
void addRecord(Tree* tree, const int key, const std::string &data);

///delete record by key
void deleteNode(Tree* tree, const int key);

///reuturn key, which belongs to right child 
int getRightChild(Tree* tree, const int key);

///reuturn key, which belongs to left child 
int getLeftChild(Tree* tree, const int key);
