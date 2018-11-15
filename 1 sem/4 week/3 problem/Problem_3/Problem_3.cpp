#define _CRT_SECURE_NO_WARNINGS 

#include <stdio.h>
#include <string>
#include "Functions for phonebook.h"

void interaction(int numberOfRecords, Person *man)
{
	int userChoice = 0;
	do
	{
		printf(" Choose option, please \n\n");
		printf(" Your choice: ");
		scanf("%d", &userChoice);
		switch (userChoice)
		{
		case 0:
			return;
		case 1://add record
			addRecord(&numberOfRecords);
			break;
		case 2://print
			printAllRecords(numberOfRecords, man);
			break;
		case 3://find number
		{
			char ownerOfTelephoneNumber[20];
			printf(" Let's find telephone number, which belongs to :   ");
			scanf("%s", &ownerOfTelephoneNumber);
			findNumber(man, numberOfRecords, ownerOfTelephoneNumber);
		}
		break;
		case 4://find name
		{
			char smbTelephoneNumber[20];
			printf(" Enter telephone number:   ");
			scanf("%s", &smbTelephoneNumber);
			findName(man, numberOfRecords, smbTelephoneNumber);
		}
		break;
		case 5://save
			saveToFile(numberOfRecords);
			break;
		default:
			printf(" No such option ;(\n");
			break;
		}
	} while (userChoice != 0);
}

int readFromFile(FILE *file, Person* man)
{
	int numberOfRecords = 0;
	if (!file)
	{
		printf(" File not found!\n\n");
	}
	else
	{
		while (!feof(file))
		{
			const int readBytes = fscanf(file, "%s%s", &man[numberOfRecords].name, &man[numberOfRecords].telephoneNumber);
			if (readBytes < 0)
			{
				break;
			}
			numberOfRecords++;
		}
		fclose(file);
	}
	return numberOfRecords;
}

int test()
{
	Person personTest[10]{};
	FILE *test = fopen("test.txt", "r");
	readFromFile(test, personTest);
	
	printf("Must be printed: qwerty\n");
	findName(personTest, 6, personTest[0].telephoneNumber);
	printf("Must be printed: qwe\n"); 
	findName(personTest, 6, personTest[3].telephoneNumber);
	printf("Must be printed: q\n"); 
	findName(personTest, 6, personTest[5].telephoneNumber);
	
	printf("Must be printed: 123456\n");
	findNumber(personTest, 6, personTest[0].name);
	printf("Must be printed: 123\n");
	findNumber(personTest, 6, personTest[3].name);
	printf("Must be printed: 1\n");
	findNumber(personTest, 6, personTest[5].name);

	int resultOfTest = 0;
	printf("if everything ok, press 1, else press 0\n");
	scanf("%d", &resultOfTest);
	return resultOfTest;
}

int main()
{
	if (test() != 1)
	{
		printf("Program doesn't work ;(");
		return 1;
	}
	system("cls");
	printf(" 0. Exit\n");
	printf(" 1. Add record\n");
	printf(" 2. Print all records\n");
	printf(" 3. Find number\n");
	printf(" 4. Find name\n");
	printf(" 5. Save current data to file\n");
	FILE *file = fopen("file.txt", "r");
	interaction(readFromFile(file, man), man);
	return 0;
}
