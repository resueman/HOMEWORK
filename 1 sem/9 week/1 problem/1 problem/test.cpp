#include "test.h"

bool test()
{
	Set* hashTableTest = createHashTable();
	readFromFile(hashTableTest, "test.txt");
	bool result = findNumberOfStrReiterations(hashTableTest, "скороговорун") == 7 &&
		findNumberOfStrReiterations(hashTableTest, "скороговорил") == 3 &&
		findNumberOfStrReiterations(hashTableTest, "скоровыговаривал") == 3 &&
		findNumberOfStrReiterations(hashTableTest, "что") == 6 &&
		findNumberOfStrReiterations(hashTableTest, "всех") == 3 &&
		findNumberOfStrReiterations(hashTableTest, "все") == 3 &&
		findNumberOfStrReiterations(hashTableTest, "не") == 9 &&
		findNumberOfStrReiterations(hashTableTest, "скороговорок") == 3 &&
		findNumberOfStrReiterations(hashTableTest, "скороговорки") == 3 &&
		findNumberOfStrReiterations(hashTableTest, "перескороговоришь") == 6 &&
		findNumberOfStrReiterations(hashTableTest, "перескоровыговариваешь") == 6 &&
		findNumberOfStrReiterations(hashTableTest, "заскороговорившись") == 3 &&
		findNumberOfStrReiterations(hashTableTest, "выскороговорил") == 3 &&
		findNumberOfStrReiterations(hashTableTest, "скоро") == 4 &&
		findNumberOfStrReiterations(hashTableTest, "поскороговорим") == 1 &&
		findNumberOfStrReiterations(hashTableTest, "непоскороговори") == -1 &&
		findNumberOfStrReiterations(hashTableTest, "скороо") == -1 &&
		findNumberOfStrReiterations(hashTableTest, "перескороговорим") == -1;

	deleteHashTable(hashTableTest);

	return result;
}
