#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int mjain() {

	int a, b, z;
	int k = -1;

	printf("%s", "Enter a =  ");
	scanf("%i", &a);
	printf("%s", "Enter b =  ");
	scanf("%i", &b);

	if (a * b == 0)
		z = 0;
	else if (a * b > 0)
		z = 1;
		else z = -1;
	
	if (a < 0) a = a * (-1);
	if (b < 0) b = b * (-1);

	if (b != 0) {
		while (a >= 0) {
			a = a - b;
			k = k + 1;
		}
		printf("%s%i\n", "Result = ", k * z);
	}else printf("%s","Error! Division by zero!\n");

	return 0;
}