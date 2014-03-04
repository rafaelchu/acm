// 145 - Gondwanaland Telecom

#include <iostream>

using namespace std;

double charges[5][3] = {
{ 0.10, 0.06, 0.02 },
{ 0.25, 0.15, 0.05 },
{ 0.53, 0.33, 0.13 },
{ 0.87, 0.47, 0.17 },
{ 1.44, 0.80, 0.30 }
};

struct { int brk; int step; } rates[7] = {
{  8 * 60, 2 },
{ 18 * 60, 0 },
{ 22 * 60, 1 },
{  8 * 60 + 24 * 60, 2 },
{ 18 * 60 + 24 * 60, 0 },
{ 22 * 60 + 24 * 60, 1 },
{  8 * 60 + 48 * 60, 2 }
}; 


int main()
{
	char c, s[32];
	int sh, sm, eh, em, st, et, tt;
	int t[3];
	int i,j,k;

	for(;;)
	{
		scanf("%c", &c);		
		if(c == '#') 
			break;

		scanf(" %s %d %d %d %d\n", &s, &sh, &sm, &eh, &em);
		
		t[0] = t[1] = t[2] = 0;
		
		st = 60 * sh + sm;
		et = 60 * eh + em;
		
		if(et <= st) 
			et += 24 * 60;
		
		i = 0;		
		while(st >= rates[i].brk) 
			i++;
		
		while(st < et)
		{
			tt = (et > rates[i].brk) ? rates[i].brk : et; 						
			
			k = tt - st;
			st = tt; 
			
			j = rates[i].step;
			 			
			t[j] += k;
			
			i++;	
		}
				
		i = c - 'A';
				
		printf("  %s%6d%6d%6d  %c%8.2f\n", s, t[0], t[1], t[2], c, 
			(double)(t[0]*charges[i][0] +
			 t[1]*charges[i][1] + t[2]*charges[i][2]));		
	}

	return 0;
}
