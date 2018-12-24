#define _CRT_SECURE_NO_WARNINGS 

#include <stdlib.h> 
#include <utility> 

using namespace std;

void printArr(int* arr, int length)
{
	for (int i = 0; i < length; ++i)
	{
		printf("%d ", arr[i]);
	}
	printf("\n");
}

int partition(int* arr, int left, int right)
{
	int first = arr[left];
	int i = left + 1;
	for (int j = left + 1; j < right + 1; ++j)
	{
		if (arr[j] <= first)
		{
			swap(arr[j], arr[i]);
			i++;
		}
	}
	swap(arr[left], arr[i - 1]);
	return i - 1;
}

void insertionSort(int* arr, int left, int right)
{
	for (int i = left; i < right; ++i)
	{
		int j = i + 1;
		while ((arr[j] < arr[j - 1]) && (j > 0))
		{
			swap(arr[j], arr[j - 1]);
			j--;
		}
	}
}

void quickSort(int* arr, int left, int right)
{
	if (right > left)
	{
		int pivot = partition(arr, left, right);
		if (right - left + 1 < 10)
		{
			insertionSort(arr, left, right);
		}
		else
		{
			quickSort(arr, left, pivot - 1);
			quickSort(arr, pivot + 1, right);
		}
	}
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

	int n = 0;
	printf("Enter N = ");
	scanf("%d", &n);
	int* arr = new int [n] {};
	for (int i = 0; i < n; ++i)
	{
		arr[i] = (rand() % 20);
	}

	printf("%s", "Original array\n");
	printArr(arr, n);
	quickSort(arr, 0, n - 1);
	printf("%s", "Sorted array\n");
	printArr(arr, n);

	printf("Most common element is  %d\n", search(arr, n));
	delete[] arr;
	return 0;
}