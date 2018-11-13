#define _CRT_SECURE_NO_WARNINGS 

#include <stdio.h> 
#include "quickSort.h"

void printData(int* arrayOfData, int length)
{
	for (int i = 0; i < length; ++i)
	{
		printf(" %d ", arrayOfData[i]);
	}
	printf("\n");
}

int searchMostFrequentElement(int* arr, int length)
{
	int mostFrequent = -111;
	int maxNumberOfRepet = 1;
	int counter = 1;
	for (int i = 1; i < length; ++i)
	{
		if (arr[i] == arr[i - 1])
		{
			counter++;
			if (counter >= maxNumberOfRepet)
			{
				mostFrequent = arr[i - 1];
				maxNumberOfRepet = counter;
			}
		}
		else
		{
			counter = 1;
		}
	}
	return mostFrequent;
}

int* getDataFromFile(FILE* file, int &n)
{
	fscanf(file, "%d", &n);
	int* arrayOfData = new int [n] {};

	int lineNumber = 0;
	while (!feof(file))
	{
		int buffer = 0;
		const int readBytes = fscanf(file, "%d", &buffer);
		if (readBytes < 0)
		{
			break;
		}
		arrayOfData[lineNumber] = buffer;
		lineNumber++;
	}
	fclose(file);
	return arrayOfData;
}

bool test()
{
	int* arr = new int[10]{ 5, 3, 5, 3, 0, 1, 1, 0, 2, 5 };
	quickSort(arr, 0, 9);
	int mostFrequent = searchMostFrequentElement(arr, 10);
	delete[] arr;
	return mostFrequent == 5;
}

int main()
{
	if (!test())
	{
		printf("%s", "Program doesn't work");
		return 1;
	}
	FILE *file = fopen("test.txt", "r");
	if (!file)
	{
		printf("file not found!");
		return 1;
	}
	int n = 0;
	int* arrayOfData = getDataFromFile(file, n);
	printf("%s", "Original array\n");
	printData(arrayOfData, n);
	quickSort(arrayOfData, 0, n - 1);
	printf("%s", "Sorted array\n");
	printData(arrayOfData, n);
	printf("Most common element is  %d\n", searchMostFrequentElement(arrayOfData, n));

	delete[] arrayOfData;
	return 0;
}