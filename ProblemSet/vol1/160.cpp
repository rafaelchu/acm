// 160 - Factors and Factorials

#include <iostream>
#include <iomanip>

using namespace std;

//Find the prime from 1 to 100
void find_prime(int prime[], int& prime_no)
{
	int gap = 2;
	bool is_prime;
	int may_be_prime = 5;
	int i;

	prime[0] = 2;
	prime[1] = 3;
	prime[2] = 5;
	prime_no = 3;

	while (true)
	{
		may_be_prime += gap;
		gap = 6 - gap;
		is_prime = true;

		for (i = 2; ((prime[i] * prime[i] <= may_be_prime) && is_prime); i++)
			if (may_be_prime % prime[i] == 0)
				is_prime = false;

		if (may_be_prime > 100)
			break;
		else if (is_prime)
			prime[prime_no++] = may_be_prime;
	}
}


int main(void)
{
	int prime[30];
	int prime_no;
	int answer[101][30];
	int n;	
	int ck;
	int cm;

	//initialize
	for (n = 0; n < 101; n++)
		for (ck = 0; ck < 30; ck++)
			answer[n][ck] = 0;
	
	//find primes
	find_prime(prime,prime_no);

	//factorization (2~100)
	for (n = 2; n <= 100; n++)
	{
		int ntemp = n;

		for (ck = 0; ck < prime_no; ck++)
		{
			for (cm = 0; (ntemp % prime[ck] == 0) && (ntemp > 1); cm++)	 
				ntemp = ntemp / prime[ck];

			if (cm > 0)
				answer[n][ck] = answer[n][ck] + cm;

			if (ntemp == 1)
				break;
		}
	}

	//factorization (2!~100!)
	for (n = 3; n <= 100; n++)
		for (ck = 0; ck < prime_no; ck++)
			answer[n][ck] = answer[n][ck] + answer[n - 1][ck];		
	
	//read input
	cin >> n;
	while (n != 0)
	{
		//output
		cout << setw(3) << n;
		cout << "! =";

		for (ck = 0; answer[n][ck] != 0; ck++)
		{
			if ((ck == 15) || (ck == 30))
				cout << endl << "      ";				

			cout << setw(3) << answer[n][ck];
		}
		cout << endl;

		cin >> n;		//read input
	}

	return 0;
}
