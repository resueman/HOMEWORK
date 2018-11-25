#define _CRT_SECURE_NO_WARNINGS

#include "test.h"
#include "functionsToWorkWithNumbers.h"
#include <stdio.h>

int main() 
{
	if(!test())
	{
		printf("Program doesn't work!");
		return -1;
	}

	int decimal1 = 0;
	int decimal2 = 0;
	bool binary1[size]{};
	bool binary2[size]{};
	bool binarySum[size]{};

	printf("Enter decimal number  ");
	scanf("%d", &decimal1);
	printf("Enter decimal number  ");
	scanf("%d", &decimal2);

	convertToBinary(decimal1, binary1, size);
	printf("First number in binary:\n");
	printBinary(binary1, size);
	convertToBinary(decimal2, binary2, size);
	printf("Second number in binary:\n");
	printBinary(binary2, size);

	sumInBinary(binary1, binary2, binarySum, size);
	printf("Binary sum:\n");
	printBinary(binarySum , size);

	int decimalSum = convertToDecimal(binarySum, size);
	printf("Decimal sum:  %d", decimalSum);

	return 0;
}