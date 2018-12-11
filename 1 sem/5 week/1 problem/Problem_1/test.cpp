#include <string>
#include "listFunctions.h"
#include "test.h"

bool test()
{
	List listTest;
	whatToDelete(listTest, 1);
	addElement(listTest, 1);
	whatToDelete(listTest, 1);
	addElement(listTest, 2);
	whatToDelete(listTest, 3);
	whatToDelete(listTest, 1);
	addElement(listTest, 1);
	addElement(listTest, 2);
	addElement(listTest, 3);
	whatToDelete(listTest, 1);
	whatToDelete(listTest, 2);
	whatToDelete(listTest, 3);
	whatToDelete(listTest, 2);
	addElement(listTest, 0);
	addElement(listTest, 1);
	addElement(listTest, 7);
	whatToDelete(listTest, 1);
	system("cls");
	std::string desiredResult = "0 7 ";
	std::string resultWeGot = "";
	auto* current = listTest.head;
	while (current != nullptr)
	{
		resultWeGot += std::to_string(current->data) + " ";
		current = current->next;
	}
	deleteList(listTest);
	return resultWeGot == desiredResult;
}
