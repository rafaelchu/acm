// 530 - Binomial Showdown

#include <iostream>

using namespace std;

long find_ans(long table[][101], long n, long m)
{
	if ((n < 101) && (m < 101))
		return table[n][m];
	else if ((n < m) || (n == 0))
		return 0;
	else if (m == 0)
		return 1;
	else if (m == 1)
		return n;
	else
		return find_ans(table, n-1, m-1) + find_ans(table, n-1, m);
}

int main()
{
	long table[101][101];
	long n;
	long k;
	long ans;

	long i;
	long j;

	// Use dynamic programming to calculate answer.
	for (j = 1; j < 101; j++)
		table[0][j] = 0;
	
	for (i = 0; i < 101; i ++)
		table [i][0] = 1;
	
	for (i = 1; i < 101; i++)
		for (j = 1; j < 101; j++)
		{
			if (i >= j)
				table[i][j] = table[i-1][j-1] + table[i-1][j];
			else
				table[i][j] = 0;
		}

	// Read input
	cin >> n >> k;
	while ((n != 0) || (k != 0))
	{
		if (k > n - k)
			k = n - k;
		ans = find_ans(table, n, k);

		// Output result
		cout << ans << endl;

		cin >> n >> k;
	}

	return 0;
}
