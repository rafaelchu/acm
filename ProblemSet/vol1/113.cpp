// 113 - Power of Cryptography
// Time limit: 3.000 seconds 

#include <iostream>
#include <stdlib.h>
#include <math.h>

using namespace std;

int main()
{
	double long n;
	double long p;

	//read input
	while (cin >> n >> p)
		printf("%.0lf\n", pow(p, 1/n));

	return 0;
}