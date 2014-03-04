// 127 - "Accordian" Patience

#include <iostream>

using namespace std;

struct card_type
{
	char suit;
	int  value;
};

struct pile_type
{
	int no;
	card_type card[52];
};

//��P���r���ন�Ʀr
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
	else if (temp[0] == 'K')
		return 13;
	else
		return 0;
}

void move_pile(pile_type pile[], int s_pile, int& pile_no)
{
	bool move;
	int  now;
	int  i;
	int  j;

	i = s_pile;
	while (i < pile_no)
	{
		//initial
		move = false;
		j = i;

		if (i - 3 >= 0)
		{
			if((pile[i-3].card[pile[i-3].no-1].suit == pile[i].card[pile[i].no-1].suit) ||
			   (pile[i-3].card[pile[i-3].no-1].value == pile[i].card[pile[i].no-1].value))
			{
				//move�줧�e��pile
				pile[i-3].card[pile[i-3].no].suit = pile[i].card[pile[i].no-1].suit;
				pile[i-3].card[pile[i-3].no].value = pile[i].card[pile[i].no-1].value;
				pile[i-3].no++;
				pile[i].no--;
				move = true;
				i = i - 3;
			}
		}

		if ((i - 1 >= 0) && !move)
		{
			if((pile[i-1].card[pile[i-1].no-1].suit == pile[i].card[pile[i].no-1].suit) ||
			   (pile[i-1].card[pile[i-1].no-1].value == pile[i].card[pile[i].no-1].value))
			{
				//move�줧�e��pile
				pile[i-1].card[pile[i-1].no].suit = pile[i].card[pile[i].no-1].suit;
				pile[i-1].card[pile[i-1].no].value = pile[i].card[pile[i].no-1].value;
				pile[i-1].no++;
				pile[i].no--;
				move = true;
				i = i - 1;
			}
		}

		//i�ŤF�A�G��i���᪺pile���e����
		if ((pile[j].no == 0) && (move))
		{			
			for (now = j; now < pile_no - 1; now++)
			{
				pile[now].no = pile[now+1].no;
				for (j = 0; j < pile[now].no; j++)
				{
					pile[now].card[j].suit = pile[now+1].card[j].suit;
					pile[now].card[j].value = pile[now+1].card[j].value;
				}						
			}

			pile_no--;
		}

		if (!move)
			i++;
	}
}


int main()
{
	int  pile_no;
	pile_type pile[52];
	int  now;
	int  index;
	bool move;
	char temp[10];
	int  i;

	//read input
	cin >> temp;
	while (temp[0] != '#')
	{
		//initial
		pile_no = 1;
		pile[0].no = 1;
		pile[0].card[0].value = to_card(temp);
		pile[0].card[0].suit = temp[1];

		//read rest card
		for (i = 1; i < 52; i++)
		{
			cin >> temp;

			//�ݬݷs�W�[���o�i�P�i�_�[�Jpile
			now = pile_no;
			move = false;
			if (now - 3 >= 0)
			{
				//�ˬd�O�_�i�Hmove
				index = now-3;
				if ((pile[index].card[pile[index].no-1].suit == temp[1]) ||
					(pile[index].card[pile[index].no-1].value == to_card(temp)))
				{
					move = true;
					pile[index].card[pile[index].no].suit = temp[1];
					pile[index].card[pile[index].no].value = to_card(temp);
					pile[index].no++;
				}
			}

			if ((now - 1 >= 0) && (!move))
			{
				//�ˬd�O�_�i�Hmove
				index = now-1;
				if ((pile[index].card[pile[index].no-1].suit == temp[1]) ||
					(pile[index].card[pile[index].no-1].value == to_card(temp)))
				{
					move = true;
					pile[index].card[pile[index].no].suit = temp[1];
					pile[index].card[pile[index].no].value = to_card(temp);
					pile[index].no++;
				}
			}

			//�s��pile
			if (!move)
			{
				index = now;
				pile[index].card[0].suit = temp[1];
				pile[index].card[0].value = to_card(temp);
				pile[index].no = 1;
				pile_no++;
			}

			//�ݬݷs�P�[�J��pile�|���|�A�[�J���e��pile
			move_pile(pile, index, pile_no);
		}

		//output result
		cout << pile_no;		
		if (pile_no == 1)
			cout << " pile remaining:";
		else
			cout << " piles remaining:";
		for (i = 0; i < pile_no; i++)
			cout << " " << pile[i].no;
		cout << endl;

		cin >> temp;
	}

	return 0;
}
