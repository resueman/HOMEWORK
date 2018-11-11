#include <string>
#include "functionsDeclaration.h"
#include "test.h"
bool test()
{
	List list;
	whatToDelete(list, 1);
	addElement(list, 1);
	whatToDelete(list, 1);
	addElement(list, 2);
	whatToDelete(list, 3);
	whatToDelete(list, 1);
	addElement(list, 1);
	addElement(list, 2);
	addElement(list, 3);
	whatToDelete(list, 1);
	whatToDelete(list, 2);
	whatToDelete(list, 3);
	whatToDelete(list, 2);
	addElement(list, 0);
	addElement(list, 1);
	addElement(list, 7);
	whatToDelete(list, 1);
	system("cls");
	std::string desiredResult = "0 7 ";
	std::string resultWeGot = "";
	auto* current = list.head;
	while (current != nullptr)
	{
		resultWeGot += std::to_string(current->data) + " ";
		current = current->next;
	}
	deleteList(list);
	return resultWeGot == desiredResult;
}