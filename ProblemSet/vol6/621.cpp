// 621 - Secret Research

#include <iostream>
#include "string.h"

using namespace std;

int main()
{
	int number;
	char digit[10000];
	int i;

	//read input
	cin >> number;
	for (i = 0; i < number; i++) 
	{
		cin >> digit;

		//output result
		if ((strcmp(digit, "1") == 0) || (strcmp(digit, "4") == 0) ||
			 (strcmp(digit, "78") == 0))
		{
			cout << '+' << endl;
		}
		else
		{
			int len = strlen(digit);

			if ((digit[len - 2] == '3') && (digit[len - 1] == '5'))
				cout << '-' << endl;
			else if ((digit[0] == '9') && (digit[len - 1] == '4'))
				cout << '*' << endl;
			else if ((digit[0] == '1') && (digit[1] == '9') &&
				      (digit[2] == '0'))
				cout << '?' << endl;
		}
	}

	return 0;
}