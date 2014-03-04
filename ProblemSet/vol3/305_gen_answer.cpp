// 305 - Joseph

#include <iostream>
#include <iomanip>

using namespace std;

//check m is the answer or not
bool Judge_m(int k, int m)
{
	int now_loc = 0;
	int temp = k * 2;	//number of all boys
	int i;

	for (i = 0; i < k; i++)
	{
		now_loc = (now_loc + m - 1) % temp;
		if (now_loc < k)
			return false;
		temp--;
	}

	return true;
}

int main()
{
	int k;
	int m;
	int i;

	//read input
	for (cin >> k; k; cin >> k)
	{
		i = 1;
		while (1)
		{
			m = (k + 1) * i;	//case 1
			if (Judge_m(k, m))
			{
				//output result
				cout << m << endl;
				break;
			}
				
			m++;              //case 2
			if (Judge_m(k, m))
			{
				//output result
				cout << m << endl;
				break;
			}
			i++;
		}
	}
	
	return 0;
}