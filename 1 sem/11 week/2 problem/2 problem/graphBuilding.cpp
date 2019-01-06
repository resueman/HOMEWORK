#include "graphBuilding.h"
#include "graph.h"

#include <fstream>
#include <istream>
#include <iostream>

Graph* graphBuilding(const char* fileName)
{
	std::ifstream file;
	file.open(fileName);
	if (!file.is_open())
	{
		std::cout << "File isn't opened\n";
		return nullptr;
	}
	int size = 0;
	file >> size;
	Graph* graph = createGraph(size);
	for (int i = 0; i < size; ++i)
	{
		for (int j = 0; j < size; ++j) 
		{
			int element = 0;
			file >> element;
			addToGraph(graph, element, i, j);
		}
	}
	file.close();
	return graph;
}
