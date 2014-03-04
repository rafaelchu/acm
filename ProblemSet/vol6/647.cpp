// 647 - Chutes and Ladders

#include <iostream>
#include <cstdlib>

using namespace std;

struct ladder_type
{
	int from;
	int to;
};

struct player_type
{
	int  position;
	bool lost_turn;
};


int main()
{
	int dies[1010];
	int dies_no;
	player_type player[6];
	int player_no;
	ladder_type ladder[200];
	int ladder_no;
	int special_sqr[110];
	int special_sqr_no;
	int time;					//how many times in the game
	int turn;					//whose turn in the game
	int ci;
	int ck;

	//read input (dies)
	dies_no = 0;
	cin >> dies[dies_no];
	while (dies[dies_no] != 0)
	{
		dies_no++;
		cin >> dies[dies_no];
	}	

    //read input (player number)
	for (cin >> player_no; player_no > 0; cin >> player_no)
	{
		//read input (ladder)
		ladder_no = 0;							
		cin >> ladder[ladder_no].from >> ladder[ladder_no].to;
		while ((ladder[ladder_no].from != 0) && (ladder[ladder_no].to != 0))
		{
			ladder_no++;
			cin >> ladder[ladder_no].from >> ladder[ladder_no].to;
		}
		
		//read input (special square)
		special_sqr_no = 0;
		cin >> special_sqr[special_sqr_no];
		while (special_sqr[special_sqr_no] != 0)
		{
			special_sqr_no++;
			cin >> special_sqr[special_sqr_no];
		}

		//start to play game	
		for (ci = 0; ci < player_no; ci++)
		{
			player[ci].position = 0;
			player[ci].lost_turn = false;
		}

		for (time = 0; time < dies_no; time++)
		{
			turn = time % player_no;        // decide whose turn

			if (!player[turn].lost_turn)			
			{
				if (player[turn].position + dies[time] == 100)
                {
                    //reach the end
					break;
                }                 
				else if (player[turn].position + dies[time] < 100)
				{
                    //check reach the end or not
					player[turn].position = player[turn].position + dies[time];

					//go to ladder
					for (ci = 0; ci < ladder_no; ci++)
						if (player[turn].position == ladder[ci].from)
						{
							player[turn].position = ladder[ci].to;
							break;
						}

					//go to special square
					if (ci >= ladder_no)
					{
						for (ci = 0; ci < special_sqr_no; ci++)
							if (player[turn].position == abs(special_sqr[ci]))
							{
								if (special_sqr[ci] >= 0)		//extra-turn
								{
									for (ck = 0; ck < player_no; ck++)
										if (ck != turn)			//make other player paused
											player[ck].lost_turn = true;
								}
								else							//lose-a-turn
									player[turn].lost_turn = true;
								
								break;
							}
					}
				}
			}
			else
            {
                //pasue one time, player can move in next turn
				player[turn].lost_turn = false;
            }
		}

		//output result
		cout << turn + 1 << endl;
	}

	return 0;
}