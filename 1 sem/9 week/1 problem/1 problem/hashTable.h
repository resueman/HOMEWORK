#pragma once
#include <string>

struct Set;

///returns load factor of hash-table (the ratio of the number of elements to the number of segments)
int loadFactor(Set* hashTable);

void addToHashTable(Set* hashTable, std::string &str);

Set* createHashTable();

void printHashTable(Set* hashTable);
