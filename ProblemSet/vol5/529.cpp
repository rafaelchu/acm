// 529 - Addition Chains

#include <iostream>
#include "string.h"

using namespace std;

struct entry
{
	int number;
	int list_no;
	int list[20];
};

void find_step(entry table[], int table_no, int& min_step, entry step[], int& step_no,
               int ai, int aj)
{
	int pi;
	int pj;
    
	for (pi = 1; pi <= table_no; pi++)
		if (table[pi].number == ai)
			break;
    
	for (pj = table_no; pj >= 1; pj--)
		if (table[pj].number == aj)
			break;
    
	while (pi <= pj)
	{
		int tpj = pj;
		if (table[pi].number == ai)
		{
			while (tpj >= pi)
			{
				if (table[tpj].number == aj)
				{
					// Store pi and tpj into step
					int no = 0;
					int i = 0;
					int j = 0;
                    
					while ((i < table[pi].list_no) && (j < table[tpj].list_no))
					{
						if (table[pi].list[i] == table[tpj].list[j])
						{
							step[step_no].list[no] = table[pi].list[i];
							i++;
							j++;
						}
						else if (table[pi].list[i] > table[tpj].list[j])
						{
							step[step_no].list[no] = table[tpj].list[j];
							j++;
						}
						else
						{
							step[step_no].list[no] = table[pi].list[i];
							i++;
						}
                        
						no++;
					}
                    
					// Plus rest steps
					for (; i < table[pi].list_no; i++)
						step[step_no].list[no++] = table[pi].list[i];
					for (; j < table[tpj].list_no; j++)
						step[step_no].list[no++] = table[tpj].list[j];
                    
					// Add myself.
					step[step_no].list[no++] = ai + aj;
					step[step_no].list_no = no;
                    
					// Check the stop is minimum.
					if (step[step_no].list_no <= min_step)
					{
						min_step = step[step_no].list_no;
						step_no++;
					}
                    
					tpj--;
				}
				else
					break;
			}
			pi++;
		}
		else
			break;
	}
}

int main()
{
	entry table[10010];
	int table_no;
	int no;
	int min_step;
	int i, j;
    
	// Initialization.
	table_no = 1;
	table[1].number = 1;
	table[1].list_no = 1;
	table[1].list[0] = 1;
    
	// Create DP table.
	for (no = 2; no <= 200; no++)
	{
		entry step[1000];
		int step_no;
        
		step_no = 0;
		i = 1;
		j = no - i;
        
		// Find out minimum steps from ai to aj.
		min_step = no + 1;
		while (i <= j)
		{
			find_step(table, table_no, min_step, step, step_no, i, j);
			i++;
			j--;
		}
		
		// Store the minimum steps into table
		for (i = 0; i < step_no; i++)
		{
			if (step[i].list_no == min_step)
			{
				table_no++;
				table[table_no].number = no;
				table[table_no].list_no = min_step;
				for (j = 0; j < min_step; j++)
					table[table_no].list[j] = step[i].list[j];
			}
		}
	}
    
	// Fill all table.
	no = 2;
	for (i = 2; i <= table_no; i++)
	{
		if (table[i].number == no)
		{
			table[no] = table[i];
			no++;
		}
	}
    
	// Read inpupt and print output.
	cin >> no;
	while (no > 0)
	{
		for (i = 0; i < table[no].list_no - 1; i++)
			cout << table[no].list[i] << ' ';
		cout  << table[no].list[i] << endl;
        
		cin >> no;
	}
    
	return 0;
}