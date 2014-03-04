// 555 - Bridge Hands

#include <iostream>

using namespace std;

char s_table[] = "CDSH";
char r_table[] = "23456789TJQKA";

class card_type {
	long suit;
	long rank;

public:
	void set(char s, char r) {
		for (suit = 0; s_table[suit] != s; suit++);
		for (rank = 0; r_table[rank] != r; rank++);
	}

	char get_suit() {
		return s_table[suit];
	}

	char get_rank() {
		return r_table[rank];
	}

	bool operator < (card_type a) {
		if (suit < a.suit)
			return true;
		else if ((suit == a.suit) && (rank < a.rank))
			return true;
		else
			return false;
	}
};

int main()
{
	char dir;
	int first;
	card_type card[4][13];
	char suit;
	char rank;
	long i;
	long j;
	long k;

	//read input
	cin >> dir;
	while (dir != '#') {
		if (dir == 'N')
			first = 0;
		else if (dir == 'E')
			first = 1;
		else if (dir == 'S')
			first = 2;
		else 
			first = 3;

		for (i = 1; i <= 52; i++) {
			cin >> suit >> rank;
			card[(first+i)%4][(i-1)/4].set(suit, rank);
		}

		//sort card
		for (k = 0; k < 4; k++)
			for (i = 0; i < 13 - 1; i++) {
				long min = i;
				for (j = i + 1; j < 13; j++)
					if (card[k][j] < card[k][min])
						min = j;

				card_type temp = card[k][i];
				card[k][i] = card[k][min];
				card[k][min] = temp;
			}

		//output result
		cout << "S:";
		for (i = 0; i < 13; i++)
			cout << " " << card[2][i].get_suit() << card[2][i].get_rank();
		cout << endl;
		cout << "W:";
		for (i = 0; i < 13; i++)
			cout << " " << card[3][i].get_suit() << card[3][i].get_rank();
		cout << endl;
		cout << "N:";
		for (i = 0; i < 13; i++)
			cout << " " << card[0][i].get_suit() << card[0][i].get_rank();
		cout << endl;
		cout << "E:";
		for (i = 0; i < 13; i++)
			cout << " " << card[1][i].get_suit() << card[1][i].get_rank();
		cout << endl;

		cin >> dir;
	}

	return 0;
}