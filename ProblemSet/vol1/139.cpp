// 139 - Telephone Tangles

#include <string.h>
#include <stdlib.h>
#include <iostream>

using namespace std;

struct data_type
{
	char code[500];
	char name[50];
	long price;
	data_type* next;
};

//比較電話簿中的code和這次電話號碼
bool compare(data_type data, char number[], char subscriber[])
{
	long len_d;
	long len_n;
	int  i;

	//initial
	len_d = strlen(data.code);
	len_n = strlen(number);

	for (i = 0; i < len_d; i++)
	{
		if (i > len_n)
			break;
		else if (data.code[i] != number[i])
			break;
	}

	//檢查是不是找到了
	if ((i < len_d) || (i > len_n))
		return false;
	else if (len_n - i < 4) 
		return false;
	else if (data.code[1] == '0')
	{
		if (len_n - i > 10)
			return false;
		strcpy(subscriber, number + i);
		return true;
	}
	else 
	{
		if (len_n - i > 7)
			return false;
		strcpy(subscriber, number + i);
		return true;
	}
}

int main()
{	
	data_type* head;
	data_type* tail;
	char number[500];
	long duration;
	char area[500];
	char subscriber[500];
	double cost;
	double total;
	int i;

	//initial
	head = NULL;
	tail = NULL;
	
	//read input 1
	while (cin >> number)
	{
		if (strcmp(number, "000000") == 0)
			break;

		if (tail)
		{
			tail->next = new data_type;
			tail = tail->next;
			strcpy(tail->code, number);
			tail->next = NULL;
		}
		else
		{
			tail = new data_type;
			strcpy(tail->code, number);
			tail->next = NULL;
			head = tail;
		}

		char temp[10000];
		char sep[] = "$\n";
		char* token;

		cin.getline(temp, 10000);
		token = strtok(temp+1, sep);
		strcpy(tail->name, token);
		token = strtok(NULL, sep);
		tail->price = atol(token);
	}

	//read input 2
	while (cin >> number)
	{
		if (strcmp(number, "#") == 0)
			break;
		cin >> duration;

		//計算答案
		if (number[0] == '0')
		{
			data_type* pdata;
			
			for (pdata = head; pdata; pdata = pdata->next)
				if (compare(*pdata, number, subscriber))
					break;

			//檢查有沒有找到
			if (pdata)
			{
				strcpy(area, pdata->name);
				cost = (double)pdata->price / 100;
				total = cost* (double)duration;
			}
			else
			{
				strcpy(area, "Unknown");
				strcpy(subscriber, " ");		
				total = -1.00;
			}
		}
		else
		{
			strcpy(area, "Local");
			strcpy(subscriber, number);
			cost = 0.0;
			total = 0.0;
		}

		//print output
		printf("%s", number);		
		for (i = 0; i < 16 - strlen(number); i++)
			printf(" ");

		printf("%s", area);		
		for (i = 0; i < 35 - strlen(area) - strlen(subscriber); i++)
			printf(" ");
		printf("%s", subscriber);

		printf("%5d", duration);

		if (strcmp(area, "Unknown") == 0)
			printf("      ");
		else
			printf("%6.2f", cost);

		printf("%7.2f\n", total);
	}

	return 0;
}

