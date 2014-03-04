// 159 - Word Crosses

#include <iostream>
#include <string.h>

using namespace std;

struct word_type
{
	char str[15];
	int  len;
	int  place;
};


void result(word_type word[])
{
	int hor;
	int ver[2];
	int row;
	char table[100][100];
	int i;
	int j;

	//find horizontal row
	if (word[1].place >= word[3].place)
		hor = word[1].place;
	else
		hor = word[3].place;

	//find vertical column
	ver[0] = word[0].place;
	ver[1] = word[0].len + 3 + word[2].place;

	//Calculate the total number of row
	if ((word[1].len - word[1].place) >= (word[3].len - word[3].place))
		row = hor + word[1].len - word[1].place;
	else
		row = hor + word[3].len - word[3].place;

	//table
	int bcol = word[0].len + word[2].len + 3;	
	for (i = 0; i < row; i++)
		for (j = 0; j < bcol; j++)
			table[i][j] = ' ';

	for (i = 0; i < word[0].len; i++)
		table[hor][i] = word[0].str[i];
	for (i = 0; i < word[1].len; i++)
		table[hor - word[1].place + i][ver[0]] = word[1].str[i];

	for (i = 0; i < word[2].len; i++)
		table[hor][i + word[0].len + 3] = word[2].str[i];
	for (i = 0; i < word[3].len; i++ )
		table[hor - word[3].place + i][ver[1]] = word[3].str[i];
	
	//output result
	for (i = 0; i < row; i++)
	{
		for (j = 0; j < bcol; j++)
			cout << table[i][j];
		cout << endl;
	}
}

int main()
{	
	word_type word[4];
	int case_no;
	int i;
	int j;

	//read input
	case_no = 0;
	cin >> word[0].str;
	while (strcmp(word[0].str, "#") != 0)
	{
		cin >> word[1].str >> word[2].str >> word[3].str;
		case_no++;
		if (case_no > 1)
			cout << endl;

		//initial
		for (i = 0; i < 4; i++)
			word[i].len = strlen(word[i].str);

		//find the position
		for (i = 0; i < word[0].len; i++)
		{
			for (j = 0; j < word[1].len; j++)
				if (word[0].str[i] == word[1].str[j])
					break;
			if (j < word[1].len)
				break;
		}

		if (i < word[0].len)
		{
			word[0].place = i;
			word[1].place = j;

			for (i = 0; i < word[2].len; i++)
			{
				for (j = 0; j < word[3].len; j++)
					if (word[2].str[i] == word[3].str[j])
						break;
				if (j < word[3].len)
					break;
			}

			if (i < word[2].len)
			{
				word[2].place = i;
				word[3].place = j;			

				//output result
				result(word);
			}
			else
				cout << "Unable to make two crosses" << endl;
		}
		else 
			cout << "Unable to make two crosses" << endl;

		cin >> word[0].str;
	}

	return 0;
}

