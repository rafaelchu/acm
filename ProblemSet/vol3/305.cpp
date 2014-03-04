// 305 - Joseph

#include <iostream>

using namespace std;

int main()
{
	int k;
	long answer[] = {0, 2, 7,5,30,169,441,1872,7632,1740,93313,459901,1358657,2504881};
	
	for (cin >> k; k; cin >> k)		//read input
		cout << answer[k] << endl;	//output result
		
	return 0;
}