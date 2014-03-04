// 584 - Bowling

#include <iostream>
#include <string.h>

using namespace std;

int main()
{
	int  all_score;
	int  score[100];
	char result[100];
	int  all_ball;
	int  frame;
	int  ball;
	char line[100];
	char sep[] = " \n";
	char* token;
	int i;

	//read input
	cin.getline(line, 100);
	while (strcmp(line, "Game Over") != 0)
	{
		//read input
		all_ball = 0;
		token = strtok(line, sep);
		while (token)
		{
			if (*token == 'X')
				score[all_ball] = 10;
			else if (*token == '/')
				score[all_ball] = 10 - score[all_ball-1];
			else
				score[all_ball] = *token - '0';
			result[all_ball] = *token;
			
			all_ball++;
			token = strtok(NULL, sep);
		}

		//calculate the total score
		all_score = 0;
		frame = 0;
		ball = 0;
		for (i = 0; i < all_ball; i++)
		{
			ball = (ball + 1)  % 2;

			if (result[i] == 'X')
			{
				ball = 0;
				frame++;
				if (i + 2 < all_ball)
					all_score = all_score + score[i+1] + score[i+2];
				all_score = all_score + score[i];				
			}
			else if (result[i] == '/')
			{
				frame++;
				if (i + 1 < all_ball)
					all_score = all_score + score[i+1];
				all_score = all_score + score[i];
			}
			else
			{
				if (ball == 0)
					frame++;
				all_score = all_score + score[i];
			}

			if (frame == 10)
				break;
		}

		//output result
		cout << all_score << endl;

		cin.getline(line, 100);
	}
    
    return 0;
}