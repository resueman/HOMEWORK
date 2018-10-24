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

void partition(int *arr, int n)
{
	const int first = arr[0];
	int i = 1;
	for(int j = 1; j < n; ++j)
	{
		if (arr[j] <= first)
		{
			swap(arr[j], arr[i]);
			i++;
		}
	}
	swap(arr[0], arr[i - 1]);
}

int test()
{
	int* origArr = new int[11]{5, 6, 7, 8, 2, 5, 5, 9, 2, 8, 1};
	int* finalArr = new int[11]{1, 2, 5, 5, 2, 5, 8, 9, 6, 8, 7};
	partition(origArr, 11);
	int i = 0;
	while ((origArr[i] == finalArr[i]) && (i < 10)) 
	{
		i++;
	}
	delete[] origArr;
	delete[] finalArr;
	return i;
}

int main()
{
	if (test() != 10)
	{
		printf("Program doesn't work :(");
		return 1;
	}

	int n = 0;
	printf("%s", "Enter N  =  ");
	scanf("%d", &n);

	int* arr = new int[n]{};
	for (int i = 0; i < n; ++i)
	{
		arr[i] = rand() % 150;
	}

	printf("%s", "Original array\n");
	printArr(arr, n);	
	partition(arr, n);
	printf("%s", "Final array\n");
	printArr(arr, n);
	delete[] arr;
	return 0;
}
