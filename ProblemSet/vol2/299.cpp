// 299 - Train Swapping

#include <stdio.h>

int main()
{
	int Loc[51];
	int Case_no;
	int Length;
	int Swap_no;
	int Temp;
	int I;
	int J;
	int K;

	//read number of the test cases
	scanf("%d", &Case_no);

	for (I = 0; I < Case_no; I++) {
		Swap_no = 0;

		//read each case's input
		scanf("%d", &Length);
		for (J = 1; J <= Length; J++) {
			scanf("%d", &Temp);
			Loc[Temp] = J;
		}

		//calculate swapping
		for (J = 1; J <= Length; J++)
			if (Loc[J] != J) {
				for (K = J + 1; K <= Length; K++) //move other carriage*
					if (Loc[K] < Loc[J])
						Loc[K]++;

				for (K = Loc[J]; K > J; K--)  //move carriage J to correct location
					Swap_no = Swap_no + 1;
				Loc[J] = J;
			}

		//output result
		printf("Optimal train swapping takes %d swaps.\n", Swap_no);
	}
	
	return 0;
}