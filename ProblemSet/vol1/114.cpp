// 114 - Simulation Wizardry
// Time limit: 3.000 seconds 

#include <iostream>
using namespace std;

struct bumper_type
{
	long x;
	long y;
	long value;
	long cost;
};

struct ball_type
{
	int x;
	int y;
	long dir;
	long life;
};

//檢查ball是否撞到wall
bool hit_wall(long m, long n, ball_type ball)
{
	switch (ball.dir)			
	{
		case 0:	//向右
		{
			if (ball.x + 1 == n)
				return true;
			break;
		}
		case 1: //向下
		{
			if (ball.y + 1 == m)
				return true;
			break;
		}
		case 2: //向左
		{
			if (ball.x - 1 == 1)
				return true;
			break;
		}
		case 3: //向上
		{
			if (ball.y - 1 == 1)
				return true;		
			break;
		}
	}

	return false;
}

//檢查ball是否撞到bumper
bool hit_bumper(long bumper_table[][55], bumper_type bumper[], ball_type ball, long& index)
{
	switch (ball.dir)			
	{
		case 0:	//向右
		{
			if (bumper_table[ball.x+1][ball.y] >= 0)
			{
				index = bumper_table[ball.x+1][ball.y];
				return true;
			}
			break;
		}
		case 1: //向上
		{
			if (bumper_table[ball.x][ball.y+1] >= 0)
			{
				index = bumper_table[ball.x][ball.y+1];
				return true;
			}
			break;
		}
		case 2: //向左
		{
			if (bumper_table[ball.x-1][ball.y] >= 0)
			{
				index = bumper_table[ball.x-1][ball.y];
				return true;
			}
			break;
		}
		case 3: //向下
		{
			if (bumper_table[ball.x][ball.y-1] >= 0)
			{
				index = bumper_table[ball.x][ball.y-1];
				return true;
			}
			break;
		}
	}

	return false;
}

int main()
{	
	long m;
	long n;
	long cost;
	long bumper_no;
	long bumper_table[55][55];
	bumper_type bumper[2700];
	ball_type ball;
	long point;
	long sum;
	long i;
	long j;

	//initial
	sum = 0;

	//read input
	cin >> m >> n;
	cin >> cost;
	cin >> bumper_no;
	for (i = 0; i < m; i++)
		for (j = 0; j < n; j++)
			bumper_table[i][j] = -1;
	for (i = 0; i < bumper_no; i++) 
	{
		int x;
		int y;

		cin >> x >> y >> bumper[i].value >> bumper[i].cost;
		bumper_table[x][y] = i;
	}

	while (cin >> ball.x >> ball.y >> ball.dir >> ball.life)
	{
		point = 0;

		//計算答案		
		while (ball.life > 1)
		{
			long temp;

			//移動ball
			ball.life--;

			//檢查移動後的結果
			if (hit_wall(m, n, ball))
			{
				switch (ball.dir)		//改成向右旋轉90度
				{
				case 0: ball.dir = 3; break;	//向右
				case 1: ball.dir = 0; break;	//向下
				case 2: ball.dir = 1; break;	//向左
				case 3: ball.dir = 2; break;	//向上
				}
				ball.life = ball.life - cost;
			}
			else if (hit_bumper(bumper_table, bumper, ball, temp))
			{
				switch (ball.dir)		//改成向右旋轉90度
				{
				case 0: ball.dir = 3; break;	//向右
				case 1: ball.dir = 0; break;	//向下
				case 2: ball.dir = 1; break;	//向左
				case 3: ball.dir = 2; break;	//向上
				}				
				ball.life = ball.life - bumper[temp].cost;
				point = point + bumper[temp].value;
			}
			else
			{
				switch (ball.dir)			
				{
				case 0: ball.x++; break;	//向右					
				case 1: ball.y++; break;	//向上
				case 2: ball.x--; break;	//向左
				case 3: ball.y--; break;	//向下
				}
			}
		}

		//print output
		cout << point << endl;
		sum = sum + point;
	}

	//print sum output
	cout << sum << endl;

	return 0;
}

