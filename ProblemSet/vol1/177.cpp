// 177 - Paper Folding

#include <iostream>

using namespace std;

const char UP = 'U';
const char DOWN = 'D';
const char RIGHT = 'R';
const char LEFT = 'L';

struct point_type
{
	int row;
	int col;
};

char change(char dir)
{
	if (dir == UP)
		return LEFT;
	else if (dir == DOWN)
		return RIGHT;
	else if (dir == RIGHT)
		return UP;
	else
		return DOWN;
}

int main()
{	
	int no;					
	char step[13][9000];	
	int  step_no[13];		
	point_type point[13];	
	int  range[13][2];		
	char pic[200][250];		
	int row;
	int col;
	int  i;
	int  j;

	//initial
	step[0][0] = RIGHT;
	step[0][1] = UP;
	step_no[0] = 2;

	//calculate moving step
	for (i = 1; i < 13; i++)
	{
		step_no[i] = step_no[i-1] * 2;
		for (j = 0; j < step_no[i-1]; j++)
			step[i][j] = step[i-1][j];
		for (; j < step_no[i]; j++)
			step[i][j] = change(step[i-1][step_no[i-1] - 1 - j + step_no[i-1]]);
	}

	//calculate start location
	for (i = 0; i < 13; i++)
	{
		//initial
		int max_row = 0;
		int min_row = 0;
		int max_col = 0;
		int min_col = 0;
		point[i].row = 0;
		point[i].col = 0;

		//calculate point[]
		for (j = 0; j < step_no[i] - 1; j++)
		{
			switch (step[i][j])
			{
			case UP:	if (step[i][j+1] == RIGHT)
						{
							point[i].row--;		//UR
							point[i].col++;
						}
						else
						{
							point[i].row--;		//UL
							point[i].col--;
						}					
						break;
			case DOWN:	if (step[i][j+1] == RIGHT)
							point[i].col++;		//DR
						else
							point[i].col--;		//DL
						break;
			case RIGHT: if (step[i][j+1] == UP)
						{
							point[i].col++;		//RU
						}
						else
						{
							point[i].row++;		//RD
							point[i].col++;
						}					
						break;
			case LEFT:	if (step[i][j+1] == UP)
						{
							point[i].col--;		//LU
						}
						else
						{
							point[i].row++;		//LD
							point[i].col--;
						}					
						break;
			}

			if (point[i].row > max_row)
				max_row = point[i].row;
			else if (point[i].row < min_row)
				min_row = point[i].row;

			if (point[i].col > max_col)
				max_col = point[i].col;
			else if (point[i].col < min_col)
				min_col = point[i].col;
		}

		//Find out start point and range
		point[i].row = 0 - min_row;
		point[i].col = 0 - min_col;
		range[i][0] = max_row - min_row + 1;
		range[i][1] = max_col - min_col + 1;
	}

	//read input
	cin >> no;
	while (no > 0)
	{
		no = no - 1;
		for (row = 0; row < range[no][0]; row++)
			for (col = 0; col < range[no][1]; col++)
				pic[row][col] = ' ';

		//draw picture step by step
		row = point[no].row;
		col = point[no].col;
		for (j = 0; j < step_no[no] - 1; j++)		
		{
			//draw picture
			if ((step[no][j] == UP) || (step[no][j] == DOWN))
				pic[row][col] = '|';
			else
				pic[row][col] = '_';

			//go to next step
			switch (step[no][j])
			{
			case UP:	if (step[no][j+1] == RIGHT)
						{
							row--;		//UR
							col++;
						}
						else
						{
							row--;		//UL
							col--;
						}					
						break;
			case DOWN:	if (step[no][j+1] == RIGHT)
							col++;		//DR
						else
							col--;		//DL
						break;
			case RIGHT: if (step[no][j+1] == UP)
						{
							col++;		//RU
						}
						else
						{
							row++;		//RD
							col++;
						}					
						break;
			case LEFT:	if (step[no][j+1] == UP)
						{
							col--;		//LU
						}
						else
						{
							row++;		//LD
							col--;
						}					
						break;
			}			
		}
		if ((step[no][j] == UP) || (step[no][j] == DOWN))
			pic[row][col] = '|';
		else
			pic[row][col] = '_';

		//output result
		for (row = 0; row < range[no][0]; row++)
		{
			for (col = 0; col < range[no][1]; col++)
				cout << pic[row][col];
			cout << endl;
		}
		cout << "^" << endl;

		cin >> no;
	}

	return 0;
}