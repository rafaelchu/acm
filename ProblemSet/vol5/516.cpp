// 516 - Problem: Prime Land

#include <iostream>
#include <string.h>
#include <stdlib.h>
#include <math.h>

using namespace std;

int main()
{
	long p;
	long e;
	long sum;
	char line[10000];
	long pair_no;
	long pair[30000][2];
	char sep[] = " \n";
	char* token;
	long i;

	//read input
	cin.getline(line, 10000);
	while (true)
	{
		token = strtok(line, sep);
		p = atol(token);
		if (p == 0)
			break;
		token = strtok(NULL, sep);
		e = atol(token);
		sum = (long)pow(p, e);

		token = strtok(NULL, sep);
		while (token)
		{
			p = atol(token);
			token = strtok(NULL, sep);
			e = atol(token);
			sum = sum * (long)pow(p, e);
			token = strtok(NULL, sep);
		}
		sum--;

		//find answer
		pair_no = 0;
		for (i = 2; (i < 50000) && (sum > 1); i++)
			if (sum % i == 0)
			{
				pair[pair_no][0] = i;
				pair[pair_no][1] = 0;

				while ((sum % i) == 0)
				{
					sum = sum / i;
					pair[pair_no][1]++;
				}

				pair_no++;
			}

		//output result
		cout << pair[pair_no - 1][0] << ' ' << pair[pair_no - 1][1];
		for (i = pair_no - 2; i >= 0; i--)
			cout << ' ' << pair[i][0] << ' ' << pair[i][1];
		cout << endl;

		cin.getline(line, 10000);
	}

	return 0;
}