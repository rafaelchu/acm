// Problem: Street Numbers
#include <stdio.h>

int main()
{
	long count;
	long long int hsum;
	long home; 
	long long int lsum;
	long last;

	printf("%10d%10d\n", 6, 8);
	printf("%10d%10d\n", 35, 49);
	count = 2;
	hsum =0;
	for (home = 1; home <= 36; home++)
		hsum = hsum + home;
	home--;
	lsum =0;
	for (last = 36; last <= 49; last++)
		lsum = lsum + last;
	last--;

	while (count < 10) {
		while (hsum != lsum) {
			if (hsum < lsum) {
				lsum = lsum - home;
				home++;
				hsum = hsum + home;
			}
			else {
				last++;
				lsum = lsum + last;
			}
		}
		count++;
		printf("%10ld%10ld\n", home, last);

		lsum = lsum - home;
		home++;
		hsum = hsum + home;
	}

	return 0;
}
