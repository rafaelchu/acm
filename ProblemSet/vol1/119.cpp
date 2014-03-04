// 119 - Greedy Gift Givers
// Time limit: 3.000 seconds

#include <iostream>
#include <string.h>
using namespace std;

int main()
{	
	int  test_no;
	int  number;
	char name[15][20];
	char person_name[20];
	int  person_now;
	long money;
	int  gift_no;
	long networth[15];
	int  i;
	int  j;

	// Initialize.
	test_no = 0;

	// Read intput.
	while (cin >> number)
	{
		test_no++;
		for (i = 0; i < number; i++)		
			cin >> name[i];
		
		// Initialize.
		for (i = 0; i < 15; i++)
			networth[i] = 0;

		// Calculate the answer.
		for (i = 0; i < number; i++)
		{
			cin >> person_name;
			cin >> money;
			cin >> gift_no;

			if (gift_no != 0)
			{
				for (person_now = 0; person_now < number; person_now++)
					if (strcmp(name[person_now], person_name) == 0)
						break;

				// 扣掉此次收入的錢.
				networth[person_now] = networth[person_now] - money;

				// 加上分給別人的錢.
				for (j = 0; j < gift_no; j++)
				{
					int k;

					cin >> person_name;
					for (k = 0; k < number; k++)
						if (strcmp(name[k], person_name) == 0)
							break;

					networth[k] = networth[k] + (money / gift_no);
				}

				// 加上發完禮物後剩下的錢.
				networth[person_now] = networth[person_now] + (money % gift_no);
			}
		}

		// Print output
		if (test_no != 1)
			cout << endl;
		for (i = 0; i < number; i++)
			cout << name[i] << ' ' << networth[i] << endl;		
	}

	return 0;
}