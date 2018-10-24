#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include<cmath>
int ma99in() {
	int b, del;
	bool f;
	printf("%s", "Enter the number  ");
	scanf("%d", &b);
	for (int a = 2; a <= b; a++){
		del = 2; 
		f = true;
		while ((f) && (del <= sqrt(a))){
			if(a % del == 0) f = false;
			del++;
		}
		if (f) printf("%d%s", a, "   ");
	}
	printf("\n");
	return 0;
}