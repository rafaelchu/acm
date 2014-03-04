// 105 - The Skyline Problem
// Time limit: 3.000 seconds 

#include <iostream>
using namespace std;

int main()
{
	int l;
	int h;
	int r;
	int building[20010];	//  building[i] records the maximum height in (i, i+1).
	int l_min;
	int r_max;

	int i;

	// Initial
	for (i = 0; i < 20010; i++)
		building[i] = 0;	
	r_max = -20000;

	// Read input
	cin >> l >> h >> r;
	l_min = l + 10000;
	do 
	{
		// Calculate maximum height from 1 to r.
		l = l + 10000;
		r = r + 10000;
		for (i = l; i < r; i++)
		{
			if (h > building[i])
				building[i] = h;
		}

		if (r > r_max)
			r_max = r;
	} while(cin >> l >> h >> r);

	// Print output	
	cout << l_min - 10000;	
	for (i = l_min + 1; i <= r_max; i++)
	{
		if (building[i - 1] != building[i])
			cout << ' ' << building[i - 1] << ' ' << i - 10000;
	}		
	cout << " 0" << endl;

	return 0;
}

