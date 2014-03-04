// 534 - Frogger

#include <iostream>
#include <stdio.h>
#include <math.h>

using namespace std;

double find_dis(int p1[2], int p2[2])
{
	double a;
	double b;

	a = p2[0] - p1[0];
	b = p2[1] - p1[1];

	return sqrt(a * a + b * b);
}

int main()
{
	int set_no;
	int n;
	int stone[210][2];
	double table[210][210];
	double max;
	int i;
	int j;
	int k;

	//initial
	set_no = 0;

	//read input
	cin >> n;
	while (n != 0)
	{
		//initial
		set_no++;

		//read stone input
		for (i = 0; i < n; i++)
			cin >> stone[i][0] >> stone[i][1];
		for (i = 0; i < n; i++)
			for (j = 0; j < n; j++)
				table[i][j] = find_dis(stone[i], stone[j]);

		//calculate answers
		for (k = 0; k < n; k++)
			for (i = 0; i < n; i++)
				for (j = 0; j < n; j++)
					if (i != j)
					{
						if (table[i][k] >= table[k][j])
							max = table[i][k];
						else
							max = table[k][j];

						if (max < table[i][j])
							table[i][j] = max;
					}

		//output result
		printf("Scenario #%d\n", set_no);
		printf("Frog Distance = %.3lf\n\n", table[0][1]);

		cin >> n;
	}

	return 0;
}