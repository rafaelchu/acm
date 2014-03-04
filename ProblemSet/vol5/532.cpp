// 532 - Dungeon Master

#include <iostream>
#include <string.h>

using namespace std;

const int INF = 200000000;

struct point_type
{
	int l;
	int r;
	int c;
};


void move(int l, int r, int c, char dungeon[][31][31], bool used[], int cost[], point_type p)
{
	int p_no;

	p_no = p.l*r*c + p.r*c + p.c;

	if (p.l + 1 < l)		//up level
	{
		int no = (p.l + 1)*r*c + p.r*c + p.c;
		if ((dungeon[p.l+1][p.r][p.c] != '#') && (!used[no]))
			if (cost[p_no] + 1 < cost[no])
				cost[no] = cost[p_no] + 1;
	}

	if (p.l - 1 >= 0)		//down level
	{
		int no = (p.l - 1)*r*c + p.r*c + p.c;
		if ((dungeon[p.l-1][p.r][p.c] != '#') && (!used[no]))
			if (cost[p_no] + 1 < cost[no])
				cost[no] = cost[p_no] + 1;
	}

	if (p.r + 1 < r)		//down
	{
		int no = p.l*r*c + (p.r + 1)*c + p.c;
		if ((dungeon[p.l][p.r+1][p.c] != '#') && (!used[no]))
			if (cost[p_no] + 1 < cost[no])
				cost[no] = cost[p_no] + 1;
	}

	if (p.r - 1 >= 0)		//up
	{
		int no = p.l*r*c + (p.r - 1)*c + p.c;
		if ((dungeon[p.l][p.r-1][p.c] != '#') && (!used[no]))
			if (cost[p_no] + 1 < cost[no])
				cost[no] = cost[p_no] + 1;
	}

	if (p.c + 1 < c)		//right
	{
		int no = p.l*r*c + p.r*c + (p.c + 1);
		if ((dungeon[p.l][p.r][p.c+1] != '#') && (!used[no]))
			if (cost[p_no] + 1 < cost[no])
				cost[no] = cost[p_no] + 1;
	}

	if (p.c - 1 >= 0)		//left
	{
		int no = p.l*r*c + p.r*c + (p.c - 1);
		if ((dungeon[p.l][p.r][p.c-1] != '#') && (!used[no]))
			if (cost[p_no] + 1 < cost[no])
				cost[no] = cost[p_no] + 1;
	}
}

int main()
{
	char dungeon[30][31][31];
	int  cost[27010];
	bool used[27010];
	int l;
	int r;
	int c;
	int no;
	point_type start_p;
	point_type exit_p;
	point_type next_p;
	int i;
	int j;
	int k;

	//read input
	cin >> l >> r >> c;
	while ((l != 0) && (r != 0) && (c != 0))
	{
		//read dungeon
		char temp[31];
		for (i = 0; i < l; i++)
			for (j = 0; j < r; j++)
			{
				cin >> temp;
				strcpy(dungeon[i][j], temp);
			}

		//find start and exit point
		for (i = 0; i < l; i++)
		{
			for (j = 0; j < r; j++)
				for (k = 0; k < c; k++)
					if (dungeon[i][j][k] == 'S')
					{
						start_p.l = i;
						start_p.r = j;
						start_p.c = k;
					}
					else if (dungeon[i][j][k] == 'E')
					{
						exit_p.l = i;
						exit_p.r = j;
						exit_p.c = k;
					}
		}

		//find the shortest path
		no = l * r * c;
		for (i = 0; i < no; i++)
		{
			cost[i] = INF;
			used[i] = false;
		}

		//star point
		used[start_p.l*r*c + start_p.r*c + start_p.c] = true;
		cost[start_p.l*r*c + start_p.r*c + start_p.c] = 0;
		next_p = start_p;

		//other points
		for (i = 0; i < no - 2; i++)
		{
			move(l, r, c, dungeon, used, cost, next_p);			

			//find next point
			int min = INF;			
			for (j = 0; j < no; j++)
			{
				if (!used[j] && (cost[j] < min))
				{
					min = cost[j];
					next_p.c = j;
				}
			}
			used[next_p.c] = true;
			next_p.l = next_p.c / (r * c);
			next_p.c = next_p.c % (r * c);
			next_p.r = next_p.c / c;
			next_p.c = next_p.c % c;
		}

		//output result
		if (cost[exit_p.l*r*c + exit_p.r*c + exit_p.c] != INF)		
			cout << "Escaped in " << cost[exit_p.l*r*c + exit_p.r*c + exit_p.c] << " minute(s)." << endl;
		else
			cout << "Trapped!" << endl;

		cin >> l >> r >> c;
	}

	return 0;
}
