// 598 - Bundling Newspapers

#include <iostream>
#include <string.h>
#include <stdlib.h>

using namespace std;

const int NEWS_SIZE = 300;

//C(n, k) subset
void subset(int n, int k, char news[][50])
{
	int set[NEWS_SIZE];
	int position;
	int i;

	//initial
	for (i = 0; i < k; i++)
		set[i] = i;

	//output result
	cout << news[set[0]];
	for (i = 1; i < k; i++)
		cout << ", " << news[set[i]];
	cout << endl;

	position = k - 1;
	while (set[0] < n - k) 
	{
		if (set[k - 1] == n - 1)
			position--;
		else
			position = k - 1;
		set[position]++;

		for (i = position + 1; i < k; i++)
			set[i] = set[i - 1] + 1;

		//output result
		cout << news[set[0]];
		for (i = 1; i < k; i++)
			cout << ", " << news[set[i]];
		cout << endl;
	}
}

int submain()
{
	int  news_no;
	char news[NEWS_SIZE][50];
	char size[50];
	int  size_b;
	int  size_e;	
	char line[50];
	char sep[] = " /n";
	char* token;
	int i;

	//initial
	news_no = 0;

	//read input
	cin.getline(size, 50);
	while (cin.getline(line, 50))
	{
		if (strlen(line) == 0)
			break;
		strcpy(news[news_no], line);
		news_no++;
	}

	//get size
	token = strtok(size, sep);
	if (strcmp(token, "*") == 0)
	{
		size_b = 1;
		size_e = news_no;
	}
	else
	{
		size_b = atoi(token);
		token = strtok(NULL, sep);
		if (token)
			size_e = atoi(token);
		else
			size_e = size_b;
	}

	//generate sorting sequence
	for (i = size_b; i <= size_e; i++)
	{
		cout << "Size " << i << endl;
		subset(news_no, i, news);
		cout << endl;
	}


	return 0;
}

int main()
{
	int n;
	char line[50];
	int i;

	cin.getline(line, 50);
	n = atoi(line);
	cin.getline(line, 50);

	for (i = 0; i < n - 1; i++)
	{
		submain();
		cout << endl;
	}
	submain();

	return 0;
}