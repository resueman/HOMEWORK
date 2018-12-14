#include "readFromFile.h"
#include "list.h"
#include <iostream>

using namespace std;

bool test()
{
	List* listTest = createList();
	read(listTest, "test.txt");
	List* newListTest = createList();
	newListTest = reverse(listTest, newListTest);
	std::string result = printList(listTest);
	
	deleteList(listTest);
	deleteList(newListTest);
	
	return result == "3  2  1  ";
}

int main()
{
	if (!test())
	{
		cout << "Everything is bad";
		return -1;
	}

	List* list = createList();
	read(list, "file.txt");
	std::cout << printList(list);
	List* newList = createList();
	newList = reverse(list, newList);
	std::string result = printList(list);
	std::cout << result;

	deleteList(list);
	deleteList(newList);

	return 0;
}