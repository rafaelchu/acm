// 120 - Stacks of Flapjacks
// Time limit: 3.000 seconds

#include <iostream>
using namespace std;

void Flip(int Stack[], int Top, int Number)
{
	int Queue[30];
	int End;
	int I;

	/*Initial*/
	End = -1;

	for (; Top >= Number;)		/*Pop*/
		Queue[++End] = Stack[Top--];

	for (I = 0; I <= End; I++) /*Push*/
		Stack[++Top] = Queue[I];
}

int main()
{
	int Stack[31];
	int StackT[31];
	int top;
	int Max;

	char Temp;
	int I;
	int J;

	/*Initial*/
	StackT[0] = 101; /*Set boundary*/
	top = 0;
	while (scanf("%d", &Stack[++top]) == 1) {
		/*Read input*/
		for (scanf("%c", &Temp); Temp != '\n'; scanf("%c", &Temp))
			scanf("%d", &Stack[++top]);

		// Output the original stack.
		cout << Stack[1];
		for ( int i = 2; i <= top; i++ )
			cout << " " << Stack[i];
		cout << endl;

		// Reverse the stack.
		I = 0;
		for (; top > 0; )
			StackT[++I] = Stack[top--];
		top = I;

		// Move pancake.
		for (I = 1; I <= top; I++) {
			Max = I;
			for (J = I + 1; J <= top; J++)
				if (StackT[J] > StackT[Max])
					Max = J;

			if (Max != I) {
				if (Max != top) {
					Flip(StackT, top, Max);
					printf("%d ", Max);
				}

				Flip(StackT, top, I);
				printf("%d ", I);
			}
		}

		// Output the terminal '0'.
		cout << "0" << endl;
		top = 0;
	}

	return 0;
}