// 170 - Clock Patience

#include <iostream>
#include "string.h"

using namespace std;

struct pile_type
{
	int  no;
	char card[4][5];
};

//convert card number to numbers
int to_card(char temp[])
{
	if (temp[0] == 'A')
		return 1;
	else if ((temp[0] >= '2') && (temp[0] <= '9'))
		return temp[0] - '0';
	else if (temp[0] == 'T')
		return 10;
	else if (temp[0] == 'J')
		return 11;
	else if (temp[0] == 'Q')
		return 12;
	else
		return 0;
}


int main()
{	
	char card[52][5];			//cards
	pile_type pile[13];			//13 piles
	char now[5];				//current cards
	int  rest_no;				//remain cards
	char temp[5];
	int  i;

	//read input
	cin >> temp;
	while (strcmp(temp, "#") != 0)
	{
		strcpy(card[51], temp);

		//read input and initial
		for (i = 50; i >= 0; i--)
			cin >> card[i];
		for (i = 0; i < 13; i++)
			pile[i].no = 0;

		//start to deal
		for (i = 0; i < 52; i++)
		{
			int index = (i + 1) % 13;

			strcpy(pile[index].card[pile[index].no], card[i]);
			pile[index].no++;
		}

		//start to play game
		strcpy(now, pile[0].card[pile[0].no-1]);
		pile[0].no--;
		rest_no = 51;
		while (rest_no > 0)
		{
			int now_no = to_card(now) % 13;

			if (pile[now_no].no == 0)	//ª±¤£¤U¥hÅo!
				break;
			else
				rest_no--;

			strcpy(now, pile[now_no].card[pile[now_no].no-1]);
			pile[now_no].no--;
		}

		//output result
		rest_no = 52 - rest_no;
		if (rest_no < 10)
			cout << '0' << rest_no;
		else
			cout << rest_no;
		cout << ',' << now << endl;

		cin >> temp;
	}

	return 0;
}