// 371 - Ackermann Functions

#include <iostream>

using namespace std;

const long T_SIZE = 50000;

//calculate ack
long cal_ack(long table[], long n)
{
	long t_ack = 0;

	while (n >= T_SIZE)		
	{
		if (n % 2 == 0)		//even
			n = n / 2;
		else				//odd
		{
			if (n * 3 < 0)	//overflow
			{
				n = n / 2 * 3 + 2;
				t_ack++;
			}
			else
				n = 3 * n + 1;
		}
		t_ack++;
	}

	if (table[n] >= 0)
	{
		return table[n] + t_ack;
	}
	else if (n % 2 == 0)		//even
	{
		table[n] = 1 + cal_ack(table, n / 2);
		return table[n] + t_ack;
	}
	else						//odd
	{
		if (n * 3 < 0)			//overflow
		{
			table[n] = 2 + cal_ack(table, n / 2 * 3 + 2);
			return table[n] + t_ack;
		}
		else
		{
			table[n] = 1 + cal_ack(table, 3 * n + 1);
			return table[n] + t_ack;
		}
	}
}

int main()
{
	long table[T_SIZE];
	long l;
	long u;
	long v;
	long s;
	long i;

	//make table
	table[0] = 0;
	table[1] = 3;
	table[2] = 1;
	for (i = 3; i < T_SIZE; i++)
		table[i] = -1;
	for (i = 3; i < T_SIZE; i++)
		cal_ack(table, i);

	//read input
	cin >> l >> u;
	while ((l != 0) && (u != 0))
	{
		//swap l and u if necessary
		if (l > u)
		{
			v = l;
			l = u;
			u = v;
		}

		//calculate ack from l to u
		v = l;
		s = cal_ack(table, l);
		for (i = l + 1; i <= u; i++)
		{		
			long temp = cal_ack(table, i);
			if (temp > s)
			{
				v = i;
				s = temp;
			}
		}

		//output result
		cout << "Between " << l << " and " << u << ", "
			  << v << " generates the longest sequence of " << s << " values." << endl;

		cin >> l >> u;
	}

	return 0;
}