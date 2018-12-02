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
bool exists(Tree* tree, int key);

///reurn string by key
std::string getDataByKey(Tree* tree, int key);

///add record by key
void addRecord(Tree* tree, int key, std::string data);

///delete record by key
void deleteNodeByKey(Tree* tree, int key);

///record result(keys) of tree traversal to string
void resultOfTreeBuilding(Tree* tree, std::string &result);

int get(Tree* tree, int desiredKey)