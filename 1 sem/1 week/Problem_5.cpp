#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int mainh() {
	int n;
	
	printf("%s", "Enter the number of chars   ");
	scanf("%d\n", &n);
	char* c = new char[n] {};

	for (int i = 0; i < n; ++i) {
		scanf("%c", &c[i]);
	}

	for (int i = 0; i < n; ++i) {
		printf("%c ", c[i]);
	}
	printf("\n");
	
	int balance = 0;
	int i = 0;
	while ((balance >= 0) && (i < n)) {
		if (c[i] == ')') balance--;
		if (c[i] == '(') balance++;
		i++;
	}

	if (balance != 0) printf("%s", "No balance\n");
	else printf("%s","Balance\n");
	
	delete[] c;
	return 0;
}