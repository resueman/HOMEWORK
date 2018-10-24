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

bool test()
{
	int* arr = new int[25]{-15, 39, -26, 4, 7, -15, 17, -4, 48, 3, 2, 14, -28, -26, 18, 42, 47, 3, 1, 39, 38, 41, -10, 12, 6};
	int* sortArr = new int[25]{-28, -26, -26, -15, -15, -10, -4, 1, 2, 3, 3, 4, 6, 7, 12, 14, 17, 18, 38, 39, 39, 41, 42, 47, 48};
	quickSort(arr, 0, 24);
	int i = 0;
	while ((arr[i] == sortArr[i]) && (i < 26))
	{
		i++;
	}
	delete[] arr;
	delete[] sortArr;
	return i == 26;
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
		arr[i] = (rand() % 50) - 10;
	}

	printArr(arr, n);
	quickSort(arr, 0, n - 1);
	printArr(arr, n);
	
	return 0;
}
