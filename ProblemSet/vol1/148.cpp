// 148 - Anagram checker

#include <iostream>
#include <string.h>

using namespace std;

void find_ans(int dic_no, char dic[][22], int s_no, int word[], char o_word[], int ans_no, int ans_word[], int ans[])
{
	int t_ans_word[26];
	int i;

	ans[ans_no] = s_no;
	ans_no++;
	for (i = 0; i < 26; i++)
		t_ans_word[i] = ans_word[i];
	for (i = 0; i < strlen(dic[s_no]); i++)
		t_ans_word[dic[s_no][i]-'A']++;

	for (i = 0; i < 26; i++)
		if (t_ans_word[i] != word[i])
			break;
	if (i >= 26)
	{
		char o_ans[40100];		
		char* token;
		char sep[] = " \n";

		strcpy(o_ans, o_word);
		token = strtok(o_ans, sep);
		while (token)
		{
			for (i = 0; i < ans_no; i++)
				if (strcmp(token, dic[ans[i]]) == 0)
					break;

			if (i >= ans_no)
				break;
			token = strtok(NULL, sep);
		}

		if (token)
		{
			//output result
			cout << o_word << " = ";
			for (i = 0; i < ans_no-1; i++)
				cout << dic[ans[i]] << ' ';
			cout << dic[ans[i]] << endl;
		}				
	}
	else
	{
		for (i = 0; i < 26; i++)
			if (t_ans_word[i] > word[i])
				break;
		if (i >= 26)
		{
			for (i = s_no + 1; i < dic_no; i++)
				find_ans(dic_no, dic, i, word, o_word, ans_no, t_ans_word, ans);
		}
	}
}

int main()
{
	int  dic_no;
	char dic[2010][22];
	int  word[26];	
	int  ans[2010];
	int  ans_word[26];
	char temp[40100];
	int  i;
	int  j;

	//read input - dic
	dic_no = 0;
	cin >> dic[dic_no];
	while (strcmp(dic[dic_no], "#") != 0)
	{
		dic_no++;
		cin >> dic[dic_no];
	}

	//read input - phrase
	cin.getline(temp, 40100);
	cin.getline(temp, 40100);
	while (strcmp(temp, "#") != 0)
	{
		for (i = 0; i < 26; i++)
		{
			word[i] = 0;
			ans_word[i] = 0;
		}

		//assign word
		j = 0;
		for (i = 0; i < strlen(temp); i++)
		{
			if (temp[i] != ' ')
				word[temp[i]-'A']++;
		}

		for (i = 0; i < dic_no; i++)
			find_ans(dic_no, dic, i, word, temp, 0, ans_word, ans);

		cin.getline(temp, 40100);
	}

	return 0;
}