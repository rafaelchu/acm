// 352 - The Seasonal War

#include <iostream>

using namespace std;

//delete oil
void delete_oil(char land[][30], long& m, long& n, long row, long col)
{
	if ((row < 0) || (row >= m) || (col < 0) || (col >= n))	//border
		return;
	else if (land[row][col] == '0')							//not oil
		return;
	else									
	{
		//delete it
		land[row][col] = '0';

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
	long set_no;
	long n;
	char image[30][30];
	long war_no;
	long i;
	long j;
	
	//initial
	set_no = 0;

	//read input
	while (cin >> n)
	{
		for (i = 0; i < n; i++)		
				cin >> image[i];

		//initial
		set_no++;
		war_no = 0;

		//find ans
		for (i = 0; i < n; i++)
			for (j = 0; j < n; j++)
				if (image[i][j] == '1')
				{
					war_no++;
					delete_oil(image, n, n, i, j);
				}

		//output result
		cout << "Image number " << set_no << " contains " << war_no << " war eagles." << endl;
	}

	return 0;
}