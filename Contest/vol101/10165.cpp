// @JUDGE_ID: 5084AA 10165 C++ "<a href=http://go.to/hoshiko_acm>�P�l��ACM�p��</a>" 
// Problem: Stone Game
#include <iostream.h>

bool win(long n, long p[])
{
	long i;

	for (i = 0; i < n; i++)
		if (p[i] > 0)
			if (p[i] == 2)
			{
				p[i]--;				//��1��
				if (!win(n, p))
				{
					p[i] = p[i] + 1;
					return true;
				}

				p[i]--;				//��2��
				if (!win(n, p))
				{
					p[i] = p[i] + 2;
					return true;
				}

				p[i] = p[i] + 2;
			}
			else
			{
				p[i]--;				//��1��
				if (!win(n, p))
				{
					p[i] = p[i] + 1;
					return true;
				}

				p[i] = p[i] + 1;
			}

	return false;
}

int main()
{
	long n;
	long p[1000];
	bool ans;
	long i;

	//read input
	cin >> n;
	while (n > 0)
	{
		for (i = 0; i < n; i++)
		{
			cin >> p[i];
			if (p[i] >= 2)
				p[i] = 2;
		}

		//�p�⵪��
		ans = win(n, p);

		//output result
		if (ans)
			cout << "Yes" << endl;
		else
			cout << "No" << endl;

		cin >> n;
	}

	return 0;
}