#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int man() {
	int x;
	printf("%s", "Enter x:   ");
	scanf("%i", &x);

	int k = x * x;
	x = (x + k) * (k + 1) + 1;

	printf("Result:   %i\n", x);

	return 0;
}