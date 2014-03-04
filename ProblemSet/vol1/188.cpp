// 188 - Perfect Hash

#include <iostream>
#include "string.h"
#include "stdlib.h"

using namespace std;

const long INF = 200000000;

struct set_type
{
	int no;			//count
	long value;		//minimum value in (c/wi+1)*wi
};

int main()
{	
	int  input_no;
	int  w_no;
	long w[15];
	long result;				//result of c/wi
	set_type set[15];			//put minimum of (c/wi) mod n = x into set[x]
	long c;
	bool find;
	long pro;
	char ori_line[500];
	char line[500];
	char sep[] = " \n";
	char* token;
	int i;
	int j;

	//inital
	input_no = 0;

	//read intput
	while (cin.getline(line, 500))
	{
		//initial
		input_no++;
		strcpy(ori_line, line);
		w_no = 0;

		//calculate word
		token = strtok(line, sep);
		while (token)
		{				
			w[w_no] = 0;
			pro = 1;
			for (i = strlen(token) - 1; i >= 0; i--)
			{			
				w[w_no] = w[w_no] + (token[i] - 'a' + 1) * pro;
				pro = pro * 32;
			}
			w_no++;
			
			token = strtok(NULL, sep);
		}

		//sort w[]
		for (i = 0; i < w_no - 1; i++)
		{
			pro = i;		//minimuim value
			for (j = i + 1; j < w_no; j++)
				if (w[j] < w[pro])
					pro = j;

			int temp = w[i];
			w[i] = w[pro];
			w[pro] = temp;
		}

		c= 1;
		find = false;
		while (!find)
		{
			//initial set
			for (i = 0; i < w_no; i++)
			{
				set[i].no = 0;
				set[i].value = INF;
			}

			for (i = 0; i < w_no; i++)
			{
				result = c / w[i];
				pro = result % w_no;		// (c/wi) mod n
				set[pro].no++;
				if ((result + 1) * w[i] < set[pro].value)
					set[pro].value = (result + 1) * w[i];
			}		

			for (i = 0; i < w_no; i++)
				if (set[i].no == 0)
					break;
			if (i >= w_no)
				find = true;
			else
			{
				for (i = 0; i < w_no; i++)
					if ((set[i].no > 1) && (set[i].value > c))
						c = set[i].value;
			}			
		}

		//print output
		if (input_no > 1)
			cout << endl;
		cout << ori_line << endl;
		cout << c << endl;
	}

	return 0;
}

