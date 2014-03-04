// 587 - There's treasure everywhere!

#include <iostream>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>

using namespace std;

int main()
{
	int map_no;
	double x;
	double y;
	int  len;
	double step;
	double dis;
	char digit[10];
	double two;
	char line[500];
	char sep[] = ",.\n";
	char* token;
	int i;

	//initial
	two = sqrt(2);
	map_no = 0;

	//read input
	cin.getline(line, 500);
	while (strcmp(line, "END") != 0)
	{
		//initial
		map_no++;
		x = 0.0;
		y = 0.0;

		//start to move
		token = strtok(line, sep);
		while (token)
		{
			//get total steps
			len = strlen(token);
			for (i = 0; i < len; i++)
			{
				if ((token[i] >= '0') && (token[i] <= '9'))
					digit[i] = token[i];
				else
					break;
			}
			digit[i] = 0;
			step = static_cast<double>(atoi(digit));

			//get the direction and move
			if (token[i] == 'N')
			{
				if (i + 1 < len)
				{
					step = step / two;

					if (token[i+1] == 'E')	//NE
					{
						x = x + step;
						y = y + step;
					}
					else					//NW
					{
						x = x - step;
						y = y + step;
					}
				}
				else
					y = y + step;			//N
			}
			else if (token[i] == 'E')
				x = x + step;				//E
			else if (token[i] == 'S')
			{
				if (i + 1 < len)
				{
					step = step / two;

					if (token[i+1] == 'E')	//SE
					{
						x = x + step;
						y = y - step;
					}
					else					//SW
					{
						x = x - step;
						y = y - step;
					}
				}
				else
					y = y - step;			//S
			}
			else if (token[i] == 'W')
				x = x - step;				//W

			token = strtok(NULL, sep);
		}
		dis = sqrt(x * x + y * y);

		//output result
		printf("Map #%d\n", map_no);
		printf("The treasure is located at (%.3lf,%.3lf).\n", x, y);
		printf("The distance to the treasure is %.3lf.\n\n", dis);		

		cin.getline(line, 500);
	}

	return 0;
}