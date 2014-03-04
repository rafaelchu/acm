// 572 - Oil Deposits

#include <iostream>

using namespace std;

// Delete the oil spot.
void delete_oil(char land[110][110], int& m, int& n, int row, int col)
{
	if ((row < 0) || (row >= m) || (col < 0) || (col >= n))	//boarder
		return;
	else if (land[row][col] == '*')							//not oil spot.
		return;
	else									
	{
		land[row][col] = '*';	//delete it

		delete_oil(land, m, n, row-1, col  );
		delete_oil(land, m, n, row-1, col+1);
		delete_oil(land, m, n, row  , col+1);
		delete_oil(land, m, n, row+1, col+1);
		delete_oil(land, m, n, row+1, col  );
		delete_oil(land, m, n, row+1, col-1);
		delete_oil(land, m, n, row  , col-1);
		delete_oil(land, m, n, row-1, col-1);
	}
}

int main()
{	
	int m;
	int n;	
	char land[110][110];
	int oil_no;
	int i;
	int j;
	
	//read input
	cin >> m >> n;
	while (m != 0) 
	{
		for (i = 0; i < m; i++)
			for (j = 0; j < n; j++)
				cin >> land[i][j];

		//find out the answer
		oil_no = 0;
		for (i = 0; i < m; i++)
			for (j = 0; j < n; j++)
				if (land[i][j] == '@')
				{
					oil_no++;
					delete_oil(land, m, n, i, j);	//delete the oil spot
				}

		//output result
		cout << oil_no << endl;

		cin >> m >> n;
	}

	return 0;
}

