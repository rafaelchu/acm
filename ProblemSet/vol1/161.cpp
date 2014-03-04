// 161 - Traffic Lights

#include <iostream>

using namespace std;

const int MAX = 30000;

void find_ans(int sig_no, int sig[], int sig_dis[])
{
	int hour;
	int minute;
	int min;
	int i;
	int j;

	//find the longest signal
	min = MAX;
	for (i = 0; i < sig_no; i++)
		if (sig[i] < min)
			min = sig[i];

	//calculate answer
	for (i = min; i <= 18000; i++)
	{
		for (j = 0; j < sig_no; j++)
			if ((i % sig[j]) >= sig_dis[j])
				break;

		if (j == sig_no)
			break;
	}

	//print output		
	if (i <= 18000)
	{
		hour = i / 3600;
		i = i % 3600;
		minute = i / 60;
		i = i % 60;

		if (hour < 10)
			cout << '0' << hour << ':';
		else
			cout << hour << ':';
		if (minute < 10)
			cout << '0' << minute << ':';
		else
			cout << minute << ':';
		if (i < 10)
			cout << '0' << i << endl;
		else
			cout << i << endl;
	}
	else
		cout << "Signals fail to synchronise in 5 hours" << endl;

}

int main()
{
	int  sig_no;
	int  sig[105];
	int  sig_dis[105];	
	int  z_no;
	int  i;

	//initial
	z_no = 0;

	//read input	
	while (z_no < 2)
	{
		sig_no = 0;
		cin >> i;
		while (i > 0)
		{
			sig_dis[sig_no] = i - 5;
			sig[sig_no] = i * 2;
			sig_no++;
			cin >> i;
		}

		if (sig_no != 0)
			find_ans(sig_no, sig, sig_dis);
		else
			z_no++;
	}
	
	return 0;
}