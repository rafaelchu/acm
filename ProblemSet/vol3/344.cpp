// 344 - Roman Digititis

#include <stdio.h>

void Break(int Number, int Array[])
{
	int Temp;

	Temp = Number / 10;
	Number = Number - Temp * 10;

	switch (Temp) {
		case 10:Array[4]++;
		case 9: Array[2]++;
				  Array[4]++; break;
		case 8: Array[2] = Array[2] + 3;
				  Array[3]++; break;
		case 7: Array[2] = Array[2] + 2;
				  Array[3]++; break;
		case 6: Array[2] = Array[2] + 1;
				  Array[3]++; break;
		case 5: Array[3]++; break;
		case 4: Array[2] = Array[2] + 1;
				  Array[3]++; break;
		case 3: Array[2] = Array[2] + 3; break;
		case 2: Array[2] = Array[2] + 2; break;
		case 1: Array[2] = Array[2] + 1; break;
	}

	switch (Number) {
		case 9: Array[0]++;
				  Array[2]++; break;
		case 8: Array[0] = Array[0] + 3;
				  Array[1]++; break;
		case 7: Array[0] = Array[0] + 2;
				  Array[1]++; break;
		case 6: Array[0] = Array[0] + 1;
				  Array[1]++; break;
		case 5: Array[1]++; break;
		case 4: Array[0] = Array[0] + 1;
				  Array[1]++; break;
		case 3: Array[0] = Array[0] + 3; break;
		case 2: Array[0] = Array[0] + 2; break;
		case 1: Array[0] = Array[0] + 1; break;
	}
}

int main()
{
	int Number;
	int Table[101][5];
	int Now;

	int I;

	//initial
	for (I = 0; I < 5; I++)
		Table[0][I] = 0;
	Now = 0;

	//read input
	for (scanf("%d", &Number); Number; scanf("%d", &Number)) {
		for (; Number > Now ;) {
			Now++;
			for (I = 0; I < 5; I++)
				Table[Now][I] = Table[Now - 1][I];

			//break now
			Break(Now, Table[Now]);
		}

		//output result
		printf("%d: %d i, %d v, %d x, %d l, %d c\n", Number,
				 Table[Number][0] , Table[Number][1], Table[Number][2],
				 Table[Number][3] , Table[Number][4]);
	}

	return 0;
}