#include "hashTable.h"
#include "list.h"
#include <vector>

using namespace std;

struct Set
{
	int numberOfElements = 0;
	int maxLenghtOfList = 0;
	vector<List*> buckets;
};

void constructor(Set *hashTable)
{
	int size = 10;
	hashTable->buckets.resize(size);
}

Set* createHashTable()
{
	Set* hashTable = new Set;
	constructor(hashTable);
	return hashTable;
}

int hashFunction(string &str)
{
	int hash = 0;
	const int randomNumber = 11;
	for (int i = 0; i < str.size(); ++i)
	{
		hash += hash * randomNumber + str[i];
	}
	return hash;
}

void addToHashTable(Set* hashTable, string &str)
{
	int hash = hashFunction(str) % hashTable->buckets.size();
	addToList(hashTable->buckets[hash], str);
}

int loadFactor(Set* hashTable)
{
	return hashTable->numberOfElements / hashTable->buckets.size();
}

void printHashTable(Set* hashTable)
{
	for (int i = 0; i < hashTable->buckets.size(); ++i)
	{
		printList(hashTable->buckets[i]);
	}
}
