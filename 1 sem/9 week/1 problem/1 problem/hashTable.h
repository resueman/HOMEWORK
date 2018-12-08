#pragma once
#include <string>

struct Set;

///Create hash-table
Set* createHashTable();

///Delete hash-table
void deleteHashTable(Set* hashTable);

///add word to hash-table
void addToHashTable(Set* hashTable, const std::string &str);

///Print hash-table
void printHashTable(Set* hashTable);

///returns load factor of hash-table (the ratio of the number of elements to the number of segments)
double loadFactor(Set* hashTable);

///Returns average list lenght of bucket
int averageListLength(Set* hashTable);

///Returns maximum list lenght of hash-table
int maxListLength(Set* hashTable);
