// 142 - Mouse Clicks

#include <iostream>
#include <stdio.h>
#include <math.h>

using namespace std;

double find_dis(int mouse[], int icon[])
{
	double a = mouse[0] - icon[0];
	double b = mouse[1] - icon[1];

	return sqrt(a * a + b * b);
}

int main()
{	
	char type;
	int  icon_no;
	int  icon[55][2];
	int  region_no;
	int  region[27][4];
	int  mouse[2];
	int  ans_no;
	int  ans[55];	
	double min;
	int  i;


	//initial
	icon_no = 0;
	region_no = 0;

	//read input
	cin >> type;
	while (type != '#')
	{
		if (type == 'I')		
		{
			cin >> icon[icon_no][0] >> icon[icon_no][1];
			icon_no++;
		}
		else if (type == 'R')
		{
			cin >> region[region_no][0] >> region[region_no][1];
			cin >> region[region_no][2] >> region[region_no][3];
			region_no++;
		}
		else		//type == 'M'
		{
			cin >> mouse[0] >> mouse[1];

			for (i = region_no - 1; i >= 0; i--)	
			{
				if ((mouse[0] >= region[i][0]) && (mouse[0] <= region[i][2]) && 
					(mouse[1] >= region[i][1]) && (mouse[1] <= region[i][3]))
					break;
			}
			
			if (i >= 0)
				//output result				
				printf("%c", i + 'A');
			else
			{
				double temp;
				//initial
				ans_no = 0;			
				min = 20000000.0;

				for (i = 0; i < icon_no; i++)
				{
					temp = find_dis(mouse, icon[i]);
					if (temp < min)
					{
						ans[0] = i;
						ans_no = 1;	
						min = temp;
					}
					else if (temp == min)
						ans[ans_no++] = i;
				}

				//output result
				for (i = 0; i < ans_no; i++)
					printf("%3d", ans[i]+1);
			}
			printf("\n");	

		}

		cin >> type;
	}

	return 0;
}

