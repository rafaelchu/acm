// 603 - Parking Lot

#include "stdio.h"
#include "string.h"
#include "stdlib.h"

struct car_type
{
	int o_pos;			//origin position
	int n_pos;			//now position
	int park_pos;		//parked position
};

void sub_main()
{
	int car_no;						//waitting car's NO
	struct car_type car[30];		
	int park_no;	
	int vacated_pos;
	bool find;
	char temp[256];
	int n;
	int i;
	
	//read input - 1
	car_no = 0;
	while (gets(temp) != NULL)
	{
		n = atol(temp);
		if (n == 99)
			break;
		car[car_no].o_pos = n;
		car[car_no].n_pos = n;
		car_no++;
	}

	//initail
	for (i = 0; i < car_no; i++)	
		car[i].park_pos = -1;	
	park_no = 0;


	//read input - 2
	while (gets(temp) != NULL)
	{
		if (temp[0] == 0)
			break;
		n = atol(temp);
		vacated_pos = n;

		//simulate parking
		if (park_no < car_no)
		{
			//find out the nearest car
			find = false;

			while (!find) 
			{
				for (i = 0; i < car_no; i++)
					if ((car[i].park_pos < 0) && ((car[i].n_pos - vacated_pos) == 0))
					{
						find = true;
						car[i].park_pos = vacated_pos;
						park_no++;
					}

				if (!find)					//rotate cars with clockwise			
				{
					for (i = 0; i < car_no; i++)
					{
						car[i].n_pos++;
						if (car[i].n_pos > 20)
							car[i].n_pos = 1;
					}
				}
			}
		}
	}

	//output result
	for (i = 0; i < car_no; i++)
	{
		if (car[i].park_pos >= 0)
			printf("Original position %d parked in %d\n", car[i].o_pos, car[i].park_pos);
		else
			printf("Original position %d did not park\n", car[i].o_pos);
	}
}

int main()
{
	int number;	
	int j;

	scanf("%d\n\n", &number);
	for (j = 0; j < number - 1; j++)
	{
		sub_main();
		printf("\n");
	}
	sub_main();

	return 0;
}