#define _CRT_SECURE_NO_WARNINGS 

#include "functionsForPhonebook.h"

void addRecord(int &numberOfRecords, Person* man)///1
{
	printf(" Enter name:   ");
	scanf("%s", &man[numberOfRecords].name);
	printf(" Enter telephone number:   ");
	scanf("%s", &man[numberOfRecords].telephoneNumber);
	(numberOfRecords)++;
}

void printAllRecords(int numberOfRecords, Person* man)///2
{
	if (numberOfRecords == 0)
	{
		printf(" Phonebook is empty\n\n");
	}
	else
	{
		for (int i = 0; i < numberOfRecords; ++i)
		{
			printf(" %s   %s\n", man[i].name, man[i].telephoneNumber);
		}
	}
}

std::string findNumber(Person* man, int numberOfRecords, char* ownerOfTelephoneNumber)///3
{
	int i = 0;
	while ((i < numberOfRecords) && (strcmp(man[i].name, ownerOfTelephoneNumber) != 0))
	{
		i++;
	}
	if (i != numberOfRecords)
	{
		return man[i].telephoneNumber;
	}
	else
	{
		return "No such telephone number in base";
	}
}

std::string findName(Person *man, int numberOfRecords, char* smbTelephoneNumber)///4
{
	int i = 0;
	while ((i < numberOfRecords) && (strcmp(man[i].telephoneNumber, smbTelephoneNumber) != 0))
	{
		i++;
	}
	if (i != numberOfRecords)
	{
		return man[i].name;
	}
	else
	{
		return "Owner is not found";
	}
}

void saveToFile(int currentNumberOfRecords, Person* man)///5
{
	FILE * out = fopen("file.txt", "w");
	for (int i = 0; i < currentNumberOfRecords; i++)
	{
		fprintf(out, "%s   %s\n", man[i].name, man[i].telephoneNumber);
	}
	printf(" Changes saved\n");
	fclose(out);
}
