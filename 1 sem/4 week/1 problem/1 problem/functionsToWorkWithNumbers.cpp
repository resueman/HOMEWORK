#include <stdio.h>

void printBinary(bool* binary, const int size)
{
	for (int i = 0; i < size; ++i)
	{
		printf("%d ", binary[i]);
	}
	printf("\n\n");
}

void convertToBinary(int decimal, bool* binary, const int size)
{
	int bit = 0b010000000;
	for (int i = 1; i < size; ++i)
	{
		binary[i] = decimal & bit;
		bit = bit >> 1;
	}
	binary[0] = decimal < 0;
}

void sumInBinary(bool* binary1, bool* binary2, bool* binarySum, const int size)
{
	bool addToNext = 0;
	for (int i = size - 1; i >= 0; --i)
	{
		switch (binary1[i] + binary2[i] + addToNext)
		{
		case 0:
		{
			binarySum[i] = 0;
			addToNext = 0;
			break;
		}
		case 1:
		{
			binarySum[i] = 1;
			addToNext = 0;
			break;
		}
		case 2:
		{
			binarySum[i] = 0;
			addToNext = 1;
			break;
		}
		case 3:
		{
			binarySum[i] = 1;
			addToNext = 1;
			break;
		}
		}
	}
}

int convertToDecimal(bool* binary, const int size)
{
	int decimal = 0;
	int degreeOfTwo = 1;
	for (int i = size - 1; i >= 1; --i)
	{
		if (binary[i] ^ binary[0])
		{
			decimal += degreeOfTwo;
		}
		degreeOfTwo *= 2;
	}
	if (binary[0])
	{
		decimal += 1;
		decimal *= -1;
	}

	return decimal;
}
