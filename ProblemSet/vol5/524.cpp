// 524- Prime Ring Problem

#include <iostream>

using namespace std;

void find_ans(long prime[], long n, bool used[], long ans_no, long ans[])
{
	long i;
	long j;

	if (ans_no == n)
	{
		for (j = 0; j < 12; j++)
			if (ans[0] + ans[ans_no-1] == prime[j])						
				break;
		if (j < 12)
		{
			cout << ans[0];
			for (i = 1; i < ans_no; i++)
				cout << " " << ans[i];
			cout << endl;
		}
	}
	else
	{
		for (i = 1; i <= n; i++)
			if (!used[i-1])
			{
				bool ok = false;

				if (ans_no == 0)
					ok = true;
				else
				{
					for (j = 0; j < 12; j++)
						if (ans[ans_no-1] + i == prime[j])						
							break;
					if (j < 12)
						ok = true;

					for (j = 0; (j < 12) && ok; j++)
						if (i + ans[0] == prime[j])						
							break;	
					if ((j < 12) && ok)
						ok = true;
				}

				// add i
				if (ok)
				{
					ans[ans_no] = i;
					used[i-1] = true;
					find_ans(prime, n, used, ans_no +1, ans);
					used[i-1] = false;
				}
			}
	}

}

int main()
{
	long set_no;
	long prime[12] = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37};
	bool used[20];
	long ans[20];
	long n;
	long i;

	//initial
	set_no = 0;

	//read input
	while (cin >> n)
	{
		//initial
		set_no++;
		for (i = 0 ; i < n; i++)
			used[i] = false;
		ans[0] = 1;
		used[0] = true;

		//output result
		if (set_no > 1)
			cout << endl;
		cout << "Case " << set_no << ":" << endl;
		find_ans(prime, n, used, 1, ans);
	}

	return 0;
}