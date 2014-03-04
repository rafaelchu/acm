// 383 - Shipping Routes

#include <iostream>
#include "stdio.h"
#include "string.h"

using namespace std;

const int INF = 200000000;

int main()
{
	int  set_no;
	int  now_set;
	char house[30][4];
	int  route[30][30];
	int  m;
	int  n;
	int  p;
	int  place_s;
	int  place_e;
	int  ship_no;	
	int  i;
	int  j;
	int  k;

	//initial
	now_set = 0;

	//read input
	cin >> set_no;
	printf("SHIPPING ROUTES OUTPUT\n\n");
	for (now_set = 1; now_set <= set_no; now_set++)
	{
		//output data set's no
		printf("DATA SET %2d\n\n", now_set);

		//read input
		cin >> m >> n >> p;
		for (i = 0; i < m; i++)
			cin >> house[i];

		//read route
		for (i = 0; i < 30; i++)
			for (j = 0; j < 30; j++)
				route[i][j] = INF;
		for (i = 0; i < 30; i++)
			route[i][i] = 0;
		for (i = 0; i < n; i++)
		{
			char temp[4];

			cin >> temp;
			for (place_s = 0; place_s < 30; place_s++)
				if (strcmp(temp, house[place_s]) == 0)
					break;
			cin >> temp;
			for (place_e = 0; place_e < 30; place_e++)
				if (strcmp(temp, house[place_e]) == 0)
					break;
			route[place_s][place_e] = 1;
			route[place_e][place_s] = 1;
		}

		//find all-pair shortest path
		for (k = 0; k < m; k++)
			for (i = 0; i < m; i++)
				for (j = 0; j < m; j++)				
					if (route[i][k] + route[k][j] < route[i][j])
						route[i][j] = route[i][k] + route[k][j];

		//read ship and calcualte result
		for (i = 0; i < p; i++)
		{			
			char temp[4];

			cin >> ship_no;
			cin >> temp;
			for (place_s = 0; place_s < 30; place_s++)
				if (strcmp(temp, house[place_s]) == 0)
					break;
			cin >> temp;
			for (place_e = 0; place_e < 30; place_e++)
				if (strcmp(temp, house[place_e]) == 0)
					break;
			if (route[place_s][place_e] != INF)			
				printf("$%d\n", ship_no*route[place_s][place_e]*100);
			else
				printf("NO SHIPMENT POSSIBLE\n");			
		}
		printf("\n");
	}
	printf("END OF OUTPUT\n");

	return 0;
}