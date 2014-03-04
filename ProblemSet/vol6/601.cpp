// 601 - The PATH

#include <iostream>

using namespace std;

bool check_white(long n, char table[][85], bool walk[][85], long row, long col)
{
	if ((row < 0) || (row >= n) || (col < 0) || (col >= n))
		return false;
	if (walk[row][col])
		return false;
	if (table[row][col] != 'W')
		return false;

	//answer!!
	if (col == n - 1)
		return true;

	walk[row][col] = true;

	if (check_white(n, table, walk, row, col + 1))	//right
		return true;
	if (check_white(n, table, walk, row + 1, col))	//down
		return true;
	if (check_white(n, table, walk, row - 1, col))	//up
		return true;
	if (check_white(n, table, walk, row, col - 1))	//left
		return true;

	return false;
}

bool check_black(long n, char table[][85], bool walk[][85], long row, long col)
{
	if ((row < 0) || (row >= n) || (col < 0) || (col >= n))
		return false;
	if (walk[row][col])
		return false;
	if (table[row][col] != 'B')
		return false;

	//answer!!
	if (row == n -1)
		return true;

	walk[row][col] = true;

	if (check_black(n, table, walk, row + 1, col))	//down
		return true;
	if (check_black(n, table, walk, row, col + 1))	//right
		return true;
	if (check_black(n, table, walk, row, col - 1))	//left
		return true;
	if (check_black(n, table, walk, row - 1, col))	//up
		return true;

	return false;
}

long find_ans(long n, char table[][85])
{
	bool walk[85][85];
	bool walk2[85][85];
	bool ans;
	long i;
	long j;
	long ur;
	long uc;

	//initial
	for (i = 0; i < n; i++)
		for (j = 0; j < n; j++)
			walk[i][j] = false;
	ans = false;

	//check WHITE is passed or not
	for (i = 0; (i < n) && !ans; i++)
		if (!walk[i][0] && (table[i][0] == 'W'))
			ans = check_white(n, table, walk, i, 0);
	if (ans)
		return 1;

	//check BLACK is passed or not
	for (i = 0; (i < n) && !ans; i++)
		if (!walk[0][i] && (table[0][i] == 'B'))
			ans = check_black(n, table, walk, 0, i);
	if (ans)
		return 2;

	//check WHITE + U is passed or not
	for (ur = 0; ur < n; ur++)
		for (uc = 0; uc < n; uc++)
			if (table[ur][uc] == 'U') 
			{
				//check U is usefull or not
				int w_no = 0;

				if (ur - 1 >= 0)
					if ((table[ur-1][uc] == 'W') && (walk[ur-1][uc]))
						w_no++;
				if (uc - 1 >= 0)
					if ((table[ur][uc-1] == 'W') && (walk[ur][uc-1]))
						w_no++;
				if (ur + 1 < n)
					if ((table[ur+1][uc] == 'W') && (walk[ur+1][uc]))
						w_no++;
				if (uc + 1 < n)
					if ((table[ur][uc+1] == 'W') && (walk[ur][uc+1]))
						w_no++;

				if (w_no > 0)
				{
					for (i = 0; i < n; i++)
						for (j = 0; j < n; j++)
							walk2[i][j] = walk[i][j];

					//check WHITE is passed or not
					table[ur][uc] = 'W';
					ans = check_white(n, table, walk2, ur, uc);
					if (ans)
						return 3;
					table[ur][uc] = 'U';
				}
			}

	//check BLACK + U is passed or not
	for (ur = 0; ur < n; ur++)
		for (uc = 0; uc < n; uc++)
			if (table[ur][uc] == 'U') 
			{
				//check U is usefull or not
				int w_no = 0;

				if (ur - 1 >= 0)
					if ((table[ur-1][uc] == 'B') && (walk[ur-1][uc]))
						w_no++;
				if (uc - 1 >= 0)
					if ((table[ur][uc-1] == 'B') && (walk[ur][uc-1]))
						w_no++;
				if (ur + 1 < n)
					if ((table[ur+1][uc] == 'B') && (walk[ur+1][uc]))
						w_no++;
				if (uc + 1 < n)
					if ((table[ur][uc+1] == 'B') && (walk[ur][uc+1]))
						w_no++;

				if (w_no > 0)
				{
					for (i = 0; i < n; i++)
						for (j = 0; j < n; j++)
							walk2[i][j] = walk[i][j];

					//check BLACK is passed or not
					table[ur][uc] = 'B';

					ans = check_black(n, table, walk2, ur, uc);
					if (ans)
						return 4;
					table[ur][uc] = 'U';
				}
			}

	return 5;
}

int main()
{
	long n;
	char table[85][85];
	long ans;
	long i;
	long j;

	//read input
	cin >> n;
	while (n > 0)
	{
		for (i = 0; i < n; i++)
			for (j = 0; j < n; j++)
				cin >> table[i][j];

		//find answer
		ans = find_ans(n, table);

		//output result
		if (ans == 1)
			cout << "White has a winning path." << endl;
		else if (ans == 2)
			cout << "Black has a winning path." << endl;
		else if (ans == 3)
			cout << "White can win in one move." << endl;
		else if (ans == 4)
			cout << "Black can win in one move." << endl;
		else 
			cout << "There is no winning path." << endl;

		cin >> n;
	}

	return 0;
}