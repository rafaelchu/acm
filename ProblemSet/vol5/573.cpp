// 573 - The Snail

#include <iostream>

using namespace std;

int main()
{	
	double h;
	double u;
	double d;
	double f;
	double now;
	int day;

	//read intput
	cin >> h >> u >> d >> f;
	while ((h != 0) && (u != 0) && (d != 0) && (f != 0))
	{
		//initial
		f = u * f / 100;
		now = 0;
		day = 0;
		
		//find out the answer
		while (now >= 0)
		{
			day++;
			now = now + u;

			if (now > h)
				break;			
			now = now - d;
			u = u - f;
			if (u < 0)
				u = 0;
		}

		//output the result
		if (now > h)
			cout << "success on day " << day << endl;
		else
			cout << "failure on day "  <<day << endl;

		cin >> h >> u >> d >> f;
	}

	return 0;
}

