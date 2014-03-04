// 264 - Count on Cantor

#include <iostream>
using namespace std;


int main()
{
	long Number_ok;
	long Number;
	long Index;
	long Temp;

	// Read input.
	while ( cin >> Number_ok )
	{
		// Find level.
		Number = Number_ok;
		Index = 0;
		while (Number > 0) {
			Index++;
			Number = Number - Index;
		}

		Temp = Index + Number;
		if (Index % 2 == 0)
			printf("TERM %ld IS %ld/%ld\n", Number_ok, Temp, Index + 1 - Temp);
		else
			printf("TERM %ld IS %ld/%ld\n", Number_ok, Index + 1 - Temp, Temp);
	}

	return 0;
}