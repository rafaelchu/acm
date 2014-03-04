// 100 - The 3n + 1 problem.
// Time limit: 3.000 seconds

#include <iostream>
using namespace std;

int calculate_count(int number)
{
	int count = 1;
	while ( number > 1 )
	{
		if ( number % 2 != 0 )
			number = number * 3 + 1;
		else
			number = number / 2;
		count++;
	}

	return count;
}

int main()
{
	int val1 = 0;
	int val2 = 0;

	while ( cin >> val1 )
	{
		cin >> val2;

		int max_count = 0;
		if ( val1 <= val2 )
			for ( int i = val1; i <= val2; i++ )
			{
				int count = calculate_count(i);
				if ( count > max_count )
					max_count = count;
			}
		else
			for ( int i = val2; i <= val1; i++ )
			{
				int count = calculate_count(i);
				if ( count > max_count )
					max_count = count;
			}

		printf("%d %d %d\n", val1, val2, max_count);
	}
	return 0;
}