#include "functionsToWorkWithNumbers.h"

bool test()
{
	int decimal1 = 8;
	bool binary1[size]{};
	int decimal2 = -8;
	bool binary2[size]{};
	int decimal3 = 0;
	bool binary3[size]{};
	int decimal4 = 1;
	bool binary4[size]{};
	int decimal5 = -1;
	bool binary5[size]{};
	int decimal6 = -5;
	bool binary6[size]{};
	int decimal7 = 5;
	bool binary7[size]{};

	convertToBinary(decimal1, binary1, size);
	convertToBinary(decimal2, binary2, size);
	convertToBinary(decimal3, binary3, size);
	convertToBinary(decimal4, binary4, size);
	convertToBinary(decimal5, binary5, size);
	convertToBinary(decimal6, binary6, size);
	convertToBinary(decimal7, binary7, size);

	if (!(convertToDecimal(binary1, size) == 8 && convertToDecimal(binary2, size) == -8
		&& convertToDecimal(binary3, size) == 0 && convertToDecimal(binary4, size) == 1
		&& convertToDecimal(binary5, size) == -1))
	{
		return false;
	}

	bool binarySum12[size]{};
	bool binarySum14[size]{};
	bool binarySum15[size]{};
	bool binarySum16[size]{};
	bool binarySum17[size]{};
	bool binarySum13[size]{};
	bool binarySum33[size]{};
	bool binarySum26[size]{};
	bool binarySum27[size]{};

	sumInBinary(binary1, binary2, binarySum12, size);
	convertToDecimal(binarySum12, size);
	sumInBinary(binary1, binary4, binarySum14, size);
	convertToDecimal(binarySum14, size);
	sumInBinary(binary1, binary5, binarySum15, size);
	convertToDecimal(binarySum15, size);
	sumInBinary(binary1, binary6, binarySum16, size);
	convertToDecimal(binarySum16, size);
	sumInBinary(binary1, binary7, binarySum17, size);
	convertToDecimal(binarySum17, size);
	sumInBinary(binary1, binary3, binarySum13, size);
	convertToDecimal(binarySum13, size);
	sumInBinary(binary3, binary3, binarySum33, size);
	convertToDecimal(binarySum33, size);
	sumInBinary(binary2, binary6, binarySum26, size);
	convertToDecimal(binarySum26, size);
	sumInBinary(binary2, binary7, binarySum27, size);
	convertToDecimal(binarySum27, size);

	if (!(convertToDecimal(binarySum12, size) == 0 && convertToDecimal(binarySum14, size) == 9 &&
		convertToDecimal(binarySum15, size) == 7 && convertToDecimal(binarySum16, size) == 3 &&
		convertToDecimal(binarySum17, size) == 13 && convertToDecimal(binarySum13, size) == 8 &&
		convertToDecimal(binarySum33, size) == 0 && convertToDecimal(binarySum26, size) == -13 &&
		convertToDecimal(binarySum27, size) == -3))
	{
		return false;
	}

	return true;
}
