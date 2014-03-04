// 620 - Cellular Structure

#include <iostream>
#include "string.h"

using namespace std;

//check research.
int check(char organism[], int start, int end)
{
	if (start > end)
	{
		return 3;				//MUTANT
	}
	else if (start == end)
	{
		if (organism[start] == 'A')
			return 0;			//SIMPLE
		else
			return 3;			//MUTANT
	}
	else if ((organism[end - 1] == 'A') && (organism[end] == 'B'))
	{
		if (check(organism, start, end - 2) != 3)
			return 1;			//FULLY-GROWN
		else
			return 3;			//MUTANT
	}
	else if ((organism[start] == 'B') && (organism[end] == 'A'))
	{
		if (check(organism, start + 1, end - 1) != 3)
			return 2;			//MUTAGENIC
		else
			return 3;			//MUTANT
	}
	else 
	{
		return 3;				//MUTANT
	}
}

int main()
{
	int number;
	char organism[10000];
	int start;
	int end;
	int result;

	int i;

	//read input
	cin >> number;
	for (i = 0; i < number; i++) 
	{
		cin >> organism;

		//check research
		start = 0;
		end = strlen(organism) - 1;
		result = check(organism, start, end);

        // output result
		switch (result)
		{
		case 0: cout << "SIMPLE" << endl;      break;
		case 1: cout << "FULLY-GROWN" << endl; break;
		case 2: cout << "MUTAGENIC" << endl;   break;
		case 3: cout << "MUTANT" << endl;	   break;
		}
	}

	return 0;
}