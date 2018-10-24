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
	printf("\n");
}

void randomArr(int* arr, int n)
{
	for (int i = 0; i < n; ++i)
	{
		arr[i] = (rand() % 10) - 5;
	}
}

void bubbleSort(int* arr, int n)
{
	for (int i = 0; i < n - 1; ++i)
	{
		for (int j = 0; j < n - i - 1; ++j)
		{
			if (arr[j] > arr[j + 1])
			{
				swap(arr[j], arr[j + 1]);
			}
		}
	}
}

void countingSort(int* arr, int n)
{
	int min = arr[0];
	int max = arr[0];
	for (int i = 1; i < n; ++i)
	{
		if (arr[i] < min)
		{
			min = arr[i];
		}
		
		if (arr[i] > max)
		{
			max = arr[i];
		}
	}

	int* countArr = new int[max - min + 1] {};
	for (int i = 0; i < n; ++i) 
	{
		countArr[arr[i] - min]++;
	}
	
	int i = 0;
	for (int j = 0; j < max - min + 1; j++) 
	{
		while (countArr[j] != 0) 
		{
			arr[i] = j + min;
			countArr[j]--;
			i++;
		}
	}
	delete[] countArr;
}

bool test() 
{
	int* arrBubble = new int[10]{4, 9, 7, 1, -3, 7, 1, -3, 7, 0};
	int* arrCounting = new int[10]{ 4, 9, 7, 1, -3, 7, 1, -3, 7, 0 };
	int* sortArr = new int[10]{-3, -3, 0, 1, 1, 4, 7, 7, 7, 9};
	bubbleSort(arrBubble, 10);
	countingSort(arrCounting, 10);
	
	int i = 0;
	while ((arrBubble[i] == sortArr[i]) && (arrCounting[i] == sortArr[i]) && (i < 11))
	{
		i++;
	}

	delete[] arrBubble;
	delete[] arrCounting;
	delete[] sortArr;
	
	return i == 11;
}

int main() 
{
	if (!test())
	{
		printf("%s", "Program doesn't work");
		return 1;
	} 

	int n = 0;
	printf("%s", "Enter N  =  ");
	scanf("%d", &n);

	int* arr = new int[n] {};

	randomArr(arr, n);
	printf("%s", "Original array\n");
	printArr(arr, n);
	bubbleSort(arr, n);
	printf("%s", "Result of bubble sort\n");
	printArr(arr, n);

	randomArr(arr, n);
	printf("%s", "Original array\n");
	printArr(arr, n);
	countingSort(arr, n);
	printf("%s", "Result of counting sort\n");
	printArr(arr, n);

	delete[] arr;
	return 0;
}
