#include <iostream>
#include "iomanip.h"
struct cell
{
	long value;
	int  type;
};

void inline swap_cell(struct cell& a, struct cell& b)
{
	struct cell temp;

	temp = a;
	a = b;
	b = temp;
}

int main ()
{
	int index[3];
	long answer[1500];
	struct cell min[3];
	int count_i;

	//initial	
	index[0]  = 0;		//2's index
	index[1]  = 0;		//3's index
	index[2]  = 0;		//5's index
	answer[0] = 1;

	//calculate
	for (count_i = 1; count_i < 1500; count_i++)
	{
		//find value for 2,3,5
		min[0].type  = 0;
		min[0].value = answer[index[0]] * 2;
		min[1].type  = 1;
		min[1].value = answer[index[1]] * 3;		
		min[2].type  = 2;
		min[2].value = answer[index[2]] * 5;

		//Check the same value.
		if (min[1].value == min[0].value)		
			min[1].value = answer[++index[1]] * 3;
		if (min[2].value == min[0].value)		
			min[2].value = answer[++index[2]] * 5;
		if (min[2].value == min[1].value)		
			min[2].value = answer[++index[2]] * 5;		

		//bubblesort
		if (min[0].value > min[1].value)		
			swap_cell(min[0], min[1]);
		if (min[1].value > min[2].value)
			swap_cell(min[1], min[2]);
		if (min[0].value > min[1].value)
			swap_cell(min[0], min[1]);

		//find minimum value for this time
		answer[count_i] = min[0].value;
		index[min[0].type]++;
	}

	//output answer
	for (count_i = 0; count_i < 1500; count_i++)
		cout << setw(4) << count_i << " = " << answer[count_i] << endl;
    
    return 0;
}