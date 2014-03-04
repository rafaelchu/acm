// 641 - Do the Untwist

#include <iostream>
#include <string.h>

using namespace std;

int main()
{
	long k;
	long len;
	char word[100];
	long ccode[100];
	long pcode[100];
	long i;

	//read input
	cin >> k;
	while (k > 0)
	{
		cin >> word;

		//inital
		len = strlen(word);

		//find ciphercode
		for (i = 0; i < len; i++)
		{
			if ((word[i] >= 'a') && (word[i] <= 'z'))
				ccode[i] = word[i] - 'a' + 1;
			else if (word[i] == '.')
				ccode[i] = 27;
			else
				ccode[i] = 0;
		}

		//find plaincode
		for (i = 0; i < len; i++)
			pcode[(k * i) % len] = (ccode[i] + i) % 28;

		//output result
		for (i = 0; i < len; i++)
		{
			if (pcode[i] <= 0)
				cout << '_';
			else if (pcode[i] <= 26)
				cout << (char)('a' + pcode[i] - 1);
			else
				cout << '.';
		}
		cout << endl;

		cin >> k;
	}


	return 0;
}