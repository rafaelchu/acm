// 541 - Error Correction

#include <iostream>

using namespace std;

int main()
{
	int n;
	int code[100][100];
	int row_sum[100];
	int row_odd;
	int col_sum[100];
	int col_odd;
	int i;
	int j;

	//read input
	cin >> n;
	while (n > 0)
	{
		for (i = 0; i < n; i++)
			for (j = 0; j < n; j++)
				cin >> code[i][j];

		//Calculate sum of row and col
		for (i = 0; i < n; i++)
		{
			row_sum[i] = 0;
			for (j = 0; j < n; j++)
				row_sum[i] = row_sum[i] + code[i][j];
		}
		col_odd = 0;
		for (j = 0; j < n; j++)
		{
			col_sum[j] = 0;
			for (i = 0; i < n; i++)
				col_sum[j] = col_sum[j] + code[i][j];
		}

		//Calculate odd number of row and col
		row_odd = -1;
		for (i = 0; i < n; i++)
			if (row_sum[i] % 2 == 1)
			{
				if (row_odd == -1)
					row_odd = i;
				else
					break;
			}
		col_odd = -1;
		for (j = 0; j < n; j++)
			if (col_sum[j] % 2 == 1)
			{
				if (col_odd == -1)
					col_odd = j;
				else
					break;
			}

		//output result
		if ((i < n) || (j < n))
			cout << "Corrupt" << endl;
		else if ((row_odd == -1) && (col_odd == -1))
			cout << "OK" << endl;
		else if ((row_odd != -1) && (col_odd != -1))
			cout << "Change bit (" << row_odd+1 << "," << col_odd+1 << ")" << endl;
		else
			cout << "Corrupt" << endl;

		cin >> n;
	}


	return 0;
}