// 133 - The Dole Queue

#include <iostream>
#include <stdio.h>

int main()
{	
	int  n;
	int  k;
	int  m;
	bool man[30];
	int  cc;
	int  c;
	int  rest;
	int  i;
	int  j;

	//read input
    std::cin >> n >> k >> m;
	while (n || k || m)
	{		
		//initial
		for (i = 0; i < n; i++)
			man[i] = false;
		cc = -1;
		c = n;
		rest = n;

		while (rest > 0)
		{
			// Find a person by counter-clockwise.
			j = 0;
			while (j < k)
			{
				cc = (cc + 1) % n;
				if (!man[cc])
					j++;				
			}

			// Find a person by clockwise.
			j = 0;
			while (j < m)
			{
				c--;
				if (c < 0)
					c = n - 1;
				if (!man[c])
					j++;
			}
			
			// Pick these two persons.
			man[cc] = true;
			man[c] = true;

			//output result
			if (cc != c)
			{
				rest = rest - 2;
				printf("%3d%3d", cc+1, c+1);
			}
			else
			{
				rest = rest - 1;
				printf("%3d", cc+1);
			}
			if (rest > 0)
				printf(",");
		}
		printf("\n");

		std::cin >> n >> k >> m;
	}

	return 0;
}

