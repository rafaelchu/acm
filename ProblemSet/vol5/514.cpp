// 514 - Rails

#include <iostream>

using namespace std;

int main()
{
	int n;
	int train_out[1000];	//the order of the train arrived B
	int station[1000];		//trains stopped in the station (a stack)
	int top;

	int a_no;				//the number of started train at A
	int b_no;				//the number of arrived train at B

	//read inpupt
	cin >> n;
	while (n != 0)
	{
		cin >> train_out[0];
		while (train_out[0] != 0)
		{
			for (b_no = 1; b_no < n; b_no++)
				cin >> train_out[b_no];

			//initial
			top = -1;

			//can arrive B directly
			b_no = 0;
			a_no = 1;
			while (a_no <= n)	
			{
				if (train_out[b_no] > a_no)					//train is stopped into station
				{
					station[++top] = a_no;
					a_no++;
				}
				else if (train_out[b_no] == a_no)			//trains arrive B directly
				{
					a_no++;
					b_no++;
				}
				else if (train_out[b_no] == station[top])	//trains in the station are to B
				{
					b_no++;
					top--;
				}
				else										//crash
				{
					break;
				}
			}

			while (b_no < n)					
			{
				if (station[top] == train_out[b_no])		//trains in the station are to B
				{
					b_no++;
					top--;
				}
				else										//crash
				{					
					break;
				}
			}

			//output result
			if (b_no >= n)						//all trains are arrived
				cout << "Yes" << endl;
			else
				cout << "No" << endl;
			
			cin >> train_out[0];
		}

		cout << endl;
		cin >> n;
	}

	return 0;
}