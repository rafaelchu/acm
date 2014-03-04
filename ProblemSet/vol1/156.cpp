// 156 - Ananagrams

#include <iostream>
#include "string.h"
#include "stdlib.h"
#include "stdio.h"

using namespace std;

int compare(const void* a, const void* b)
{
	return strcmp((char* )a ,(char* )b);
	//return intcmp((int* )a ,(int* )b);
}


void word_copy(char word[], char s[])
{
	int len = strlen(word);
	int i;

	strcpy(s, word);
	for (i = 0; i < len; i++)			//to lower case
	{
		if (s[i] < 'a')
			s[i] = s[i] + ('a' - 'A');
	}
	qsort((void* )s, len,sizeof(char),compare);
}

int main()
{
	int  dic_no;
	char dic[100][25];
	char dic2[1010][25];
	char word[25];
	bool ok[1010];
	int  i;
	int  j;


	//read input
	dic_no = 0;
	cin >> word;
	while (strcmp(word, "#") != 0)
	{		
		strcpy(dic[dic_no], word);		
		dic_no++;

		cin >> word;
	}
	qsort((void* )dic, dic_no,sizeof(char)*25,compare);
	for (i = 0; i < dic_no; i++)
		word_copy(dic[i], dic2[i]);	

	//find which words are Ananagrams
	for (i = 0; i < dic_no; i++)
		ok[i] = true;
	for (i = 0; i < dic_no - 1; i++)	
		if (ok[i])
		{
			bool ana = false;	//Is ananagrams or not

			for (j = i + 1; j < dic_no; j++)
			{
				if (strcmp(dic2[i], dic2[j]) == 0)
				{
					if (strcmp(dic[i], dic[j]) != 0)
						ana = true;
					ok[j] = false;					
				}
			}

			if (ana)
				ok[i] = false;
		}	

	//output result	
	for (i = 0; i < dic_no; i++)
		if (ok[i])
			cout << dic[i] << endl;

	return 0;
}


