// 124 - Following Orders

#include "string.h"
#include "stdio.h"
#include <iostream>

using namespace std;

//找出來所有的答案
void find_ans(bool path[][26], bool used[], int in_no[], int var_no, int ans_no, char ans[])
{
	int i;
	int j;

	if (ans_no == var_no)
	{
		for (i = 0; i < var_no; i++)
			cout << ans[i];
		cout << endl;
	}
	else
	{
		//找出來從now這一個char可以到哪些char
		for (i = 0; i < 26; i++)
			if ((in_no[i] == 0) && !used[i])
			{
				//update data
				used[i] = true;
				for (j = 0 ; j < 26; j++)
					if (path[i][j])
						in_no[j]--;
				ans[ans_no] = i + 'a';

				//DFS
				find_ans(path, used, in_no, var_no, ans_no + 1, ans);

				//backup data
				for (j = 0 ; j < 26; j++)
					if (path[i][j])
						in_no[j]++;
				used[i] = false;
			}
	}
}

int main()
{
	bool path[26][26];
	int  var_no;
	int  in_no[26];
	bool used[26];		//哪些char已經用過了
	char ans[26];
	char line[300];
	char sep[] = " \n";
	char* token;
	char* token2;
	int  i;
	int  j;
	bool bFirstLine = true;

	//read input
	while (cin.getline(line, 300))
	{
		if ( !bFirstLine )
			cout << endl;
		bFirstLine = false;

		//起始路徑資料
		var_no = 0;
		for (i = 0; i < 26; i++)
			for (j = 0; j < 26; j++)
				path[i][j] = false;
		for (i = 0; i < 26; i++)
		{
			in_no[i] = -1;
			used[i] = false;
			ans[i] = 0;
		}

		//找出哪些char需要計算
		token = strtok(line, sep);
		while (token)
		{
			var_no++;
			in_no[(*token) - 'a'] = 0;		//起使in的路徑個數為0

			token = strtok(NULL, sep);
		}

		//找出char間的順序關係
		cin.getline(line, 300);
		token = strtok(line, sep);
		while (token)
		{
			token2 = strtok(NULL, sep);

			path[(*token) - 'a'][(*token2) - 'a'] = true;
			in_no[(*token2) - 'a']++;

			token = strtok(NULL, sep);
		}

		//找出來這些字母的排列順序(Topological sort)
		find_ans(path, used, in_no, var_no, 0, ans);
	}

	return 0;
}