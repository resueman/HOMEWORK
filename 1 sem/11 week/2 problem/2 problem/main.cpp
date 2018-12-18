#include "readFromFile.h"
#include <iostream>
#include <vector>

using namespace std;

int main()
{
	vector<vector<int>> matrix;
	readFromFile("file.txt", matrix);
	return 0;
}
