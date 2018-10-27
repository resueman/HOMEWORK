#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <string>
#include <iostream>
#include "functions to work with list.h"

void interactive(List &list)
{
	int userChoice;
	do
	{	
		printf("Choose option, please \n");
		printf("Your choice: ");
		scanf("%d", &userChoice);
		switch (userChoice)
		{
		case 0:
			return;
		case 1:
		{
			int value = 0;
			scanf("%d", &value);
			addElement(list, value);
			printf("\n"); 
		}
			break;
		case 2: 
		{
			int elementToDelete = 0;
			scanf("%d", &elementToDelete);
			whatToDelete(list, elementToDelete); 
			printf("\n");
		}
			break;
		case 3:
			printList(list);
			break;
		case 4:
			system("cls");
			printf("0 - EXIT\n1 - ADD ELEMENT\n2 - DELETE ELEMENT\n3 - PRINT LIST\n4 - CLEAR SCREEN\n\n");
			break;
		default:
			printf("No such option ;(\n");
			break;
		}
	} while (userChoice != 0);
}

bool test()
{
	whatToDelete(listForTest, 1); 
	addElement(listForTest, 1);
	whatToDelete(listForTest, 1);
	addElement(listForTest, 2);
	whatToDelete(listForTest, 3);
	whatToDelete(listForTest, 1);
	addElement(listForTest, 1);
	addElement(listForTest, 2);
	addElement(listForTest, 3);
	whatToDelete(listForTest, 1);
	whatToDelete(listForTest, 2);
	whatToDelete(listForTest, 3);
	whatToDelete(listForTest, 2);
	addElement(listForTest, 0);
	addElement(listForTest, 1);
	addElement(listForTest, 7);
	whatToDelete(listForTest, 1);
	system("cls");
	std::string desiredResult = "0 7 ";
	std::string resultWeGot = "";
	auto* current = listForTest.head;
	while (current != nullptr)
	{
		resultWeGot += std::to_string(current->data) + " ";
		current = current->next;
	}
	return resultWeGot == desiredResult;
}

int main()
{
	if(!test())
	{
		std::cout << "Everything is bad ;(";
		return 1;
	}
	else 
	{
		std::cout << "0 - EXIT\n1 - ADD ELEMENT\n2 - DELETE ELEMENT\n3 - PRINT LIST\n4 - CLEAR SCREEN\n\n";
		interactive(list);
	}
	return 0;
}