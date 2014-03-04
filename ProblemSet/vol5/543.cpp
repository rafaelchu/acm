// 543 - Goldbach's Conjecture

#include <iostream>

using namespace std;

const int PSIZE = 250;

//Find all primes from 1 to 1000
void find_prime(long prime[], long& prime_no)
{
	long gap = 4;
	bool is_prime;
	long may_be_prime = 7;
	long i;

	prime[0] = 2;
	prime[1] = 3;
	prime[2] = 5;
	prime[3] = 7;
	prime_no = 4;
	while (prime[prime_no-1] < 1000)
	{
		may_be_prime += gap;
		gap = 6 - gap;
		is_prime = true;

		for (i = 3; ((prime[i] * prime[i] <= may_be_prime) && is_prime); i++)
			if (may_be_prime % prime[i] == 0)
				is_prime = false;
		if (is_prime)
			prime[prime_no++] = may_be_prime;
	}
}

bool is_prime(long prime[], long num)
{
	int i;

	for (i = 0; prime[i] * prime[i] <= num; i++)
		if (num % prime[i] == 0)
			return false;

	return true;
}

int main()
{
	long prime[PSIZE];		//Primes from 1 to 1000
	long prime_no;			//Count of primes
	long n;
	bool find;
	long i;

	//find all primes from 1 to 1000.
	find_prime(prime,prime_no);

	//read input
	cin >> n;
	while (n != 0)
	{
		//find answer
		for (i = 2; i <= n / 2; i++)
			if (is_prime(prime, i))
				if (is_prime(prime, n - i))
				{
					find = true;
					break;
				}

		//output result
		if (find)
			cout << n << " = " << i << " + " << n - i << endl;
		else
			cout << "Goldbach's conjecture is wrong." << endl;

		cin >> n;
	}

	return 0;
}