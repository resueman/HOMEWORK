#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <fstream>
#include <string>
using namespace std;

int getDataFromFile(int* numbersArr, FILE* file)
{
	if (!file)
	{
		printf("File not found.");
		return 1;
	}
	int index = 0;
	while (!feof(file))
	{
		fscanf(file, "%d", &numbersArr[index]);
		++index;
	}
	fclose(file);
	return index;
}

int getKeyX(FILE* file)
{
	if (!file)
	{
		printf("File not found.");
		return 1;
	}
	int keyX = 0;
	fscanf(file, "%d", &keyX);
	fclose(file);
	return keyX;
}

void elemLessX(int* arrData, int length, int keyX, FILE* file)
{   
	string result = "";
	for(int i = 0; i < length; ++i)
	{	
		if(arrData[i] < keyX)
		{
			result += to_string(arrData[i]) + " ";
		}
	}
	fprintf(file, "%s", result.c_str());
	fclose(file);
}

/*bool test()
{
	int numbersArr[10] {};
	FILE *fileF = fopen("f_test.txt", "r");
	getDataFromFile(numbersArr, fileF);
	FILE* fileG = fopen("g_test.txt", "r");
	FILE* fileH = fopen("h_test.txt", "r");
	string desiredStr = "5 1 3 6 ";
	return desiredStr == elemLessX(numbersArr, 10, getKeyX(fileG), fileH);
}*/

int main()
{
	int n = 10000;
	int* numbersArr = new int[n] {};
	FILE *fileF = fopen("f.txt", "r");
	n = getDataFromFile(numbersArr, fileF);
	FILE* fileG = fopen("g.txt", "r");
	FILE * fileH = fopen("h.txt", "w");
	elemLessX(numbersArr, n, getKeyX(fileG), fileH);
	return 0;
}