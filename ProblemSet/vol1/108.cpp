// 108 - Maximum Sum
// Time limit: 3.000 seconds 

#include <iostream>
using namespace std;

int main()
{
	int n;
	int rect[105][105];		
	int table[105][105];
	int ans;				// 到目前為止的矩形最大值
	int now;				// 現在正在計算的矩形最大值
	int i;
	int j;
	int k;

	// Read input.
	cin >> n;
	for (i = 0; i < n; i++)
		for (j = 0; j < n; j++)
			cin >> rect[i][j];

	// Initialize table.
	for (i = 0; i < n; i++)
		table[i][0] = rect[i][0];
	for (i = 0; i < n; i++)		
		for (j = 1; j < n; j++)
			table[i][j] = table[i][j-1] + rect[i][j];

	// Calculate the answer.
	ans = 0;
	for (j = 0; j < n; j++)
		for (k = 0; j + k < n; k++)
		{
			now = 0;
			for (i = 0; i < n; i++)
			{
				now = now + table[i][j+k] - table[i][j] + rect[i][j];
				if (now < 0)
					now = 0;

				if (now > ans)
					ans = now;
			}
		}

	// Output results.
	cout << ans << endl;

	return 0;
}