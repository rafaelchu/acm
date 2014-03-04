// 153 - Permalex

#include <iostream>
#include "string.h"
#include "stdio.h"

using namespace std;

void s_sort(char word[])
{
	int len;
	int min;
	int i;
	int j;

	len = strlen(word);

	for (i = 0; i < len - 1; i++)
	{
		min = i;

		for (j = i + 1; j < len; j++)
			if (word[j] < word[min])
				min = j;

		char temp = word[i];
		word[i] = word[min];
		word[min] = temp;
	}	
}

unsigned long permutation(char word[])
{
	unsigned long ans;
	int len;
	char pre;			
	int  con_no;
	int  con[1000];		
	int  i;
	int  j;

	//initial
	ans = 1;
	len = strlen(word);

	pre = word[0];
	con_no = 1;
	con[0] = 1;
	i = 1;
	while (i < len)
	{
		for (; i < len; i++)
			if (word[i] == pre)
			{
				con[con_no] = con[con_no-1] + 1;
				con_no++;
			}
			else
				break;		

		if (i < len)
			pre = word[i];
		con[con_no] = 1;
		con_no++;		
		i++;
	}	

	ans = 1;
	j = 0;
	for (i = 2; i <= len; i++)
	{
		ans = ans * i;
		while (j < con_no)
		{
			if (ans % con[j] == 0)
			{
				ans = ans / con[j];
				j++;
			}
			else
				break;
		}
	}

	return ans;
}

void find_ans(int now, int len, char word[], char s_word[], unsigned long& ans)
{
	int  no;
	char ts_word[40];	
	int i;
	int j;

	if (now < len - 1)
	{
		i = 0;
		while (i < len)
		{
			if (word[now] == s_word[i])
			{
				no = 0;
				for (j = 0 ; j < len; j++)
					if (i != j)
					{
						ts_word[no] = s_word[j];
						no++;
					}
				ts_word[no] = 0;

				find_ans(now + 1, len, word, ts_word, ans);
				break;
			}				
			else	
			{				
				no = 0;
				for (j = 0 ; j < len; j++)
					if (i != j)
					{
						ts_word[no] = s_word[j];
						no++;
					}
				ts_word[no] = 0;

				ans = ans + permutation(ts_word);
			}

			for (i = i + 1; i < len; i++)
				if (s_word[i] != s_word[i-1])
					break;
		}
	}
}


int main()
{
	int  len;
	char word[40];
	char s_word[40];
	unsigned long ans;

	//read input
	cin >> word;
	while (strcmp(word, "#") != 0)
	{
		//initial
		len = strlen(word);
		strcpy(s_word, word);

		//sort word
		s_sort(s_word);

		ans = 1;
		find_ans(0, len, word, s_word, ans);

		//output result
		printf("%10ld\n", ans);		

		cin >> word;
	}

	return 0;
}