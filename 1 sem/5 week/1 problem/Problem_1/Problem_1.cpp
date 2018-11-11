#define _CRT_SECURE_NO_WARNINGS

#include <string>
#include "functionsDeclaration.h"
#include "test.h"

void interactive(List &list)
{
	int userChoice = 0;
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

int main()
{
	if(!test())
	{
		printf("Everything is bad ;(");
		return 1;
	}
	else 
	{
		List list;
		printf("0 - EXIT\n1 - ADD ELEMENT\n2 - DELETE ELEMENT\n3 - PRINT LIST\n4 - CLEAR SCREEN\n\n");
		interactive(list);
		deleteList(list);
	}
	return 0;
}
