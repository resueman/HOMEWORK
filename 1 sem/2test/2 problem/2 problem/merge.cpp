#include "merge.h"

using namespace std;

string merge(List*& list1, List*& list2)
{
	auto* temp1 = getHead(list1);
	auto* temp2 = getHead(list2);
	std::string answer = "";
	while (temp1 != nullptr && temp2 != nullptr)
	{
		bool result = true;
		result = getNumber(temp1) < getNumber(temp2);

		if (result)
		{
			answer += to_string(getNumber(temp1)) + " ";
			temp1 = getNext(temp1);
		}
		else
		{
			answer += to_string(getNumber(temp2)) + " ";
			temp2 = getNext(temp2);
		}
	}
	while (temp1 != nullptr)
	{
		answer += to_string(getNumber(temp1)) + " ";
		temp1 = getNext(temp1);
	}
	while (temp2 != nullptr)
	{
		answer += to_string(getNumber(temp2)) + " ";
		temp2 = getNext(temp2);
	}

	return answer;
}
