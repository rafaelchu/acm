// 101 - The Blocks Problem
#include <stdio.h>
#include <string.h>

#define MOVE "move"
#define QUIT "quit"
#define ONTO "onto"

struct pair_type {
    int stack_no;
    int height;
};

int main()
{
	int N;
	int Stack_array[24][24];
	int Top_array[24];
	struct pair_type Block_loc[24];
	char Action[10];
	char Direct[10];
	int A;
	int B;
	int T_stack_no;
	int T_stack[24];
	int T_top;
	int I;
	int J;
    
	/*Read input*/
	scanf("%d", &N);
    
	/*Initial*/
	for (I = 0; I < N; I++) {
		Stack_array[I][0] = I;
		Top_array[I] = 0;
		Block_loc[I].stack_no = I;
		Block_loc[I].height = 0;
	}
    
	/*read the robot action*/
	for (scanf("%s", Action); strcmp(Action, QUIT) != 0; scanf("%s", Action)) {
		scanf("%d %s %d", &A, Direct, &B);
		if (A != B) {
			/*Find the block A and block B*/
			if (!strcmp(Action, MOVE)) {	/*move block*/
				/*move blocks below block A to initial position*/
				for (I = Top_array[Block_loc[A].stack_no]; I != Block_loc[A].height; I--) {
					J = Stack_array[Block_loc[A].stack_no][I];
					Stack_array[J][++Top_array[J]] = J;
					Block_loc[J].stack_no = J;
					Block_loc[J].height   = Top_array[J];
				}
				Top_array[Block_loc[A].stack_no] = I;
                
				if (!strcmp(Direct, ONTO)) {   /*move onto*/
					/*move blocks below block B to initial position*/
					for (I = Top_array[Block_loc[B].stack_no]; I != Block_loc[B].height; I--) {
						J = Stack_array[Block_loc[B].stack_no][I];
						Stack_array[J][++Top_array[J]] = J;
						Block_loc[J].stack_no = J;
						Block_loc[J].height   = Top_array[J];
					}
					Top_array[Block_loc[B].stack_no] = I;
				}
                
				/*move A to B*/
				Top_array[Block_loc[A].stack_no]--;
				Stack_array[Block_loc[B].stack_no][++Top_array[Block_loc[B].stack_no]] = A;
				Block_loc[A].stack_no = Block_loc[B].stack_no;
				Block_loc[A].height = Top_array[Block_loc[B].stack_no];
			}
			else { /*pile block*/
				if (!strcmp(Direct, ONTO)) {
					/*move blocks below block B to initial position*/
					for (I = Top_array[Block_loc[B].stack_no]; I != Block_loc[B].height; I--) {
						J = Stack_array[Block_loc[B].stack_no][I];
						Stack_array[J][++Top_array[J]] = J;
						Block_loc[J].stack_no = J;
						Block_loc[J].height   = Top_array[J];
					}
					Top_array[Block_loc[B].stack_no] = I;
				}
                
				/*pile A to B*/
				T_top = -1;
				for (I = Block_loc[A].height; I <= Top_array[Block_loc[A].stack_no]; I++)
					T_stack[++T_top] = Stack_array[Block_loc[A].stack_no][I];
				Top_array[Block_loc[A].stack_no] = Block_loc[A].height - 1;
                
				T_stack_no = Block_loc[B].stack_no;
				for (I = 0; I <=  T_top; I++) {
					Stack_array[T_stack_no][++Top_array[T_stack_no]] = T_stack[I];
					Block_loc[T_stack[I]].stack_no = T_stack_no;
					Block_loc[T_stack[I]].height   = Top_array[T_stack_no];
				}
                
				/*
                 T_height   = Block_loc[A].height;
                 T_stack_no = Block_loc[A].stack_no;
                 for (I = T_height; I <= Top_array[T_stack_no]; I++) {
                 J = Stack_array[T_stack_no][I];
                 Stack_array[B][++Top_array[B]] = J;
                 Block_loc[J].stack_no = B;
                 Block_loc[J].height   = Top_array[B];
                 }
                 Top_array[T_stack_no] = T_height - 1;*/
			}
		}
	}
    
	/*Output result*/
	for (I = 0; I < N; I++) {
		printf("%d:", I);
		for (J = 0; J <= Top_array[I]; J++)
			printf(" %d", Stack_array[I][J]);
		printf("\n");
	}
    
	return 0;
}