// 374 - Big Mod

#include <stdio.h>
#include <math.h>

int main()
{
	long B;
	long P;
	long M;

	long Bonus;

	//read input
	while (scanf("%ld %ld %ld", &B, &P, &M) == 3) {
		if (B && P) {
			//initial
			Bonus = 1;

			while (P > 1) {
				if (B >= M)
					B = B % M;
				else if (P % 2 == 0) {
					B = B * B;
					P = P / 2;
					}
				else {
					Bonus = (Bonus * B) % M;
					B = B * B;
					P = (P - 1) / 2;
				}
			}
			B = ((B % M) * Bonus) % M;
		}

		//output result
		if (P)
			printf("%ld\n", B);
		else
			printf("1\n");

	}
}