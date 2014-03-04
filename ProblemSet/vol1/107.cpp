// 107 - The Cat in the Hat
// Time limit: 3.000 seconds 

#include <iostream>
#include <math.h>
#include <stdlib.h>
using namespace std;

int main()
{
	long ini_height;
	long worker;
	long not_worker;
	long all_height;
	long x;
	long y;
	long w;
	long z;
	long i;

	//read input
	cin >> ini_height >> worker;
	while ((ini_height != 0) || (worker != 0))
	{		
		if (ini_height - worker == 1)
		{
			x = worker;
			y = 1;
		}
		else if (ini_height == 1) 
		{
			x = 1;
			y = 0;
		}
		else
		{
			bool find = false;
			//找出來每個帽子裝x隻貓，共有y層
			for (y = 2; true; y++)
			{
				for (x = (long)exp(log((double)worker) / y); true; x++)
				{
					long value = (long)pow((double)x, (int)y);
					if (value == worker)
					{
						value = (long)pow((double)(x + 1), (int)y);
						if (value == ini_height)
							find = true;							
						break;
					}
					else if (value > worker)
						break;
				}
				if (find)
					break;
			}
		}

		//find answer
		not_worker = 0;
		all_height = worker;
		w = 1;
		z = worker;
		for (i = 0; i < y; i++)
		{
			w = w * (x + 1);
			z = z / x;
			not_worker = not_worker + z;
			all_height = all_height + w * z;
		}

		//output result
		cout << not_worker << " " << all_height << endl;

		cin >> ini_height >> worker;
	}

	return 0;
}