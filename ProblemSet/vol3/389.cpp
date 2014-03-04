// 389 - Basically Speaking

#include <iostream>
#include "stdio.h"
#include "math.h"

using namespace std;

//convert digit to int
int change_digit(char digit)
{
	if (digit == ' ')
		return 0;
	else if ((digit >= 'A') && (digit <= 'Z'))
		return digit - 'A' + 10;
	else if ((digit >= 'a') && (digit <= 'z'))
		return digit - 'a' + 10;
	else
		return digit - '0';
}


int main ()
{
	char digit;
	int  number[7];
	int  old_base;
	int  new_base;
	long sum;			
	long product;		
	long qurtor;		

	int  i;

	while (scanf("%c", &digit) == 1)
	{
		//read input
		number[0] = change_digit(digit);

		for (i = 1; i < 7; i++)			
		{
			scanf("%c", &digit);
			number[i] = change_digit(digit);
		}
		
		scanf("%d", &old_base);					
		scanf("%d", &new_base);					

		//calculate
		sum = 0;
		for (i = 0; i < 7 ; i++)		
			sum += number[i] * static_cast<int>(pow(old_base, 6 - i));			
		
		//output result		
		product = static_cast<int>(pow(new_base, 7));		

		if (sum >= product)		
			cout << "  ERROR";
		else 
		{
			bool printed = false;	
			for (i = 0; i < 7; i++)
			{
				product = static_cast<int>(pow(new_base, 6 - i));
				qurtor   = sum / product;	

				if (qurtor > 0)
				{					
					if (qurtor >= 10)
						cout << static_cast<char>(qurtor - 10 + 'A');
					else
						cout << qurtor;

					sum -= product * qurtor;
					printed = true;
				}
				else if (printed || (i == 6))
					cout << 0;
				else
					cout << ' ';
			}
		}

		cout << endl;
		scanf("%c", &digit);
	}

	return 0;
}