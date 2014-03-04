// 594 - One Little, Two Little, Three Little Endians

#include <iostream>

using namespace std;

int main()
{
	long number;
	long ans;
	long temp;
	int  i;

	//read input
	while (cin >> number)
	{
		//initial
		ans = 0;
		temp = number;

		//calculate teh answer
		for (i = 0; i < 3; i++)
		{
			ans = ans | (temp & 255);	//higher 8 bits of ans is the lower 8 bit of temp.
			temp = temp >> 8;
			ans = ans << 8;
		}
		ans = ans | (temp & 255);
		
		//output result
		cout << number << " converts to " << ans << endl;
	}

	return 0;
}