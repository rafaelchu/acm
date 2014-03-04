// 539 - The Settlers of Catan

#include <iostream>

using namespace std;

//Find out the longest path
void find_ans(int n, bool path[][30], int s_point, int now, int& ans)
{
	int i;

	for (i = 0; i < n; i++)
		if (path[s_point][i])
		{
			if (now > ans)
				ans = now;

			//Go to next step
			path[s_point][i] = false;
			path[i][s_point] = false;
			find_ans(n, path, i, now + 1, ans);
			path[s_point][i] = true;
			path[i][s_point] = true;
		}
}

int main()
{
 	int  n;
	int  m;
	bool path[30][30];
	int  ans;
	int  p;
	int  q;
	int  max;
	int  i;
	int  j;

	//read input
	cin >> n >> m;
	while ((n > 0) && (m > 0))
	{
		//initial
		for (i = 0; i < n; i++)
			for (j = 0; j < n; j++)
				path[i][j] = false;
		for (i = 0; i < m; i++)
		{
			cin >> p >> q;
			path[p][q] = true;
			path[q][p] = true;
		}

		//find out the longest path
		max = 0;
		for (i = 0; i < n; i++)
		{
			ans = 0;
			find_ans(n, path, i, 1, ans);
			if (ans > max)
				max = ans;
		}		

		//output result					
		cout << max << endl;

		cin >> n >> m;
	}

	return 0;
}