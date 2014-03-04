// 574 - Sum It Up

#include <iostream>

using namespace std;

const int INF = 10000;

bool equal(int n1[], int n2[])
{
	int i;

	for (i = 0; i < 15; i++)
		if (n1[i] != n2[i])
			return false;

	return true;
}

void find_ans(int t, int n, int now, int number[], bool used[], int& ans_no, int ans[][15])
{
	int i;
	int j;

	if ((now < n) && (t >= 0))
	{		
		if (t - number[now] == 0)
		{
			//get one answer.
			used[now] = true;

			j = 0;
			for (i = 0; i < n; i++)
			{
				if (used[i])
					ans[ans_no][j++] = number[i];
			}
			for (; j < 15; j++)
				ans[ans_no][j] = INF;
			ans_no++;

			//check the duplicated.
			for (i = 0; i < ans_no - 1; i++)
				if (equal(ans[i], ans[ans_no-1]))
					break;
			if (i < ans_no - 1)
				ans_no--;
		}

		//find next answer.
		used[now] = true;
		find_ans(t - number[now], n, now + 1, number, used, ans_no, ans);
		used[now] = false;
		find_ans(t              , n, now + 1, number, used, ans_no, ans);
	}
}

int main()
{
	int  t;
	int  n;
	int  number[15];
	bool used[15];
	int  ans_no;
	int  ans[4200][15];
	int  i;
	int  j;

	//read input
	cin >> t >> n;
	while (n > 0)
	{
		for (i = 0; i < n; i++)
			cin >> number[i];

		//sort number
		for (i = 0; i < n - 1; i++)
		{
			int max = i;
			for (j = i + 1; j < n; j++)
				if (number[j] > number[max])
					max = j;
			int temp = number[i];
			number[i] = number[max];
			number[max] = temp;
		}

		//initial
		for (i = 0; i < n; i++)
			used[i] = false;
		ans_no = 0;

		//find the answer.
		cout << "Sums of " << t << ":" << endl;
		find_ans(t, n, 0, number, used, ans_no, ans);	

		//check ans
		if (ans_no == 0)
			cout << "NONE" << endl;
		else
		{
			//output result
			for (i = 0; i < ans_no; i++)
			{
				cout << ans[i][0];
				for (j = 1; j < 15; j++)
					if (ans[i][j] != INF)
						cout << "+" << ans[i][j];
					else
						break;
				cout << endl;
			}
		}

		cin >> t >> n;
	}

	return 0;
}