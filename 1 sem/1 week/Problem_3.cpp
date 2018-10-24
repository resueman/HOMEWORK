#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <cstdlib>

void Func(int* arr, int n) {
	for (int i = 0; i < n / 2; ++i) {
		int exch = arr[i];
		arr[i] = arr[n - i - 1];
		arr[n - i - 1] = exch;
	}
}

void Print(int* arr, int length) {
	for (int i = 0; i < length; ++i)
		printf("%d ", arr[i]);
	printf("\n");
}

int maiddn() {
	int m, n;

	printf("%s", "Enter M  =  ");
	scanf("%d", &m);

	printf("%s", "Enter N  =  ");
	scanf("%d", &n);

	int* x = new int[m + n]{};

	for (int i = 0; i < m + n; ++i)
		x[i] = rand() % 50;

	printf("%s", "Original array\n");
	Print(x, m + n);

	Func(x, m);
	Func(x + m, n);
	Func(x, m + n);

	printf("%s", "Final array\n");
	Print(x, m + n);

	delete[] x;

	return 0;
}
