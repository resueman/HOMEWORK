#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int main1() {
	
	long long result = 0; 
	int sum[28]{};

	for (int i = 0; i < 10; i++) {
		for (int j = 0; j < 10; j++) {
			for (int k = 0; k < 10; k++) {
				sum[i + j + k]++;
			}
		}
	}

	for (int i = 0; i < 28; i++) {
		result += sum[i] * sum[i];
	 }

	printf("Result   %li\n", result);
	return 0;
}