// 154 - Recycling

#include <iostream>
#include "string.h"

using namespace std;

int main()
{
	int  city_no;					
	char city_color[110][5];		
	int  cost[110][110];			
	char line[1000];
	char bins[6] = "PGSAN";
	int  min_city;					
	int  min_no;					
	int  i;
	int  j;
	int  k;


	//read input
	cin >> line;
	while (strcmp(line, "#") != 0)
	{
		//initial
		city_no = 0;

		while (line[0] != 'e')
		{
			//paser input
			for (i = 0; i < 5; i++)
			{
				for (j = 0; j < 5; j++)
					if (line[4*i+2] == bins[j])
						break;

				city_color[city_no][j] = line[4*i];
			}
			city_no++;

			cin >> line;
		}

		for (i = 0; i < city_no; i++)
			for (j = i; j < city_no; j++)
			{
				int diff_no = 0;	
				for (k = 0; k < 5; k++)
					if (city_color[i][k] != city_color[j][k])
						diff_no++;

				//update table
				cost[i][j] = diff_no;
				cost[j][i] = diff_no;
			}

		min_city = 0;
		min_no = 0;
		for (i = 0; i < city_no; i++)
			min_no = min_no + cost[0][i];

		for (i = 0; i < city_no; i++)
		{
			int temp = 0;
			for (j = 0; j < city_no; j++)
				temp = temp + cost[i][j];
			if (temp < min_no)
			{
				min_city = i;
				min_no = temp;
			}
		}

		//output result
		cout << min_city + 1 << endl;

		cin >> line;
	}


	return 0;
}