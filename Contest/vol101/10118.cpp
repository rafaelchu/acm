// @JUDGE_ID: 5084AA 10118 C++ "<a href=http://go.to/hoshiko_acm>星子的ACM小窩</a>" 
// Problem: Free Candies
#include <iostream.h>

void find_ans(long pile[][4], long top[], long basket_no, long basket[], long temp_ans, long& ans)
{
	long basket2[5];
	bool find;
	long i;
	long j;

	//basket塞滿囉
	if (basket_no == 5)
	{
		if (temp_ans > ans)
			ans = temp_ans;
		return;
	}

	//繼續往下拿
	for (i = 0; i < 4; i++)
		if (top[i] >= 0)
		{
			//檢查有沒有在basket中
			find = false;
			for (j = 0; j < basket_no; j++)
				if (pile[top[i]][i] == basket[j])
				{
					find = true;
					break;
				}
				else
					basket2[j] = basket[j];

			if (j >= basket_no)
				basket2[j] = pile[top[i]][i];
			else
			{
				for (; j + 1 < basket_no; j++)
					basket2[j] = basket[j+1];
				j--;
			}

			top[i]--;
			if (find)
				find_ans(pile, top, j + 1, basket2, temp_ans + 1, ans);
			else
				find_ans(pile, top, j + 1, basket2, temp_ans, ans);
			top[i]++;
		}
}

int main()
{
	long n;
	long pile[45][4];
	long top[4];
	long basket[5];
	long ans;
	long i;
	long j;

	//read input
	cin >> n;
	while (n > 0)
	{
		for (i = 0; i < n; i++)
			for (j = 0; j < 4; j++)
				cin >> pile[n-1-i][j];

		//initial
		for (i = 0; i < 4; i++)
			top[i] = n - 1;

		//find answer
		ans = 0;
		find_ans(pile, top, 0, basket, 0, ans);

		//output result
		cout << ans << endl;

		cin >> n;
	}

	return 0;
}