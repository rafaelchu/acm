// 331 - Mapping the Swaps

#include <iostream>

using namespace std;

void find_ans(int n, int test[], int preloc, long now_len, long& len, long& ans)
{
	int temp;
	int i;

	if (now_len > len)
		return;

	for (i = 0; i < n - 1; i++)
		if (test[i] > test[i+1])
			break;

	if (i >= n - 1)
	{
		//array is sorted
		if (now_len == len)
			ans++;
		else if (now_len < len)
		{
			len = now_len;
			ans = 1;
		}
	}
	else
	{
		//continue finding
		for (i = 0; i < n -1; i++)
			if (i != preloc)
			{
				temp = test[i];
				test[i] = test[i+1];
				test[i+1] = temp;

				find_ans(n, test, i, now_len+1, len, ans);

				temp = test[i+1];
				test[i+1] = test[i];
				test[i] = temp;
			}
	}	
}

int main()
{
	int set_no;
	int n;
	int test[10];
	long len;
	long ans;
	int i;
	int j;

	//initial
	set_no = 0;

	//read input
	cin >> n;
	while (n > 0)
	{
		for (i = 0; i < n; i++)
			cin >> test[i];

		//initial
		set_no++;
		len = 0;
		ans = 0;

		//use bubble sort to find the possible answer
		int test2[10];
		for (i = 0; i < n; i++)
			test2[i] = test[i];
		for (i = 1; i < n; i++)
			for (j = 0; j < n - i; j++)
				if (test2[j] > test2[j+1])
				{
					int temp = test2[j];
					test2[j] = test2[j+1];
					test2[j+1] = temp;
					len++;
				}		

		if (len > 0)			
			find_ans(n, test, -1, 0, len, ans);		//find answer

		//output result
		cout << "There are " << ans << " swap maps for input data set " << set_no << "." << endl;

		cin >> n;
	}

	return 0;
}