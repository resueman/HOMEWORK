#include "test.h"

bool test()
{
	Set* hashTableTest = createHashTable();
	readFromFile(hashTableTest, "test.txt");
	bool result = findNumberOfStrReiterations(hashTableTest, "������������") == 7 &&
		findNumberOfStrReiterations(hashTableTest, "������������") == 3 &&
		findNumberOfStrReiterations(hashTableTest, "����������������") == 3 &&
		findNumberOfStrReiterations(hashTableTest, "���") == 6 &&
		findNumberOfStrReiterations(hashTableTest, "����") == 3 &&
		findNumberOfStrReiterations(hashTableTest, "���") == 3 &&
		findNumberOfStrReiterations(hashTableTest, "��") == 9 &&
		findNumberOfStrReiterations(hashTableTest, "������������") == 3 &&
		findNumberOfStrReiterations(hashTableTest, "������������") == 3 &&
		findNumberOfStrReiterations(hashTableTest, "�����������������") == 6 &&
		findNumberOfStrReiterations(hashTableTest, "����������������������") == 6 &&
		findNumberOfStrReiterations(hashTableTest, "������������������") == 3 &&
		findNumberOfStrReiterations(hashTableTest, "��������������") == 3 &&
		findNumberOfStrReiterations(hashTableTest, "�����") == 4 &&
		findNumberOfStrReiterations(hashTableTest, "��������������") == 1 &&
		findNumberOfStrReiterations(hashTableTest, "���������������") == -1 &&
		findNumberOfStrReiterations(hashTableTest, "������") == -1 &&
		findNumberOfStrReiterations(hashTableTest, "����������������") == -1;

	deleteHashTable(hashTableTest);

	return result;
}
