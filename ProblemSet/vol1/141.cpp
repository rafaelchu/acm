// 141 - The Spot Game

#include <stdio.h>
#include <stdlib.h>

#define ADD '+'
#define SUB '-'
#define SPOT 1
#define EMPTY 0

typedef struct board_type *board_ptr;
typedef struct board_type {
					short int board[51][51];
					board_ptr link;
					};

void Rotation(int Range, short int O_board[][51], short int N_board[][51])
{
	int Row;
	int Col;
	int T_row;

	T_row = Range + 1;
	for (Row = 1; Row <= Range; Row++) {
		T_row --;
		for (Col = 1; Col <= Range; Col++) {
			N_board[Col][T_row] = O_board[Row][Col];
		}
	}
}

short int Check_B(int Range, short int O_board[][51], short int N_board[][51])
{
	int Row;
	int Col;
	int Same = 0;

	for (Row = 1; Row <= Range; Row++)
		for (Col = 1; Col <= Range; Col++)
			if (O_board[Row][Col] == N_board[Row][Col])
				Same++;

	if (Same == Range * Range)
		return 1;
	else
		return 0;
}


int main(void)
{
	board_ptr Board_head;
	board_ptr Temp;
	board_ptr Now;
	int N;
	int Row;
	int Col;
	char Dir;
	short int Temp_B[51][51];
	short int Temp_C[51][51];
	short int Temp_D[51][51];
	int I;
	int J;

	/*Read input*/

	scanf("%d", &N);
	while (N != 0) {
		/*Initial*/
		Board_head = NULL;

		for (I = 1; I <= N * 2; I++) {
			/*Copy old board to new board*/
			if (!Board_head) {
				Board_head = (board_ptr) malloc(sizeof(struct board_type));
				for (Row =0; Row < 51; Row++)
					for (Col = 0; Col < 51; Col++)
						Board_head->board[Row][Col] = EMPTY;
				Board_head->link = NULL;
				Now = Board_head;
			}
			else {
				for (Temp = Board_head; Temp->link; Temp = Temp->link);
				Temp->link = (board_ptr) malloc(sizeof(struct board_type));
				for (Row =0; Row < 51; Row++)
					for (Col = 0; Col < 51; Col++)
						Temp->link->board[Row][Col] = Temp->board[Row][Col];
				Temp->link->link = NULL;
				Now = Temp->link;
			}

			/*Read new sopt*/
			scanf("%d %d %c", &Row, &Col, &Dir);
			switch (Dir) {
				case ADD : Now->board[Row][Col] = SPOT;  break;
				case SUB : Now->board[Row][Col] = EMPTY;
			}

			/*Check correct sopt loc*/
			for (Temp = Board_head; Temp != Now; Temp = Temp->link) {
				/*0 degrees*/
				if (Check_B(N, Temp->board, Now->board))
					break;

				/*90 degrees*/
				Rotation(N, Temp->board, Temp_B);
				if (Check_B(N, Temp_B, Now->board))
					break;

				/*180 degrees*/
				Rotation(N, Temp_B, Temp_C);
				if (Check_B(N, Temp_C, Now->board))
					break;

				/*270 degrees*/
				Rotation(N, Temp_C, Temp_D);
				if (Check_B(N, Temp_D, Now->board))
					break;
			}

			/*Find error position*/
			if (Temp != Now)
				break;
		}

		/*Judge who wins?*/
		if (I > N * 2)
			printf("Draw\n");
		else {
			/*read rest input*/
			for (J = I + 1; J <= N * 2; J++)
				scanf("%d %d %c", &Row, &Col, &Dir);

			if (I % 2 == 0)
				printf("Player 1 wins on move %d\n", I);
			else
				printf("Player 2 wins on move %d\n", I);
		}

		/*Read next board*/
		scanf("%d", &N);
	}
    
    return 0;
}