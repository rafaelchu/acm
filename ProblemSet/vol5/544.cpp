// 544 - Heavy Cargoe

#include <iostream>
#include <string.h>

using namespace std;

int main()
{
	int set_no;
	int n;
	int r;
	int city_no;
	char city[210][40];
	int table[210][210];
	char c1[40];
	char c2[40];
	int p;
	int min;
	int i;
	int j;
	int k;

	//initial
	set_no = 0;

	//read input
	cin >> n >> r;
	while ((n != 0) && (r != 0))
	{
		//initial
		set_no++;
		for (i = 0; i < n; i++)
			for (j = 0; j < n; j++)
				table[i][j] = 0;
		city_no = 0;

		for (i = 0; i < r; i++)
		{
			cin >> c1 >> c2 >> p;

			for (j = 0; j < city_no; j++)
				if (strcmp(c1, city[j]) == 0)
					break;
			if (j >= city_no)
			{
				//add city
				strcpy(city[j], c1);
				city_no++;
			}

			for (k = 0; k < city_no; k++)
				if (strcmp(c2, city[k]) == 0)
					break;
			if (k >= city_no)
			{
				//add city
				strcpy(city[k], c2);
				city_no++;
			}

			table[j][k] = p;
			table[k][j] = p;
		}
		cin >> c1 >> c2;

		//calculate answer
		for (k = 0; k < n; k++)
			for (i = 0; i < n; i++)
				for (j = 0; j < n; j++)
					if (i != j)
					{
						if ((table[i][k] == 0) || (table[k][j] == 0))
							min = 0;
						else if (table[i][k] <= table[k][j])
							min = table[i][k];
						else
							min = table[k][j];

						if (min > table[i][j])
							table[i][j] = min;
					}

		//output result
		cout << "Scenario #" << set_no << endl;
		for (i = 0; i < city_no; i++)
			if (strcmp(c1, city[i]) == 0)
				break;
		for (j = 0; j < city_no; j++)
			if (strcmp(c2, city[j]) == 0)
				break;
		cout << table[i][j] << " tons" << endl << endl;

		cin >> n >> r;
	}

	return 0;
}