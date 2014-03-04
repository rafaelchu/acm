// 111 - History Grading
// Time limit: 3.000 seconds 

#include <iostream>
using namespace std;

// Compare which one (a or b) appears first in order[]
int compare(int n, int order[], int a, int b)
{
	int i;

	for (i = 0; i < n; i++)
	{
		if ((order[i] == a) && (order[i] == b))
			return 0;			// a = b
		else if (order[i] == a) 
			return -1;			// a < b
		else if (order[i] == b)
			return 1;			// a > b
	}

	return 0;	// a and b does not appear in rank.
}

// Convert rank to order.
void change(int n, int rank[], int order[])
{
	int i;

	for (i = 0; i < n; i++)
		order[rank[i] - 1] = i + 1;
}

int main()
{
	int n;
	int order[30];
	int student[30];
	int len;
	int last[30];
	int temp[30];
	int left;
	int mid;
	int right;
	int i;

	// Read input
	cin >> n;
	for (i = 0; i < n; i++)
		cin >> temp[i];
	change(n, temp, order);

	while (cin >> temp[0])
	{
		for (i = 1; i < n; i++)
			cin >> temp[i];
		change(n, temp, student);

		// Initialize variables.
		len = 1;
		last[0] = student[0];

		// Find the longest increasing subsequence.
		for (i = 1; i < n; i++)
		{
			if (compare(n, order, student[i], last[len-1]) >= 0)
			{
				last[len] = student[i];
				len++;
			}
			else if (compare(n, order, student[i], last[0]) < 0)
				last[0] = student[i];
			else
			{
				//binary search
				left = 0;
				right = len - 1;

				while (left != right - 1)
				{
					mid = (left + right) / 2;
					if (compare(n, order, student[i], last[mid]) >= 0)
						left = mid;
					else
						right = mid;
				}

				last[right] = student[i];
			}
		}

		// Output result.
		cout << len << endl;
	}

	return 0;
}