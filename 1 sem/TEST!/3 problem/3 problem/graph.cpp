#include <queue>
#include <vector>
#include <iostream>

using namespace std;

struct Graph
{
	vector<vector<int>> verticesMatrix;
};

Graph* createGraph(const int numberOfVertices)
{
	auto graph = new Graph;
	graph->verticesMatrix.resize(numberOfVertices);
	for (int i = 0; i < numberOfVertices; ++i)
	{
		graph->verticesMatrix[i].resize(numberOfVertices);
	}
	return graph;
}

void deleteGraph(Graph*& graph)
{
	delete graph;
	graph = nullptr;
}

void addToGraph(Graph* graph, const int element, const int linePosition, const int columnPosition)
{
	graph->verticesMatrix[linePosition][columnPosition] = element;
}

void printGraph(Graph* graph)
{
	for (int i = 0; i < graph->verticesMatrix.size(); ++i)
	{
		for (int j = 0; j < graph->verticesMatrix.size(); ++j)
		{
			cout << graph->verticesMatrix[i][j] << "  ";
		}
		cout << endl;
	}
	cout << endl;
}

vector<bool> search(Graph* graph)
{
	vector<bool> answer(graph->verticesMatrix.size());
	for (int i = 0; i < graph->verticesMatrix.size(); ++i)
	{
		queue<int> adjacent;
		vector <bool> used(graph->verticesMatrix.size());
		for (int i = 0; i < graph->verticesMatrix.size(); ++i)
		{
			used[i] = false;
		}

		used[i] = true;

		for (int j = 0; j < graph->verticesMatrix.size(); ++j)
		{
			if (graph->verticesMatrix[i][j] < 0)
			{
				adjacent.push(j);
				used[j] = true;
			}
		}

		while (!adjacent.empty())
		{
			int vertex = adjacent.front();
			adjacent.pop();
			for (int i = 0; i < graph->verticesMatrix.size(); ++i)
			{
				if (!used[i] && graph->verticesMatrix[vertex][i] < 0)
				{
					used[i] = true;
					adjacent.push(i);
				}
			}
		}

		int result = 0;
		for (int i = 0; i < graph->verticesMatrix.size(); ++i)
		{
			if (used[i])
			{
				++result;
			}
		}
		if (result == graph->verticesMatrix.size())
		{
			answer[i] = true;
		}
		else
		{
			answer[i] = false;
		}
	}

	return answer;
}

void printAnswer(Graph* graph, vector<bool> answer)
{
	cout << "Answer:  ";
	for (int i = 0; i < graph->verticesMatrix.size(); ++i)
	{
		if (answer[i])
		{
			cout << i << " ";
		}
	}
}