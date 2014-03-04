// 144 - Student Grants

#include <iostream>
#include <iomanip>

using namespace std;

int main()
{
	int n;
	int k;
	int money[25];
	int atm_money;		
	int coin;			
	int leave_no;
	int now_std;
	int i;

	//read input
	cin >> n >> k;
	while ((n != 0) && (k != 0))
	{
		//initial
		for (i = 0; i < n; i++)
			money[i] = 0;
		atm_money = 0;
		coin = 0;
		leave_no = 0;
		now_std = -1;

		while (leave_no < n)
		{
			if (atm_money == 0)
			{
				coin++;
				if (coin > k)
					coin = 1;
				atm_money = coin;
			}

			now_std = (now_std + 1) % n;
			while (money[now_std] >= 40)
				now_std = (now_std + 1) % n;
				

			if (money[now_std] + atm_money <= 40)
			{				
				money[now_std] = money[now_std] + atm_money;
				atm_money = 0;

				if (money[now_std] == 40)
				{
					leave_no++;
					//print putput
					cout << setw(3) << now_std + 1;
				}
			}
			else
			{
				atm_money = atm_money - (40 - money[now_std]);
				money[now_std] = 40;

				leave_no++;				
				//print putput
				cout << setw(3) << now_std + 1;
			}
		}

		cout << endl;
		cin >> n >> k;
	}

	return 0;
}