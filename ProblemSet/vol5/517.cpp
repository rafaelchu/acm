// 517 - Word

#include <iostream>
#include <string.h>
#include <stdlib.h>

using namespace std;

typedef unsigned int uint16;		// we use this for "word"

int when [16385];
int whenTableLength;
uint16 maxWord;			// word consisting of all 1's
int wordLength;			// length of the word
uint16 MSB;				// mask of the most significant bit

char aWord [16];		// original word (alphanumeric)
uint16 origWord;		// original word (numeric)
uint16 actWord;			// actual word
char rules [9];			// 8 rules
long dist;
int step;

int Get (uint16 w)
{
	if (w == maxWord)
	  return when [whenTableLength-1];
	else
	  return when [w];
}

void Put (uint16 w, int s)
{
	if (w == maxWord)
	  when[whenTableLength-1] = s;
	else
	  when[w] = s;
}

uint16 AToN (char *s)	// first character = most significant bit
{
	uint16 result = 0;
	while (*s)
	  result = result*2 + (*(s++) == 'a' ? 0 : 1);
	return result;
}

char *NToA (uint16 w)
{
	static char buffer [16];
	int index = wordLength;
	buffer [index] = 0;
	while (index > 0)
	{
	  index--;
	  buffer [index] = (w % 2) ? 'b' : 'a';
	  w = w / 2;
	}
	return buffer;
}

uint16 OneStep (uint16 w)
{
	char *oldw, neww [16];
	int i;
	oldw = NToA (w);
	for (i=0; i<wordLength; i++)
	{
	  int index = (oldw [(i+wordLength-2)%wordLength] - 'a') * 4 +
		      (oldw [i] - 'a') * 2 +
		      (oldw [(i+1)%wordLength] - 'a');
	  neww[i] = rules [index];
	}
	neww[i] = 0;
	return AToN (neww);
}

uint16 Normalize (uint16 w)
{
	uint16 min = w;
	int i;
	for (i=0; i<wordLength; i++)
	{
	  w = ((w<<1)&maxWord) + ((w&MSB) >> (wordLength-1));
	  if (w < min)
	    min = w;
	}
	return min;
}

int main ()
{
	int i;

	while (cin >> wordLength)
	{
		cin >> aWord;

		//rule[0..8] should be filled.
		for (i = 0; i < 8; i++)
		{
			char rul[10];
			int index;
			cin >> rul;
			index = (rul[0] - 'a') * 4 + (rul[1] - 'a') * 2 + (rul[2] - 'a');
			rules [index] = rul[3];
		}

		// distance (s)
		cin >> dist;

		MSB = 1 << (wordLength-1);
		maxWord = ((unsigned int) 1 << wordLength) - 1;
		whenTableLength = MSB + 1;

		//initial
		for (int i = 0; i < whenTableLength; i++)
			when[i] = 0;

		origWord = Normalize (AToN (aWord));

		//dist is 0
		if (dist == 0)
		{
			cout << NToA (origWord) << endl;
			continue;
		}

		actWord = origWord;
		step = 0;
		while (true)
		{
			// do the step
			step++;
			actWord = Normalize (OneStep (actWord));

			// haven't we reached the destination (by chance) ?
			if (step == dist)
			{
				cout << NToA (actWord) << endl;
				break;
			}

			// look into the table
			int tmp = Get (actWord);
			if (tmp == 0)				// we haven't been here yet
				Put (actWord, step);	
			else						// oh a CYCLE, cool!
			{
				int pp = tmp;				// pre-period
				int p = step - pp;			// period
				int nd = ((dist-pp)%p)+pp;  // "normalized" distance

				// let's find the word with that distance from beginning
				for (i = 0; i < whenTableLength; i++)
					if (when[i] == nd)
						break;
				if (i == whenTableLength-1)
					i = maxWord;

				cout << NToA (i) << endl;
				break;
			}
		} // inner loop
	} // outer loop

	return 0;
}