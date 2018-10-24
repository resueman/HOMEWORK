#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include<cmath>
int mn() {
	int arrayLength, i;
	int counter = 0;
	printf("%s", "Enter the length of array    ");
	scanf("%d", &arrayLength);
	int *x = new int[arrayLength] {};
	for (i = 0; i < arrayLength; i++) {
		scanf("%d", &x[i]);
		if (x[i] == 0) counter++;
	}
	printf("%s%d", "Number of zero elements    ", counter);
	printf("\n");
	delete[] x;
	return 0;
}