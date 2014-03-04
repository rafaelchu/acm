// @JUDGE_ID: 5084AA 10124 C++ "<a href=http://go.to/hoshiko_acm>琍ACM痕</a>" 
// Problem: Subway
#include <iostream.h>
#include <stdlib.h>
#include <math.h>
#include <stdio.h>

int main()
{
	long d;
	long m;
	double dm;
	long a;
	double da;
	long j;
	double dj;
	double time_v;
	double time_a;
	double half_d;
	double rest;
	double ans;


	//read input
	while (cin >> d >> m >> a >> j) 
	{
		//initial
		dm = (double)m;
		da = (double)a;
		dj = (double)j;
		half_d = (double)d / 2;

		//тㄓV(硉)程临琌A(硉)程
		time_v = sqrt(dm / dj);
		time_a = da / dj;

		if (time_v <= time_a)
		{
			//V(硉)程硉ぃэ跑
			rest = half_d - dj * pow(time_v, 3) / 6;	//s = 1/6*j*t^3
//			rest = half_d - dm * time_v;	//s = 1/6*j*t^3

			if (rest >= 0)
			{
				//s = vt
				double root = sqrt(dm*dm/4 - 2*dj);
				ans = time_v + (dm/2 + root)/dj;
				double ans2 = time_v + (dm/2 - root)/dj;;
				double ans3 = sqrt(dm * 2 / dj) * ((3*dj-1) / (3*dj)) * 2 + (double)d / dm;
			}
			else
			{
				//s = 1/6*j*t^3
				ans = exp(log(rest * 6 / dj)/3);
			}
		}
		else
		{
			//A(硉)程
			rest = half_d - dj * pow(time_a, 3) / 6;	//s = 1/6*j*t^3

			if (rest >= 0)
			{
				//糤V(硉)程
				time_v = (dm - dj * pow(time_a, 2) / 2) / da;

				double rest2 = rest - da * pow(time_v, 2) / 2;	//s = 1/2*a*t^2

				if (rest2 >=0)
				{
					//s = vt
					ans = time_a + time_v + rest2 / dm;
				}
				else
				{
					//s = 1/2*a*t^2
					ans = time_a + sqrt(rest2 * 2 / da);
				}
			}
			else
			{
				//s = 1/6*j*t^3
				ans = exp(log(rest * 6 / dj)/3);
			}
		}
		ans = ans * 2;

		//output result
		printf("%.1lf\n", ans);
	}

	return 0;
}