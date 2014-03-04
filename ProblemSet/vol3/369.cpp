// 369 - Combinations

#include <iostream>

using namespace std;

int main()
{
	long ans[101][101];
	int n;
	int m;

	int i;
	int j;

	for (j = 1; j < 101; j++)
		ans[0][j] = 0;
	
	for (i = 0; i < 101; i ++)
		ans [i][0] = 1;
	
	for (i = 1; i < 101; i++)
		for (j = 1; j < 101; j++)
		{
			if (i >= j)
				ans[i][j] = ans[i-1][j-1] + ans[i-1][j];
			else
				ans[i][j] = 0;
		}

	//read input
	cin >> n >> m;
	while ((n != 0) && (m != 0))
	{
		//output result
		cout << n << " things taken " << m << 
			 " at a time is " << ans[n][m] << " exactly." << endl;

		cin >> n >> m;
	}

	return 0;
}
