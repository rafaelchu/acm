// 155 - All Squares

#include <stdio.h>
#include <iostream>
#include <iomanip>

using namespace std;

void find_ans(int k, int s_x, int s_y, int t_x, int t_y, int& count)
{
	int tlx = s_x - k;		
	int tly = s_y - k;
	int brx = s_x + k;		
	int bry = s_y + k;

	if ((t_x >= tlx) && (t_x <= brx) && (t_y >= tly) && (t_y <= bry))
		count++;

	if (k > 1)
	{
		if ((t_x > s_x) && (t_y < s_y))
			find_ans(k / 2, brx, tly, t_x, t_y, count);		
		else if ((t_x < s_x) && (t_y < s_y))
			find_ans(k / 2, tlx, tly, t_x, t_y, count);		
		else if ((t_x < s_x) && (t_y > s_y))
			find_ans(k / 2, tlx, bry, t_x, t_y, count);		
		else if ((t_x > s_x) && (t_y > s_y))
			find_ans(k / 2, brx, bry, t_x, t_y, count);		
	}
}

int main()
{
	int k;
	int x;
	int y;
	int count;

	//read input
	cin >> k >> x >> y;
	while (k != 0)
	{
		count = 0;
		find_ans(k, 1024, 1024, x, y, count);
		cout << setw(3) << count << endl;

		cin >> k >> x >> y;
	}


	return 0;
}