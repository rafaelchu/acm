#include <iostream>

using namespace std;

//-----------------------------
//used[i] 是從 No.0 ~ No.99
//ans[i]  是從 No.1 ~ No.100
//-----------------------------

int main()
{
	int n;
	int m;
	bool find;
	bool used[100];	
	int now_loc;
	int i;
	int j;
	

	cout << "int ans[100] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, " << endl;
	cout << "                0, 0, 0," ;

	for (n = 13; n < 100; n++)
	{		
		m = 1;
		find = false;

		while (!find)
		{
			//initial
			for (i = 0; i < n; i++)
				used[i] = false;
			now_loc = 0;

			for (i = 1; i <= (n - 1); i++)
			{
				if (now_loc == 12)
					break;

				used[now_loc] = true;
				for (j = 1; j <= m; j++)
				{		
					now_loc = (now_loc + 1) % n;
					while (used[now_loc])
					{
						now_loc = (now_loc + 1) % n;
					}									
				}
			}

			if (i == n)
			{
				find = true;
				cout << " " << m << ",";
				if (n % 10 == 0)
					cout << endl << "               ";
			}

			m++;
		}
	}

	return 0;
}
