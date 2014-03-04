// 183 - Bit Maps

#include <iostream>
#include "string.h"
#include "stdio.h"
#include "stdlib.h"

using namespace std;

//B-type => divide Bitmap to four parts 
void div_bitmap(char bitmap1[][205], int o_row, int o_col, int row, int col, long& bitmap2_no, char bitmap2[])
{
	int row_mid;
	int col_mid;
	int i;
	int j;

	bitmap2_no++;

	//check bitmap contains 0 only
	for (i = 0; i < row; i++)
	{
		for (j = 0; j < col; j++)
			if (bitmap1[o_row+i][o_col+j] != '0')
				break;
		if (j < col)
			break;
	}
	if (i >= row)
	{
		bitmap2[bitmap2_no-1] = '0';
		return;
	}

	//check bitmap contains 1 only
	for (i = 0; i < row; i++)
	{
		for (j = 0; j < col; j++)
			if (bitmap1[o_row+i][o_col+j] != '1')
				break;
		if (j < col)
			break;
	}
	if (i >= row)
	{
		bitmap2[bitmap2_no-1] = '1';
		return;
	}

	bitmap2[bitmap2_no-1] = 'D';

	if (row % 2 == 0)
		row_mid = row / 2;
	else
		row_mid = row / 2 + 1;
	if (col % 2 == 0)
		col_mid = col / 2;
	else
		col_mid = col / 2 + 1;

	//left-up		
	div_bitmap(bitmap1, o_row, o_col, row_mid, col_mid, bitmap2_no, bitmap2);

	//right-up
	if (col - col_mid > 0)
		div_bitmap(bitmap1, o_row, o_col+col_mid, row_mid, col-col_mid, bitmap2_no, bitmap2);

	//left-down
	if (row - row_mid > 0)
		div_bitmap(bitmap1, o_row+row_mid, o_col, row-row_mid, col_mid, bitmap2_no, bitmap2);

	//right-down
	if ((row - row_mid > 0) && (col - col_mid > 0))
		div_bitmap(bitmap1, o_row+row_mid, o_col+col_mid, row-row_mid, col-col_mid, bitmap2_no, bitmap2);
}


//D-type => combine Bitmap
void cat_bitmap(int bitmap2_no, char bitmap2[], long& now, int o_row, int o_col, int row, int col, char bitmap1[][205])
{
	int row_mid;	
	int col_mid;	
	int i;
	int j;

	if (now >= bitmap2_no)
		return;
	else if ((bitmap2[now] == '1') || (bitmap2[now] == '0'))	
	{
		for (i = 0; i < row; i++)
			for (j = 0; j < col; j++)
				bitmap1[o_row+i][o_col+j] = bitmap2[now];
	}
	else
	{
		if (row % 2 == 0)
			row_mid = row / 2;
		else
			row_mid = row / 2 + 1;
		if (col % 2 == 0)
			col_mid = col / 2;
		else
			col_mid = col / 2 + 1;

		//left-up	
		cat_bitmap(bitmap2_no, bitmap2, ++now, o_row, o_col, row_mid, col_mid, bitmap1);

		//right-up
		if (col - col_mid > 0)
			cat_bitmap(bitmap2_no, bitmap2, ++now, o_row, o_col+col_mid, row_mid, col-col_mid, bitmap1);

		//left-down
		if (row - row_mid > 0)
			cat_bitmap(bitmap2_no, bitmap2, ++now, o_row+row_mid, o_col, row-row_mid, col_mid, bitmap1);

		//right-down
		if ((row - row_mid > 0) && (col - col_mid > 0))
			cat_bitmap(bitmap2_no, bitmap2, ++now, o_row+row_mid, o_col+col_mid, row-row_mid, col-col_mid, bitmap1);
	}
}

int main()
{	
	int  row;
	int  col;
	char type;
	char line[100];
	char bitmap1[205][205];
	long bitmap2_no;
	char bitmap2[40010];
	char sep[]=" \n";
	char* token;
	int  i;
	int  j;

	//initial
	bitmap2_no = 0;

	//raed 	input
	cin.getline(line, 100);
	while (line[0] != '#')
	{
		if (strchr(line, ' '))
		{
			if (bitmap2_no > 0)
			{
				long now = 0;
				//previous inputed D-type's bitmap
				cat_bitmap(bitmap2_no, bitmap2, now, 0, 0, row, col, bitmap1);

				//output result
				printf("B%4d%4d\n", row, col);
				now = 0;
				for (i = 0; i < row; i++)
					for (j = 0; j < col; j++)
					{
						now++;
						printf("%c", bitmap1[i][j]);
						if (now == 50)
						{
							printf("\n");
							now = 0;
						}
					}
				if (now != 50)
					printf("\n");
			}
			bitmap2_no = 0;

			//start a new bitmap
			token = strtok(line, sep);
			type = *token;
			token = strtok(NULL, sep);
			row = atoi(token);
			token = strtok(NULL, sep);
			col = atoi(token);

			//check bitmap's type
			if (type == 'B')
			{
				//read input
				for (i = 0; i < row; i++)
					for (j = 0; j < col; j++)
					{
						while (true)
						{
							cin >> *token;
							if ((*token == '1') || (*token == '0'))
								break;
						}
						bitmap1[i][j] = *token;
					}
				cin.getline(line, 100);

				//divide Bitmap
				div_bitmap(bitmap1, 0, 0, row, col, bitmap2_no, bitmap2);

				//output result
				printf("D%4d%4d\n", row, col);
				int now_no = 0;
				for (i = 0; i < bitmap2_no; i++)
				{
					now_no++;
					printf("%c", bitmap2[i]);
					if (now_no == 50)
					{
						printf("\n");
						now_no = 0;
					}
				}
				if (now_no != 50)
					printf("\n");
				bitmap2_no = 0;
			}
		}
		else
		{
			//read input			
			for (i = 0; i < strlen(line); i++)
				bitmap2[bitmap2_no+i] = line[i];
			bitmap2_no = bitmap2_no + strlen(line);
		}

		cin.getline(line, 100);
	}

	//process last input
	if (bitmap2_no > 0)
	{
		long now = 0;
		//D-type's bitmap
		cat_bitmap(bitmap2_no, bitmap2, now, 0, 0, row, col, bitmap1);

		//output result
		printf("B%4d%4d\n", row, col);
		now = 0;
		for (i = 0; i < row; i++)
			for (j = 0; j < col; j++)
			{
				now++;
				printf("%c", bitmap1[i][j]);
				if (now == 50)
				{
					printf("\n");
					now = 0;
				}
			}
		if (now != 50)
			printf("\n");
	}

	return 0;
}