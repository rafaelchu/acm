// 117 - The Postal Worker Rings Once
// Time limit: 3.000 seconds 

#include <iostream>
#include <string.h>
using namespace std;

const long INF = 2000000000;

int main()
{
	char street[20000];
	long cost[26][26];
	int  odd_no;
	int  odd[10];
	long ans;
	int  i;
	int  j;

	//read input
	while (cin >> street)
	{
		//initial
		for (i = 0; i < 26; i++)
			for (j = 0; j < 26; j++)
				cost[i][j] = INF;
		for (i = 0; i < 26; i++)
			cost[i][i] = 0;
		ans = 0;

		while (strcmp(street, "deadend") != 0)
		{
			//轉換路徑的cost
			int len = strlen(street);
			int s = street[0] - 'a';
			int e = street[len-1] - 'a';

			cost[s][e] = len;
			cost[e][s] = len;
			ans = ans + len;

			cin >> street;
		}

		//找出奇數點有哪些
		odd_no = 0;
		for (i = 0; i < 26; i++)
		{
			int temp = 0;
			for (j = 0; j < 26; j++)
			{
				if ((cost[i][j] != 0) && (cost[i][j] != INF))
					temp++;
			}

			if (temp % 2 != 0)
			{
				odd[odd_no] = i;
				odd_no++;
			}
		}

		//如果有奇數點的話, 計算出兩個奇數點最短的距離
		if (odd_no > 0)
		{
			long distance[26];
			bool used[26];
			int  now;

			//initial
			for (i = 0; i < 26; i++)
				used[i] = false;
			now = odd[0];
			for (i = 0; i < 26; i++)
				distance[i] = cost[now][i];
			used[now] = true;

			//找出最短路徑
			for (i = 0; i < 24; i++)
			{
				//找出來目前要從哪一點開始走
				int min = INF;
				int min_pos = -1;
				for (j = 0; j < 26; j++)
					if (!used[j] && (distance[j] < min))
					{
						min = distance[j];
						min_pos = j;
					}
				used[min_pos] = true;

				//更改路徑
				for (j = 0; j < 26; j++)
					if ((distance[min_pos] + cost[min_pos][j] < distance[j]) && (!used[j]))
						distance[j] = distance[min_pos] + cost[min_pos][j];
			}

			//更改答案
			ans = ans + distance[odd[1]];
		}

		//output result
		cout << ans << endl;
	}

	return 0;
}