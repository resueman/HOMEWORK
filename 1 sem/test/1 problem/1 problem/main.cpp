#define _CRT_SECURE_NO_WARNINGS

#include "queue.h"
#include <fstream>
#include <string>
#include <iostream>

using namespace std;

void fromQueueToString(Queue* queue, string &result)
{
	while (!isEmpty(queue))
	{
		result += to_string(dequeue(queue)) + " ";
	}
}

void printResultToFile(const char* fileName, Queue* queueLessA, Queue* queueBetweenAB, Queue* queueBiggerB, string &result)
{
	FILE* fileG = fopen(fileName, "w");

	fromQueueToString(queueLessA, result);
	fromQueueToString(queueBetweenAB, result);
	fromQueueToString(queueBiggerB, result);

	fprintf(fileG, "%s", result.c_str());
	fclose(fileG);
}

void putInQueue(int &a, int &b, int number, Queue* queueLessA, Queue* queueBetweenAB, Queue* queueBiggerB)
{
	if (number < a)
	{
		enqueue(queueLessA, number);
	}
	else if (number <= b)
	{
		enqueue(queueBetweenAB, number);
	}
	else
	{
		enqueue(queueBiggerB, number);
	}
}

bool getResult(int &a, int &b, const char* fileNameFrom, const char* fileNameTo, string &result)
{
	Queue* queueLessA = createQueue();
	Queue* queueBetweenAB = createQueue();
	Queue* queueBiggerB = createQueue();

	FILE *fileF = fopen(fileNameFrom, "r");
	if (!fileF)
	{
		cout << "File not found";
		return false;
	}
	
	while (!feof(fileF))
	{
		int number = 0;
		fscanf(fileF, "%d", &number);
		putInQueue(a, b, number, queueLessA, queueBetweenAB, queueBiggerB);
	}

	printResultToFile(fileNameTo, queueLessA, queueBetweenAB, queueBiggerB, result);

	deleteQueue(queueLessA);
	deleteQueue(queueBetweenAB);
	deleteQueue(queueBiggerB);

	fclose(fileF);
	return true;
}

bool test()
{
	string result = "";
	int a = 7;
	int b = 10;
	getResult(a, b, "test.txt", "testResult.txt", result);
	return result == "5 4 8 13 21 ";
}

int main()
{
	if (!test())
	{
		cout << ":(";
		return -1;
	}
	
	int a = 0;
	int b = 0;
	cout << "Enter a:   ";
	cin >> a;
	cout << "Enter b:   ";
	cin >> b;
	
	string result = "";
	if (getResult(a, b, "f.txt", "g.txt", result))
	{
		cout << "Mission comleted!";
	}
	
	return 0;
}