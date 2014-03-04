// 642 - Word Amalgamation

#include <iostream>
#include "string.h"
#include "stdlib.h"

using namespace std;

const int MAX_LEN = 10;

//Selection sort for dictionary
void Sort1(char Word[100][10], int Word_len) 
{
	int Smallest;
	char Temp[MAX_LEN];

	int J;
	int K;

	for (J = 0; J < Word_len - 1; J++) {
		Smallest = J;
		for (K = J + 1; K < Word_len; K++)
			if (strcmp(Word[K],Word[Smallest]) < 0)
				Smallest = K;

		strcpy(Temp, Word[J]);
		strcpy(Word[J], Word[Smallest]);
		strcpy(Word[Smallest], Temp);
	}
}

//Selection sort
void Sort2(char Word[], int Word_len) 
{
	int Smallest;
	char Temp;

	int J;
	int K;

	for (J = 0; J < Word_len - 1; J++) {
		Smallest = J;
		for (K = J + 1; K < Word_len; K++)
			if (Word[K] < Word[Smallest])
				Smallest = K;

		Temp = Word[J];
		Word[J] = Word[Smallest];
		Word[Smallest] = Temp;
	}
}

int main()
{
	int word_no;
	char dictionary[100][MAX_LEN];
	char sort_dic[100][MAX_LEN];
	char test_word[MAX_LEN];
	bool find;
	int i;

	//initial
	word_no = 0;

	//read dictionary and sort it
	cin >> dictionary[word_no];
	while (strcmp(dictionary[word_no], "XXXXXX") != 0)
	{
		word_no++;
		cin >> dictionary[word_no];
	}
	Sort1(dictionary, word_no);

	//generate sorted dictionary
	for (i = 0; i < word_no; i++)
	{
		strcpy(sort_dic[i], dictionary[i]);
		Sort2(sort_dic[i], strlen(sort_dic[i]));
	}

	//read words
	cin >> test_word;
	while (strcmp(test_word, "XXXXXX") != 0)
	{
		Sort2(test_word, strlen(test_word));
        
        //output result
		find = false;        
		for (i = 0; i < word_no; i++)
		{
			if (strcmp(test_word, sort_dic[i]) == 0)
			{
				cout << dictionary[i] << endl;
				find = true;
			}
		}
		if (!find)
		{
			cout << "NOT A VALID WORD" << endl;
		}
		cout << "******" << endl;

        //read words
		cin >> test_word;
	}

	return 0;
}
