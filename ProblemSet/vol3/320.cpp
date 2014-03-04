// 320 - Border

#include <stdio.h>

int main()
{
	int Case_no;
	short int Square[32][32];
	int Start_x;
	int Start_y;
	char Move;

	int I;
	int J;
	int K;

	//read input
	scanf("%d", &Case_no);

	for (I = 1; I <= Case_no; I++) {
		//initial
		for (J = 0; J < 32; J++)
			for (K = 0; K < 32; K++)
				Square[J][K] = 0;

		//read input
		scanf("%d %d", &Start_x, &Start_y);

		for (scanf("%c", &Move); Move != '.'; scanf("%c", &Move)) {
			switch (Move) {
				case 'E' : Square[31 - (Start_y - 1)][Start_x] = 1;
							  Start_x++; break;
				case 'S' : Square[31 - (Start_y - 1)][Start_x - 1] = 1;
							  Start_y--; break;
				case 'W' : Square[31 - Start_y][Start_x - 1] = 1;
							  Start_x--; break;
				case 'N' : Square[31 - Start_y][Start_x] = 1;
							  Start_y++; break;
			}
		}
		scanf("%c", &Move);

		//output result
		printf("Bitmap #%d\n", I);
		for (J = 0; J < 32; J++) {
			for (K = 0; K < 32; K++)
				if (Square[J][K])
					printf("X");
				else
					printf(".");
			printf("\n");
		}

		if (I != Case_no)
			printf("\n");
	}
	
	return 0;
}