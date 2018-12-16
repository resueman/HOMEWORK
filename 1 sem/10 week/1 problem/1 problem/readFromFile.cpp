#include "readFromFile.h"

#include <fstream>
#include <istream>

using namespace std;

bool readFromFile(const char* fileName, Graph* graph, vector<int> &states, set<int> &noStateVertecies)
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
	
	for (int i = 0; i < numberOfRoads; ++i)
	{
		int city1 = 0;
		int city2 = 0;
		int pathLenght = 0;
		file >> city1 >> city2 >> pathLenght;

		bool result1 = noStateVertecies.find(city1) == noStateVertecies.end();
		bool result2 = noStateVertecies.find(city2) == noStateVertecies.end();
		
		addToSet(graph, city1, result1);
		addToSet(graph, city2, result2);

		addToAdjList(graph, city1, city2, pathLenght);
		addToAdjList(graph, city2, city1, pathLenght);

		noStateVertecies.insert(city1);
		noStateVertecies.insert(city2);
	}

	int numberOfStates = 0;
	file >> numberOfStates;
	
	for (int i = 0; i < numberOfStates; ++i)
	{
		int stateNumber = 0;
		file >> stateNumber;
		changeState(graph, stateNumber, stateNumber);
		states.push_back(stateNumber);
		noStateVertecies.erase(stateNumber);
	}

	file.close();
	return true;
}
