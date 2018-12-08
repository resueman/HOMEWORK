#include "hashTable.h"
#include "list.h"
#include <vector>

struct Set
{
	int numberOfElements = 0;
	std::vector<List*> buckets;
};

void constructor(Set *hashTable)
{
	int size = 20;
	hashTable->buckets.resize(size);
}

Set* createHashTable()
{
	Set* hashTable = new Set;
	constructor(hashTable);
	return hashTable;
}

void deleteHashTable(Set* hashTable)
{
	for (int i = 0; i < hashTable->buckets.size(); ++i)
	{
		deleteList(hashTable->buckets[i]);
	}
	delete hashTable;
}

int hashFunction(const std::string &str)
{
	int hash = 0;
	int randomNumber1 = 11;
	int randomNumber2 = 27;
	int randomNumber3 = 35;
	for (int i = 0; i < str.size(); ++i)
	{
		hash += hash * randomNumber1 * randomNumber2 * randomNumber3 + str[i];
		randomNumber1 += randomNumber1 * randomNumber2;
	}
	return hash;
}

void addToHashTable(Set* hashTable, const std::string &str)
{
	int hash = hashFunction(str) % hashTable->buckets.size();
	addToList(hashTable->buckets[hash], str, hashTable->numberOfElements);
}

void printHashTable(Set* hashTable)
{
	for (int i = 0; i < hashTable->buckets.size(); ++i)
	{
		printList(hashTable->buckets[i]);
	}
}

double loadFactor(Set* hashTable)
{
	return 1.0 * hashTable->numberOfElements / hashTable->buckets.size();
}

int averageListLength(Set* hashTable)
{
	int lenghtSum = 0;
	for (int i = 0; i < hashTable->buckets.size(); ++i)
	{
		if (hashTable->buckets[i] != nullptr)
		{
			lenghtSum += getListLenght(hashTable->buckets[i]);
		}
	}
	return lenghtSum / hashTable->numberOfElements;
}

int maxListLength(Set* hashTable)
{
	int maxListLenght = 0;
	for (int i = 0; i < hashTable->buckets.size(); ++i)
	{
		if (hashTable->buckets[i] != nullptr)
		{
			int currentLenght = getListLenght(hashTable->buckets[i]);
			if (currentLenght > maxListLenght)
			{
				maxListLenght = currentLenght;
			}
		}
	}
	return maxListLenght;
}
