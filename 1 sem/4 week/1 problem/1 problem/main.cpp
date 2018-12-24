#define _CRT_SECURE_NO_WARNINGS

#include "test.h"
#include "functionsToWorkWithNumbers.h"
#include <stdio.h>
#include <locale>

int main() 
{
	setlocale(LC_ALL, "Russian");

	if(!test())
	{
		printf("Программа не работает!");
		return -1;
	}

	int decimal1 = 0;
	int decimal2 = 0;
	bool binary1[size]{};
	bool binary2[size]{};
	bool binarySum[size]{};

	printf("Число1 в 10-й системе счисления:  ");
	scanf("%d", &decimal1);
	printf("Число2 в 10-й системе счисления:  ");
	scanf("%d", &decimal2);

	convertToBinary(decimal1, binary1, size);
	printf("\nЧисло1 в 2-й системе счисления:\n");
	printBinary(binary1, size);
	convertToBinary(decimal2, binary2, size);
	printf("Число2 в 2-й системе счисления:\n");
	printBinary(binary2, size);

	sumInBinary(binary1, binary2, binarySum, size);
	printf("Сумма числа1 и числа2 в 2-й системе счисления:\n");
	printBinary(binarySum , size);

	int decimalSum = convertToDecimal(binarySum, size);
	printf("Сумма числа1 и числа2 в 10-й системе счисления:\n%d", decimalSum);
	
	return 0;
}