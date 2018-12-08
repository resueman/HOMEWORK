#pragma once

struct Set;

///returns load factor of hash-table (the ratio of the number of elements to the number of segments)
int loadFactor();

void addToHashTable(Set* hashTable, string &str);

Set* createHashTable();
