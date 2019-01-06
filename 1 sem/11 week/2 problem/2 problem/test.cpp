#include "graphBuilding.h"
#include "graph.h"

#include <fstream>
#include <istream>
#include <iostream>
#include <vector>

using namespace std;

bool test()
{
	Graph* graph = graphBuilding("test.txt");
	Graph* minSpanningTree = primFindMST(graph);
	
	std::ifstream file;
	file.open("testAnswer.txt");
	if (!file.is_open())
	{
		return false;
	}

	int size = 0;
	file >> size;
	vector<vector<int>> graphAnswer;
	graphAnswer.resize(size, vector<int>(size));
	for (int i = 0; i < size; ++i)
	{
		for (int j = 0; j < size; ++j)
		{
			file >> graphAnswer[i][j];
			if (data(minSpanningTree, i, j) != graphAnswer[i][j])
			{
				return false;
			}
		}
	}
	file.close();

	deleteGraph(graph);
	deleteGraph(minSpanningTree);
	
	return true;
}