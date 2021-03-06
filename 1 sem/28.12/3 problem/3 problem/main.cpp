#include <iostream>
#include <fstream>
#include <istream>
#include <vector>

struct VisitTime
{
	int hourBegin = 0;
	int minuteBegin = 0;
	int hourEnd = 0;
	int minuteEnd = 0;
};

void swap(VisitTime &a, VisitTime &b)
{
	VisitTime buffer = a;
	a = b;
	b = buffer;
}

bool fileReading(std::vector<VisitTime> &allVisits)
{
	std::ifstream file;
	file.open("test.txt");
	if (!file.is_open())
	{
		std::cout << "File isn't opened\n";
		return false;
	}
	VisitTime person;
	while (!file.eof())
	{
		file >> person.hourBegin;
		file >> person.minuteBegin;
		file >> person.hourEnd;
		file >> person.minuteEnd;
		allVisits.push_back(person);
	}
	file.close();
	return true;
}

void sort(std::vector<VisitTime> &allVisits)
{
	for (int i = 0; i < allVisits.size() - 1; ++i)
	{
		for (int j = 0; j < allVisits.size() - i - 1; ++j)
		{
			if (allVisits[j].hourBegin * 60 + allVisits[j].minuteBegin > allVisits[j + 1].hourBegin * 60 + allVisits[j + 1].minuteBegin)
			{
				swap(allVisits[j], allVisits[j + 1]);
			}
		}
	}
}

int main()
{
	std::vector<VisitTime> allVisits;
	fileReading(allVisits);
	sort(allVisits);

	std::vector<int> begin;
	std::vector<int> end;
	begin.resize(allVisits.size());
	end.resize(allVisits.size());

	for (int i = 0; i < allVisits.size(); ++i)
	{
		begin[i] = allVisits[i].hourBegin * 60 + allVisits[i].minuteBegin;
		end[i] = allVisits[i].hourEnd * 60 + allVisits[i].minuteEnd;
	}

	int answerHourBegin = 0;
	int answerMinuteBegin = 0;
	int answerHourEnd = 0;
	int answerMinuteEnd = 0;
	int maxNumberOfVisitors = 0;
	int currentNumberOfVisitors = 0;
	
	int indexBegin = 0;
	int indexEnd = 0;
	while (indexBegin < allVisits.size())
	{
		if (begin[indexBegin] < end[indexEnd])
		{
			++currentNumberOfVisitors;
			if (currentNumberOfVisitors > maxNumberOfVisitors)
			{
				maxNumberOfVisitors = currentNumberOfVisitors;
				answerHourBegin = allVisits[indexBegin].hourBegin;
				answerMinuteBegin = allVisits[indexBegin].minuteBegin;
			}
			++indexBegin;
		}
		else
		{
			answerHourEnd = allVisits[indexEnd].hourEnd;
			answerMinuteEnd = allVisits[indexEnd].minuteEnd;
			--currentNumberOfVisitors;
			++indexEnd;
		}
	}

	std::cout << "Max number of visitors:  " << maxNumberOfVisitors << std::endl;
	std::cout << "Hour begin:  " << answerHourBegin << std::endl;
	std::cout << "Minute begin:  " << answerMinuteBegin << std::endl;
	std::cout << "Hour end:  " << answerHourEnd << std::endl;
	std::cout << "Minute end:  " << answerMinuteEnd << std::endl;

	return 0;
}
