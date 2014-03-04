// 567 - Risk

#include <iostream>
#include <stdio.h>

using namespace std;

const int INF = 30000;

int main()
{
	int set_no;
	int cost[20][20];
	int x;
	int p_s;
	int p_e;
	int i;
	int j;
	int k;

	//initial
	set_no = 0;

	//read input
	while (cin >> x)
	{
		//initial
		set_no++;
		for (i = 0; i < 20; i++)
			for (j = 0; j < 20; j++)
				cost[i][j] = INF;
		for (i = 0; i < 20; i++)
			cost[i][i] = 0;

		//read input
		for (i = 0; i < 19; i++)
		{			
			for (j = 0; j < x; j++)
			{
				cin >> p_e;
				cost[i][p_e-1] = 1;
				cost[p_e-1][i] = 1;
			}
			
			cin >> x;
		}

		//calculate the shortest path of all-pair
		for (k = 0; k < 20; k++)
		{
			for (i = 0; i < 20; i++)
				for (j = 0; j < 20; j++)
					if (cost[i][k] + cost[k][j] < cost[i][j])
						cost[i][j] = cost[i][k] + cost[k][j];
		}

		//output result
		printf("Test Set #%d\n", set_no);
		for (i = 0; i < x; i++)
		{
			cin >> p_s >> p_e;
			printf("%2d to %2d: %d\n", p_s, p_e, cost[p_s-1][p_e-1]);
		}
		printf("\n");
	}

	return 0;
}
