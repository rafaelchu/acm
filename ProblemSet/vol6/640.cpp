// 640 - Self Numbers

#include <iostream>
#include <math.h>

using namespace std;

void CheckNonSelfNumber(bool table[], long number)
{
	long sum;
	
	sum = number;
	while (true)
	{
		number = sum;
		while (number >= 10)
		{
			sum = sum + number % 10;
			number = number / 10;
		}		
		sum = sum + number;

		if (sum <= 1000000)
		{
			if (table[sum])
				table[sum] = false;
			else
				break;
		}
		else
			break;			
	}	
}


int main()
{
	bool table[1000010];

	long i;

	//initialize (all are self numbers)
	for (i = 0; i <= 1000000; i++)
		table[i] = true;

	for (i = 1; i <= 1000000; i++) 
	{
		if (table[i])
		{
            //output result
			cout << i << endl;
			CheckNonSelfNumber(table, i);
		}		
	}
    
    return 0;
}