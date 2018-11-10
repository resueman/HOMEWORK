#define _CRT_SECURE_NO_WARNINGS

#include <stdlib.h>
#include <utility>
#include <conio.h>
using namespace std;

void printArr(int* arr, int length)
{
	for (int i = 0; i < length; ++i)
	{
		printf("%d ", arr[i]);
	}
	printf("\n");
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
		while ((arr[j] < arr[j - 1]) && (j > left))
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
		if (right - left + 1 < 10)
		{
			insertionSort(arr, left, right);
		}
		else
		{
			int pivot = partition(arr, left, right);
			quickSort(arr, left, pivot - 1);
			quickSort(arr, pivot + 1, right);
		}
	}
}

bool binarySearch(int* arr, int left, int right, int desireK)
{
	const int middle = (left + right) / 2;
	if (right >= left) 
	{	
		if (desireK > arr[middle]) 
		{
			return binarySearch(arr, middle + 1, right, desireK);
		}
		else
		{
			if (desireK < arr[middle])
			{
				return binarySearch(arr, left, middle - 1, desireK);
			}
			else
			{
				return true;
			}
		}
	}
	else
	{
		return false;
	}
}

int test()
{
	int* arrN = new int[10] {18, 24, 19, 1, 3, 5, 9, 15, 4, 18};
	int* arrK = new int[8] {1, 4, 6, 7, 18, 19, 20, 24};
	int* checkArr = new int[8]{1, 1, 0, 0, 1, 1, 0, 1};
	quickSort(arrN, 0, 9);
	for (int i = 0; i < 8; ++i)
	{
		arrK[i] = binarySearch(arrN, 0, 9, arrK[i]);
	}
	delete[] arrN;
	int i = 0;
	while ((arrK[i] == checkArr[i]) && (i < 8))
	{
		i++;
	}
	delete[] arrK;
	delete[] checkArr;
	return i == 8;
}

int main()
{
	if (!test())
	{
		printf("Program doesn't work");
		return 1;
	}

	int n = 0;
	int k = 0;
	printf("%s", "Enter N  =  ");
	scanf("%d", &n);
	printf("%s", "Enter K  =  ");
	scanf("%d", &k);

	int* arr = new int[n] {};
	for (int i = 0; i < n; ++i)
	{
		arr[i] = rand() % 30;
	}
	printf("%s", "**Original array**\n");
	printArr(arr, n);
	quickSort(arr, 0, n - 1);
	printf("%s", "**Sorted array**\n");
	printArr(arr, n);

	for (int i = 0; i < k; ++i)
	{
		int current = rand() % 30;
		if (binarySearch(arr, 0, n - 1, current))
		{
			printf("%d.  %d is found\n", i, current);
		}
		else
		{
			printf("%d.  %d not found\n", i, current);
		}
	}
	_getch();
	delete[] arr;
	return 0;
}
