// 11877 - The Coco-Cola Store.
// Time limit: 1.000 seconds

#include <iostream>
using namespace std;

int main()
{
	int full_bottle_no[101];

	// Calculate numbers of full bottles for all cases.
	full_bottle_no[0] = 0;
	full_bottle_no[1] = 0;
	full_bottle_no[2] = 1;
	full_bottle_no[3] = 1;

	for ( int i = 4; i <= 100; i++ )
	{
		int previous = (i / 3) + (i % 3);
		full_bottle_no[i] = full_bottle_no[previous] + (i / 3);
	}

	// Read input and print output.
	int empty_bottle_no = 0;
	while ( cin >> empty_bottle_no )
	{
		if ( empty_bottle_no <= 0 )
			break;

		if ( (empty_bottle_no >= 1) && (empty_bottle_no <= 100) )
			printf("%d\n", full_bottle_no[empty_bottle_no]);
	}

	return 0;
}