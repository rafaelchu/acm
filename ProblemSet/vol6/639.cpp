// 639 - Don't Get Rooked

#include <stdio.h>

int FindAffect(int board[][4], int board_no, int row, int col)
{
	int sum = 0;
	int i;

	if (board[row][col])
		return 10;
	
	for (i = col; i >= 0; i--)                // Left
		if (board[row][i])
			break;
		else
			sum++;

	for (i = col + 1; i < board_no; i++)      // Right
		if (board[row][i])
			break;
		else
			sum++;

	for (i = row - 1; i >= 0; i--)            // Up
		if (board[i][col])
			break;
		else
			sum++;

	for (i = row + 1; i < board_no; i++)      // Down
		if (board[i][col])
			break;
		else
			sum++;

	return sum;
}

void FillRock(int board1[][4], int board2[][4], int board_no, int row, int col)
{
	int i;
	
	for (i = col; i >= 0; i--)                // Left
		if (board1[row][i])
			break;
		else
			board2[row][i] = 1;

	for (i = col + 1; i < board_no; i++)      // Right
		if (board1[row][i])
			break;
		else
			board2[row][i] = 1;
		
	for (i = row - 1; i >= 0; i--)            // Up
		if (board1[i][col])
			break;
		else
			board2[i][col] = 1;

	for (i = row + 1; i < board_no; i++)      // Down
		if (board1[i][col])
			break;
		else
			board2[i][col] = 1;
}


int main()
{
	int board_no;
	int board1[4][4];	// original chess board
	int board2[4][4];	
	int board_small[4][4];
	char chess[4+1];
	int smallest;
	int smallest_row;
	int smallest_col;
	int rock_no;

	int i, j;

	for (scanf("%d", &board_no); board_no > 0; scanf("%d", &board_no))
	{
		//initial
		rock_no = 0;

		//read chess board
		for (i = 0; i < board_no; i++) 
		{
			scanf("%s", chess);
			for (j = 0; j < board_no; j++) {
				if (chess[j] != '.')
				{
					board1[i][j] = 1;
					board2[i][j] = 1;
				}
				else
				{
					board1[i][j] = 0;
					board2[i][j] = 0;
				}
			}
		}

		//caculate board_small[][]
		for (i = 0; i < board_no; i++)
			for (j = 0; j < board_no; j++)				
				board_small[i][j] = FindAffect(board1, board_no, i, j);

		while (1)
		{
			//find out smallest value inside board_small[][]
			smallest = 10;
			for (i = 0; i < board_no; i++)
				for (j = 0; j < board_no; j++)
					if (!board2[i][j] && board_small[i][j] < smallest)
					{
						smallest = board_small[i][j];
						smallest_row = i;
						smallest_col = j;
					}			
				
			//fill rock at the position which has smallest value
			if (smallest < 10)
			{
				FillRock(board1, board2, board_no, smallest_row, smallest_col);
				rock_no++;
			}
			else
				break;
		};

		//output result
		printf("%d\n", rock_no);
	}
    
    return 0;
}
