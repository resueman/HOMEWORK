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
		printf("��������� �� ��������!");
		return -1;
	}

	int decimal1 = 0;
	int decimal2 = 0;
	bool binary1[size]{};
	bool binary2[size]{};
	bool binarySum[size]{};

	printf("�����1 � 10-� ������� ���������:  ");
	scanf("%d", &decimal1);
	printf("�����2 � 10-� ������� ���������:  ");
	scanf("%d", &decimal2);

	convertToBinary(decimal1, binary1, size);
	printf("\n�����1 � 2-� ������� ���������:\n");
	printBinary(binary1, size);
	convertToBinary(decimal2, binary2, size);
	printf("�����2 � 2-� ������� ���������:\n");
	printBinary(binary2, size);

	sumInBinary(binary1, binary2, binarySum, size);
	printf("����� �����1 � �����2 � 2-� ������� ���������:\n");
	printBinary(binarySum , size);

	int decimalSum = convertToDecimal(binarySum, size);
	printf("����� �����1 � �����2 � 10-� ������� ���������:\n%d", decimalSum);
	
	return 0;
}