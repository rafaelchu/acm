// 180 - Eeny Meeny"

#include <iostream>

using namespace std;

// Calculate chief location.
void cal_loc(int chief_loc[][2], int no, int dir)
{
	bool used[510];
	int step;
	int count;
	int loc;
	int i;
    
	//initial
	for (i = 1; i <= no; i++)
		used[i] = false;
    
	// Find start location.
	step = 15 % no;
	if (step == 0)
		step = no;
	loc = 1;
	for (i = 0; i < step - 1; i++)
		if (dir == 0)
		{
			loc++;
			if (loc > no)
				loc = 1;
		}
		else
		{
			loc--;
			if (loc < 1)
				loc = no;
		}
	used[loc] = true;
	if (dir == 0)
	{
		loc++;
		if (loc > no)
			loc = 1;
	}
	else
	{
		loc--;
		if (loc < 1)
			loc = no;
	}
    
	// Moving stpes
	count = chief_loc[no-1][0] - 1;
    
	// Find location.
	i = 0;
	while (i < count)
	{
		if (!used[loc])
		{
			i++;
			used[loc] = true;
		}
        
		// Move next
		if (dir == 0)		//clockwise
		{
			loc++;
			if (loc > no)
				loc = 1;
		}
		else				//counter-clockwise.
		{
			loc--;
			if (loc < 1)
				loc = no;
		}
	}
	chief_loc[no][dir] = loc;
}

int main()
{
	int chief_loc[510][2];	// Eligible chief locatioin. 0 is clockwise, 1 is counter-clockwise.
	int safe_loc[510];
	int upper;              // Upper bound.
	int lower;              // Lower bound.
	int no;
	int i;
    
	//initial
	chief_loc[1][0] = 1;
	chief_loc[1][1] = 1;
	chief_loc[2][0] = 2;
	chief_loc[2][1] = 2;
	chief_loc[3][0] = 2;
	chief_loc[3][1] = 3;
    
	// Calculate chief location.
	for (i = 4; i <= 500; i++)
	{
		cal_loc(chief_loc, i, 0);
		cal_loc(chief_loc, i, 1);
	}
    
	//read input
	cin >> lower >> upper;
	if (lower > upper)
	{
		int temp = lower;
		lower = upper;
		upper = temp;
	}
	while ((lower != 0) && (upper != 0))
	{
		// Find un-safe locations
		for (i = 1; i <= lower; i++)
			safe_loc[i] = true;
		for (i = lower; i <= upper; i++)
		{
			safe_loc[chief_loc[i][0]] = false;
			safe_loc[chief_loc[i][1]] = false;
		}
        
		// Find safe location near first one.
		no = 1;
		int c = 2;
		int ac = lower;
		bool find = false;
		while (c <= lower / 2 + 1)
		{
			if (safe_loc[c])
			{
				find = true;
				break;
			}
			c++;
            
			if (safe_loc[ac])
			{
				find = true;
				break;
			}
			ac--;
            
			no++;
		}
		if (find)
			cout << no << endl;
		else
			cout << "Better estimate needed" << endl;
        
		//for (i = 2; i <= lower; i++)
		//	if (safe_loc[i])
		//		break;
		//if (i <= lower)
		//	cout << i - 1 << endl;
		//else
		//	cout << "Better estimate needed" << endl;
        
		//read input
		cin >> lower >> upper;
		if (lower > upper)
		{
			int temp = lower;
			lower = upper;
			upper = temp;
		}
	}
    
	return 0;
}