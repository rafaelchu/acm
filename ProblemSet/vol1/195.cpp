// 195 - Anagram

#include <string.h>
#include <iostream>

using namespace std;

void Sort(int Word_ascii[], int Start, int Word_len) /*Selection sort*/
{
	int Smallest;
	int Temp;
	int J;
	int K;

	for (J = Start; J < Word_len - 1; J++) {
		Smallest = J;
		for (K = J + 1; K < Word_len; K++)
			if (Word_ascii[K] < Word_ascii[Smallest])
				Smallest = K;

		Temp = Word_ascii[J];
		Word_ascii[J] = Word_ascii[Smallest];
		Word_ascii[Smallest] = Temp;
	}
}

void Print_char(int ascii)
{
	if ((ascii % 2) == 0)
		cout << (char)('A' + (ascii / 2));
	else
		cout << (char)('a' + (ascii - 1) / 2);
}

int main(void)
{
	int  word_no;
	char word[1000];
	int  word_ascii[1000];
	int  word_len;
	int  temp;
	int  i;
	int  j;
	int  k;

	/*Read input*/
	cin >> word_no;
	for (i = 0; i < word_no; i++) 
	{
		//Read word
		cin >> word;
		word_len = strlen(word);
		for (j = 0; j < word_len; j++)
			if ((word[j] >= 'A') && (word[j] <= 'Z'))
				word_ascii[j] = 2 * (word[j] - 'A');
			else
				word_ascii[j] = 2 * (word[j] - 'a') + 1;

		//sort word
		Sort(word_ascii, 0, word_len);

		//first word
		for (j = 0; j < word_len; j++)
			Print_char(word_ascii[j]);
		cout << endl;
		
		/*Find the permutation*/
		for (j = word_len - 1; j > 0;) 
		{
			if (word_ascii[j - 1] >= word_ascii[j])
				j--;
			else 
			{
				for (k = word_len - 1; k >= j - 1; k--)
					if (word_ascii[k] > word_ascii[j - 1])
						break;

				temp = word_ascii[j - 1];
				word_ascii[j - 1] = word_ascii[k];
				word_ascii[k] = temp;

				Sort(word_ascii, j, word_len);

				for (temp = 0; temp < word_len; temp++)
					Print_char(word_ascii[temp]);
				cout << endl;

				j = word_len - 1;
			}
		}
	}

	return 0;
}