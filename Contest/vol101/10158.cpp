// @JUDGE_ID: 5084AA 10158 C++ "<a href=http://go.to/hoshiko_acm>星子的ACM小窩</a>" 
// Problem: War
#include <iostream.h>

int main()
{
	long n;
	long people[10000];
	long c;
	long x;
	long y;

	//read input
	cin >> n;

	//initial
	for (i = 0; i < n; i++)
		people[i] = -1;

	//read input
	while (cin >> c >> x >> y)
	{
		if (c == 1)				//setFriends
		{
			//check
			if (people[x] == NONE && people[y] == NONE)
			{
				people[x] = 0;
				people[y] = 0;
			}
			else if (people[x] == NONE)
			{
				people[x] = person[y];
			}
			else if (people[y] == NONE)
			{
				people[y] = person[x];
			}
			else if (person[x] != person[y])
			{
				cout << -1;
			}
		}
		else if (c == 2)		//setEnemies
		{
		}
		else if (c == 3)		//areFriends
		{
		}
		else					//areEnemies
		{
		}
	}


	return 0;
}