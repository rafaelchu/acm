// 636 - Squares (III)

#include <iostream>
#include "string.h"
#include "math.h"

using namespace std;

const int MAX_D = 100;

//check this value is square or not
bool check_sqr(long sqr[], long sum)
{
	bool find;

	find = false;
	for (long i = 0; sqr[i] <= sum; i++)
	{
		if (sqr[i] == sum)
		{
			find = true;
			break;
		}
	}

	return find;
}


int main()
{
	long sqr[32000];
	char digit[MAX_D];
	int digit_no;
	long sum;
	int  base;
	long i;

	//initialize squares from 0 to 39999
	for (i = 0; i < 32000; i++)
		sqr[i] = i * i;

	//read input
	cin >> digit;
	while (digit[0] != '0')
	{
		digit_no = strlen(digit);

		//find minimum possible base
		base = digit[0] - '0';
		for (i = 1; i < digit_no; i++)
		{
			if (base < (digit[i] - '0'))
				base = digit[i] - '0';
		}
		base++;

		//find minimum base
		while (true)
		{
			//calculate sum
			sum = digit[digit_no - 1] - '0';
			for (i = digit_no - 2; i >= 0; i--)
			{
				sum = sum + static_cast<int>(pow(base, digit_no - 1 -i)) * (digit[i] - '0');
			}

			//output result
			if (check_sqr(sqr, sum))
			{
				cout << base << endl;		
				break;
			}
		
			base++;
		}

        //read input
		cin >> digit;
	}

	return 0;
}