#include "printToFile.h"

#include <iostream>
#include <fstream>

using namespace std;

void printToFile(const char* fileName, const string &result)
{
	ofstream out;
	out.open(fileName);
	if (out.is_open())
	{
		out << result << endl;
	}
	out.close();
}
