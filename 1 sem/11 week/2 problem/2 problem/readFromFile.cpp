#include "readFromFile.h"

#include <fstream>
#include <istream>
#include <vector>

using namespace std;

bool readFromFile(const char* fileName, vector<vector<int>> &matrix)
{
	std::ifstream file;
	file.open(fileName);
	if (!file.is_open())
	{
		return false;
	}
	int n = 0;
	file >> n;
	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < n; ++j)
		{
			file >> matrix[i][j];
		}
	}
	file.close();
	return true;
}
