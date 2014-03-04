// 537 - Artificial Intelligence

#include <iostream>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

using namespace std;

//Calculate P, U or I
double find_value(char msg[], int start)
{
	double ans;
	char temp[3000];
	int index;
	int i;

	index = 0;
	for (i = start; i < strlen(msg); i++)
	{
		if ((msg[i] == 'W') || (msg[i] == 'V') || (msg[i] == 'A'))
		{
			temp[index] = '\0';
			ans = atof(temp);
			break;
		}
		else if ((msg[i] == 'm') || (msg[i] == 'k') || (msg[i] == 'M'))
		{
			temp[index] = '\0';
			ans = atof(temp);
			if (msg[i] == 'm')
				ans = ans * 0.001;
			else if (msg[i] == 'k')
				ans = ans * 1000;
			else
				ans = ans * 1000000;
			break;
		}
		else
		{
			temp[index] = msg[i];
			index++;
		}			 
	}

	return ans;
}


int main()
{	
	char msg[3000];
	long number;
	bool mark[3];		//Record p, u, is used or not
	double value[3];
	long i;
	int j;

	//read input
	cin.getline(msg, 3000);
	number = atol(msg);
	for (i = 0; i < number; i++)
	{
		cin.getline(msg, 3000);

		//initial
		for (j = 0; j < 3; j++)
			mark[j] = false;

		//First '='
		for (j = 0; j < strlen(msg); j++)
			if (msg[j] == '=')
				break;

		if (msg[j - 1] == 'P')
		{
			mark[0] = true;
			value[0] = find_value(msg, j + 1);
		}
		else if (msg[j - 1] == 'U')
		{
			mark[1] = true;
			value[1] = find_value(msg, j + 1);
		}
		else
		{
			mark[2] = true;
			value[2] = find_value(msg, j + 1);
		}

		//Second '='
		for (j = j + 1; j < strlen(msg); j++)
			if (msg[j] == '=')
				break;

		if (msg[j - 1] == 'P')
		{
			mark[0] = true;
			value[0] = find_value(msg, j + 1);
		}
		else if (msg[j - 1] == 'U')
		{
			mark[1] = true;
			value[1] = find_value(msg, j + 1);
		}
		else
		{
			mark[2] = true;
			value[2] = find_value(msg, j + 1);
		}

		//output result
		if (i == 0)
			printf("Problem #%ld\n", i + 1);
		else
			printf("\nProblem #%ld\n", i + 1);			

		if (!mark[0])
			printf("P=%.2fW\n", value[1] * value[2]);
		else if (!mark[1])
			printf("U=%.2fV\n", value[0] / value[2]);
		else
			printf("I=%.2fA\n", value[0] / value[1]);		
	}		

	return 0;
}
