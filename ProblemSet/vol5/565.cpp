// 565 - Pizza Anyone?

#include <iostream>

using namespace std;

//check the ans is correct or not.
bool check_ans(int list_no, int list[][16], bool ans_list[])
{
	int i;
	int j;

	for (i = 0; i < list_no; i++)
	{
		int match_no = 0;

		for (j = 0; j < 16; j++)
			if ((list[i][j] == 1) && (ans_list[j]))
				match_no++;
			else if ((list[i][j] == -1) && (!ans_list[j]))
				match_no++;

		if (match_no < 1)		// Not correct.
			return false;
	}

	return true;
}

//find out the answer.
bool find_ans(int list_no, int list[][16], int now, bool ans_list[])
{
	bool ans; 

	if (now == -1)
	{
		ans = check_ans(list_no, list, ans_list);
		if (ans)
			return true;
		else
			return false;
	}
	else
	{
		ans_list[now] = false;
		ans = find_ans(list_no, list, now - 1, ans_list);
		if (ans)
			return true;
		ans_list[now] = true;
		ans = find_ans(list_no, list, now - 1, ans_list);
		return ans;		
	}
}

int main()
{
	bool ans_list[16];
	int  list_no;
	int  list[20][16];
	bool ans;
	char temp;
	int  i;
	int  j;
	
	//read input
	while (cin >> temp)
	{
		//initial
		for (i = 0; i < 20; i++)
			for (j = 0; j < 16; j++)
				list[i][j] = 0;
		list_no = 0;

		while (temp != '.')
		{
			if (temp == ';')
				list_no++;
			else if (temp == '+')
			{
				cin >> temp;	//letter
				list[list_no][temp-'A'] = 1;
			}
			else
			{
				cin >> temp;	//letter
				list[list_no][temp-'A'] = -1;
			}

			cin >> temp;	//sign character 
		}		

		//find out the answer
		ans = find_ans(list_no, list, 15, ans_list);

		//output result
		if (ans)
		{
			cout << "Toppings: ";
			for (i = 0; i < 16; i++)
				if (ans_list[i])
					cout << static_cast<char>('A' + i);
			cout << endl;
		}
		else
			cout << "No pizza can satisfy these requests." << endl;
	}


	return 0;
}