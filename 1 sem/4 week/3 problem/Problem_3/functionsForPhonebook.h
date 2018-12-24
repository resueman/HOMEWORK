#pragma once

#include <string>

struct Person
{
	char name[20];
	char telephoneNumber[20];
};

const int baseSize = 100;

///add new record to phonebook
void addRecord(int &numberOfRecords, Person* man);///1

///print all phonebook's records												  
void printAllRecords(int numberOfRecords, Person* man);///2

///function determines telephone number by name of its owner
std::string findNumber(Person* man, int numberOfRecords, char* ownerOfTelephoneNumber);///3

///function determines the owner of the phone number by name
std::string findName(Person *man, int numberOfRecords, char* smbTelephoneNumber);///4

///save current phonebook to file
void saveToFile(int currentNumberOfRecords, Person* man);///5
