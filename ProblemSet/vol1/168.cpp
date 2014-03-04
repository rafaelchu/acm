// 168 - Theseus and the Minotaur

#include <iostream>
#include "string.h"
#include "stdlib.h"
#include "stdio.h"

using namespace std;

struct o_type
{
	int loc;
	o_type* next;
};

void paser(char line[], bool path[][26], o_type* order[])
{
	char sep[] = ";.\n";
	char* token;
	int i;

	token = strtok(line, sep);
	while (token)
	{
		for (i = 2; i < strlen(token); i++)
		{
			path[token[0]-'A'][token[i]-'A'] = true;

			if (order[token[0]-'A'])
			{
                o_type* temp = NULL;
				for (o_type* temp = order[token[0]-'A']; temp->next; temp = temp->next);

				temp->next = new o_type;
				temp = temp->next;
				temp->loc = token[i]-'A';
				temp->next = NULL;				
			}
			else
			{
				order[token[0]-'A'] = new o_type;
				order[token[0]-'A']->loc = token[i]-'A';
				order[token[0]-'A']->next = NULL;
			}
		}

		token = strtok(NULL, sep);
	}
}


int main()
{
	bool path[26][26];		//p
	o_type* order[26];		//moving order
	char line[300];
	int  bull_loc;			//current location of Minotaur
	int  hero_loc;			//current location of Theseusªº
	long k;
	long step;				//how many steps of Theseus
	int  i;
	int  j;

	//read input
	cin >> line;
	while (strcmp(line, "#") != 0)
	{
		//paser input
		for (i = 0; i < 26; i++)
		{
			for (j = 0; j < 26; j++)
				path[i][j] = false;
			order[i] = NULL;
		}
		paser(line, path, order);

		cin >> line[0];
		bull_loc = line[0] - 'A';
		cin >> line[0];
		hero_loc = line[0] - 'A';
		cin >> k;

		//--------------begin simulation--------------
		step = 0;
		while (true)
		{
			//Minotaur escape
            o_type* ptr = order[bull_loc];
			while (ptr) 
            {
				if (path[bull_loc][ptr->loc] && (ptr->loc != hero_loc))
				{
					hero_loc = bull_loc;
					step++;
					bull_loc = ptr->loc;
					break;
				}
                
                ptr = ptr->next;
            }

			//Theseus get Minotaur!
			if (!ptr)
			{
				cout << '/' << static_cast<char>(bull_loc + 'A') << endl;
				break;
			}

			//Theseus lights up
			if (step % k == 0)
			{
				cout << static_cast<char>(hero_loc + 'A') << ' ';
				//erase the path
				for (i = 0; i < 26; i++)
					path[i][hero_loc] = false;
			}
		}

		cin >> line;
	}

	return 0;
}