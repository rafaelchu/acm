// 583 - Prime Factors

#include <iostream>

using namespace std;

//find 1~65000's primes
void find_prime(unsigned long prime[], long& prime_no)
{
	bool is_prime;
	unsigned long may_be_prime;
	long gap;
	long i;

	prime[0] = 2;
	prime[1] = 3;
	prime[2] = 5;
	prime_no = 3;
	may_be_prime = 5;
	gap = 2;

	while (may_be_prime + gap <= 65536)
	{
		may_be_prime += gap;
		gap = 6 - gap;
		is_prime = true;

		for (i = 2; ((prime[i] * prime[i] <= may_be_prime) && is_prime); i++)
			if (may_be_prime % prime[i] == 0)
				is_prime = false;

		if (is_prime)
			prime[prime_no++] = may_be_prime;
	}
}


int main()
{
	long prime_no;
	unsigned long prime[7000];
	long g1;
	unsigned long g;
	long i;

    //find 1~65000's primes
	find_prime(prime, prime_no);

	//read input
	cin >> g1;
	while (g1 != 0)
	{
		//output result (first digit)
		bool head = false;
		cout << g1 << " = ";
		i = 0;
		if (g1 < 0)
		{
			g = g1 * -1;
			head = true;
			cout << "-1";
		}
		else
		{
			g = g1;
			i = 0;
			while (prime[i] * prime[i] <= g)
				if (g % prime[i] == 0)
				{
					g = g / prime[i];
					head = true;
					cout << prime[i];
					break;
				}
				else
					i++;
		}

		//output result (other digits)
		while (prime[i] * prime[i] <= g)
			if (g % prime[i] == 0)
			{
				g = g / prime[i];
				cout << " x " << prime[i];
			}
			else
				i++;

		if (g > 1)
		{
			if (head)
				cout << " x " << g;
			else
				cout << g;
		}
		cout << endl;

		cin >> g1;
	}

	return 0;
}