// 200 - Rare Order

#include <iostream>
using namespace std;

void a_connect_b (long table[][26], long alpha_no, int a, int b)
{
	long i;

	if (table[a][b] == 0)
	{
		table[a][b] = 1;

		for (i = 0; i < alpha_no; i++)
		{
			if(table[b][i] == 1)	// Connect a to all characters connected by b.
				table[a][i] = 1;

			if(table[i][a] == 1)	// Connect all characters connected by a to b.
				table[i][b] = 1;
		}  
	}
}

int main()
{
	long table[26][26];		// The path from row to column.
	char line[2][100];	
	bool used[26];			// What English characters are used.
	long ans[26];
	long i;
	long j;

	//initial
	for (i = 0; i < 26; i++)
		for (j = 0; j < 26; j++)
			table[i][j] = 0;
	for (i = 0; i < 26; i++)
		used[i] = false;

	i = 0;
	cin.getline(line[i%2], 100);
	for (i = 1; true; i++)
	{
		cin.getline(line[i%2], 100);
		if (strcmp(line[i%2], "#") == 0)
			break;

		j = 0;
		while ((line[(i-1)%2][j] == line[i%2][j])  && (line[(i-1)%2][j] != 0) && (line[i%2][j] != 0))
			j++;

		if ((line[(i-1)%2][j] != 0) && (line[i%2][j] != 0))
		{
			a_connect_b(table, 26, line[(i-1)%2][j] - 'A', line[i%2][j] - 'A');
			used[line[(i-1)%2][j] - 'A'] = true;
			used[line[i%2][j] - 'A'] = true;
		}
	}
		
	// Initial
	for (i = 0; i < 26; i++)
		if (used[i])
			ans[i] = 0;
		else
			ans[i] = -1;
	for (j = 0; j < 26; j++)
		for (i = 0; i < 26; i++)
			if (used[i] && used[j])
				ans[j] = ans[j] + table[i][j];

	// Topological sort
	while ( true )
	{
		for (i = 0; i < 26; i++)
			if ((ans[i] == 0) && used[i])
			{
				cout << char('A' + i) ;	//output result
				break;
			}

		if (i < 26)
		{
			for (j = 0; j < 26; j++)
				if (table[i][j] == 1)
					ans[j]--;
			used[i] = false;
		}
		else
			break;
	}
	cout << endl;

	return 0;
}