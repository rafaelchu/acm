// 231 - Testing the CATCHER

#include <iostream>
using namespace std;

int main()
{
	long set_no = 0;
	long height;
	long length;
	long last[10000];
	long i;

	// Read input
	cin >> height;
	while (height >= 0)
	{
		// Initial
		set_no++;
		last[0] = height;
		length = 0;

		cin >> height;
		while (height >= 0)
		{
			// Create a decreasing height array.
			if (height <= last[length])
			{
				length++;
				last[length] = height;
			}
			else if (height > last[0])
			{
				last[0] = height;
			}
			else
			{
				for (i = 1; i <= length; i++)
					if (last[i] < height)
						break;
				last[i] = height;
			}	

			cin >> height;
		}

		// Output result
		if (set_no > 1)
			cout << endl;
		cout << "Test #" << set_no << ":" << endl;
		cout << "  maximum possible interceptions: " << length + 1 << endl;

		cin >> height;
	}

	return 0;
}