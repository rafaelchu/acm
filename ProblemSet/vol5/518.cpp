// 518 - Time

#include <stdio.h>

int days_year[64];
int common_days_month[12] = { 0, 31, 59, 90, 120, 151, 181, 212, 243, 273, 304, 334 };
int leap_days_month[12] = {  0, 31, 60, 91, 121, 152, 182, 213, 244, 274, 305, 335 };

bool leapyear(int y)
{
	return (!(y % 4) && !!(y % 100)) || !(y % 400);
}

int days(int y, int m)
{
	return days_year[y - 1970] + 
		(leapyear(y) ? leap_days_month : common_days_month)[m-1];
}

int main()
{
	int date1[6], date2[6], units, result, i, level;
	char unitstr[32];

	for(i = 1970; i < 2030; i++)
		days_year[i-1970 + 1] = days_year[i-1970] + (leapyear(i) ? 366 : 365);

	for(;;)
	{
		if(scanf("%d%d%d%d%d%d%d%d%d%d%d%d%d%s",
		     &date1[0], &date1[1], &date1[2], &date1[3], &date1[4], &date1[5],
	         &date2[0], &date2[1], &date2[2], &date2[3], &date2[4], &date2[5],
		     &units, unitstr) != 14)
			break;

		switch(unitstr[0])
		{
		case 'd':
			level = 2;
			break;

		case 'h':
			level = 3;
			break;

		case 'm':
			if(unitstr[1] == 'o')
			{
				result = 12 * (date2[0] - date1[0]) + (date2[1] - date1[1]);
				level = 1;
			}
			else
			{
				level = 4;
			}
			break;

		case 'y':
			result = (date2[0] - date1[0]);
			level = 0;
			break;

		default:
			level = 5;
		}

		if(level >= 2)
		{
			result = days(date2[0], date2[1]) - days(date1[0], date1[1]) + (date2[2] - date1[2]);

			for(i = 3; i <= level; i++)
				result = ((i >= 4) ? 60 : 24) * result + (date2[i] - date1[i]);
		}

		for(i = level + 1; i < 6; i++)
		{
			if(date1[i] > ((i >= 3) ? 0 : 1))
			{
				result -= 1;
				break;
			}
		}

		printf("%d\n", result / units);
	}
    
    return 0;
}