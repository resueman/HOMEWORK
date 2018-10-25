#define _CRT_SECURE_NO_WARNINGS 

#include <stdlib.h> 
#include <utility> 
#include "quick_sort.h"

using namespace std;

void printArr(int* arr, int length)
{
	for (int i = 0; i < length; ++i)
	{
		printf(" %d ", arr[i]);
	}
	printf("\n");
}

int search(int* arr, int length)
{
	int mostFrequent;
	int max = 1;
	int counter = 1;
	for (int i = 1; i < length; ++i)
	{
		if (arr[i] == arr[i - 1])
		{
			counter++;
			if (counter >= max)
			{
				mostFrequent = arr[i - 1];
				max = counter;
			}
		}
		else
		{
			counter = 1;
		}
	}
	return mostFrequent;
}

bool test()
{
	int* arr = new int[10]{ 5, 3, 5, 3, 0, 1, 1, 0, 2, 5 };
	quickSort(arr, 0, 9);
	int mostFrequent = search(arr, 10);
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
	fscanf(file, "%d", &n);
	int* arr = new int [n] {};
	
	int lineNumber = 0;
	while (!feof(file))
	{
		int buffer = 0;
		const int readBytes = fscanf(file, "%d", &buffer);
		if (readBytes < 0) 
		{
			break;
		}
		arr[lineNumber] = buffer;
		lineNumber++;
	}
	fclose(file);
	
	printf("%s", "Original array\n");
	printArr(arr, n);
	quickSort(arr, 0, n - 1);
	printf("%s", "Sorted array\n");
	printArr(arr, n);
	printf("Most common element is  %d\n", search(arr, n));

	delete[] arr;
	return 0;
}