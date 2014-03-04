// 187 - Transaction Processing

#include <iostream>
#include "string.h"
#include "stdlib.h"
#include "stdio.h"

using namespace std;

struct account_type
{
	char no[5];
	char name[35];
};

struct entry_type
{
	char account_no[5];
	double money;
};

//find out balance
void find_balance(char seq[], int entry_no, entry_type entry[], account_type account[], int& tran_no)
{
	double balance;
	int i;
	int j;

	balance = 0.0;
	for (i = 0; i < entry_no; i++)
		balance = balance + entry[i].money;

	if (balance != 0.0)
	{
		balance = balance * -1.0;

		//print output
		if (tran_no >= 1)
			printf("\n");
		printf("*** Transaction %s is out of balance ***\n", seq);
		for (i = 0; i < entry_no; i++)
		{
			j = 0;
			while (true)
			{
				if (strcmp(entry[i].account_no, account[j].no) == 0)
					break;
				j++;
			}
			
			printf("%3d %s %10.2lf\n", atoi(account[j].no), account[j].name, entry[i].money);				
		}
		printf("999 Out of Balance                 %10.2lf\n", balance);		

		tran_no++;
	}
}

//insert new data
void insert_data(char line[], int& entry_no, entry_type entry[])
{
	char digit[20];
	int i;

	entry[entry_no].account_no[0] = line[3];
	entry[entry_no].account_no[1] = line[4];
	entry[entry_no].account_no[2] = line[5];
	entry[entry_no].account_no[3] = 0;
	
	for (i = 6; i < 15; i++)
		if (line[i] != ' ')
			break;
	if ((i <= 12) && (line[12] != '-'))
	{
		digit[0] = line[6];		//sign
		digit[1] = line[7];		//integer
		digit[2] = line[8];
		digit[3] = line[9];
		digit[4] = line[10];
		digit[5] = line[11];
		digit[6] = line[12];
		digit[7] = '.';
		digit[8] = line[13];	//float
		digit[9] = line[14];
	}
	else
	{
		digit[0] = ' ';		//sign
		digit[1] = ' ';		//integer
		digit[2] = ' ';
		digit[3] = ' ';
		digit[4] = ' ';
		if (line[i] == '-')
			digit[5] = '-';
		else
			digit[5] = '0';
		digit[6] = '0';
		digit[7] = '.';		//float
		if ((line[13] == ' ') || (line[13] == '-'))
			digit[8] = '0';
		else
			digit[8] = line[13];
		if ((line[14] == ' ') || (line[14] == '-'))
			digit[9] = '0';
		else
			digit[9] = line[14];
	}
	digit[10] = 0;
	entry[entry_no].money = atof(digit);

	entry_no++;
}

int main()
{
	int account_no;
	account_type account[110];		
	char seq[5];	
	int entry_no;
	entry_type entry[15];
	int tran_no;
	char line[100];
	int i;

	//initial
	account_no = 0;	
	strcpy(seq, "-1");
	entry_no = 0;	
	tran_no = 0;

	//read input - account
	cin.getline(line, 100);
	while (true)
	{
		account[account_no].no[0] = line[0];
		account[account_no].no[1] = line[1];
		account[account_no].no[2] = line[2];
		account[account_no].no[3] = 0;

		if (atoi(account[account_no].no) == 0)
			break;
		else
		{
			strcpy(account[account_no].name, line + 3);
			for (i = strlen(account[account_no].name); i < 30; i++)
				account[account_no].name[i] = ' ';
			account[account_no].name[i] = 0;
			account_no++;
			cin.getline(line, 100);
		}
	}
	
	//read input - transaction
	cin.getline(line, 100);
	while (true)
	{
		char now[5];		
		now[0] = line[0];
		now[1] = line[1];
		now[2] = line[2];
		now[3] = 0;
		
		if (atoi(seq) != atoi(now))
		{
			find_balance(seq, entry_no, entry, account, tran_no);

			//new transaction
			strcpy(seq, now);
			entry_no = 0;
		}
		
		if (atoi(seq) != 0)					
			insert_data(line, entry_no, entry);
		else
			break;

		cin.getline(line, 100);
	}


	return 0;
}