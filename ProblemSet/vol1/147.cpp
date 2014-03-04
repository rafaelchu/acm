// 147 - Dollars
#include <stdio.h>
#include <iostream>

using namespace std;

int main()
{
	float value;
	long number;
	long ans[1010][11];
	long money[11] = {0, 1, 2, 4, 10, 20, 40, 100, 200, 400, 1000};
	int i;
	int j;

	//initial
	for (i = 1; i <= 1000; i++)
		ans[i][1] = 1;
	for (i = 1; i <= 10; i++)
		ans[1][i] = 1;

	for (i = 2; i <= 1000; i++)
	{
		for (j = 2; j <= 10; j++)
			if (i < money[j])
				ans[i][j] = ans[i][j-1];
			else if (i == money[j])
				ans[i][j] = ans[i][j-1] + 1;
			else
				ans[i][j] = ans[i][j-1] + ans[i-money[j]][j];
	}

	//Read input
	scanf("%f", &value);
	
	while (value > 0.00) 	
	{
		number = (long)(value*100.0+0.5);
		number = number / 5;

		//output result
		printf("%5.2f%12ld\n", value, ans[number][10]);

		scanf("%f", &value);
	}

	return 0;
}