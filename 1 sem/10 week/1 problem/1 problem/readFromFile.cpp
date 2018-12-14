#include "readFromFile.h"
#include "graph.h"
#include <fstream>
#include <istream>

using namespace std;

bool readFromFile(const char* fileName, Graph* graph)
{
	ifstream file;
	file.open(fileName);
	if (!file.is_open())
	{
		return false;
	}

	int numberOfCities = 0;
	int numberOfRoads = 0;
	file >> numberOfCities >> numberOfRoads;

	buildGraph(graph, numberOfCities);

	for (int i = 0; i < numberOfRoads; ++i)
	{
		int city1 = 0;
		int city2 = 0;
		int pathLenght = 0;
		file >> city1 >> city2 >> pathLenght;
		addVertexToGraph(graph, city1, city2, pathLenght);
		addVertexToGraph(graph, city2, city1, pathLenght);
	}

	int numberOfStates = 0;
	file >> numberOfStates;
	for (int i = 0; i < numberOfStates; ++i)
	{
		int stateNumber = 0;
		file >> stateNumber;
		assignToState(graph, stateNumber, stateNumber);
	}

	file.close();
	return true;
}
