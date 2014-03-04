// 357 - Let Me Count The Ways

#include <stdio.h>

int Partition(int N, int M)
{
	if (N == 1 || M == 1) {
		return 1;
	}
	else if (N < M) {
		switch (M) {
			case 50: return Partition(N, 25);
			case 25: return Partition(N, 10);
			case 10: return Partition(N, 5);
			case 5:  return Partition(N, 1);
		}
	}
	else if (N == M) {
		switch (M) {
			case 50: return 1 + Partition(N, 25);
			case 25: return 1 + Partition(N, 10);
			case 10: return 1 + Partition(N, 5);
			case 5:  return 1 + Partition(N, 1);
		}
	}
	else {
		switch (M) {
			case 50: return Partition(N, 25) + Partition(N - M, 50);
			case 25: return Partition(N, 10) + Partition(N - M, 25);
			case 10: return Partition(N, 5) + Partition(N - M, 10);
			case 5:  return Partition(N, 1) + Partition(N - M, 5);
		}
	}
    
    return 0;
}


int main()
{
	int Number;
	int Part;

	//read input
	while (scanf("%d", &Number) == 1) {
		Part = Partition(Number, 50);

		//output result
		if (Part != 1)
			printf("There are %d ways to produce %d cents change.\n", Part, Number);
		else
			printf("There is only 1 way to produce %d cents change.\n", Number);
	}
	
	return 0;
}