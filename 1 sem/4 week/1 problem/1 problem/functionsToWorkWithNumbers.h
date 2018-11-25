#pragma once

const int size = 9; //don't forget to change bit mask, if you change size

///print binary
void printBinary(bool* binary, const int size);

///convert decimal to binary
void convertToBinary(int decimal, bool* binary, int size);

///sum two binary numbers
void sumInBinary(bool* binary1, bool* binary2, bool* binarySum, const int size);

///convert binary to decimal
int convertToDecimal(bool* binary, const int size);
