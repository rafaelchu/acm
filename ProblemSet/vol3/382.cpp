// 382 - Perfection

#include <iostream>
#include <iomanip>

using namespace std;

struct entry
{
	long number;
	int type;
};

void find_answer(struct entry& answer)
{
	long sum = 0;
	long i;

	for (i = 1; i < answer.number; i++)
		if ((answer.number % i) == 0)
		{
			sum = sum + i;
			if (sum > answer.number)
				break;
		}

	if (sum < answer.number)
		answer.type = -1;
	else if (sum == answer.number)
		answer.type = 0;
	else
		answer.type = 1;
}


int main ()
{
	struct entry answer[100];
	int answer_i = -1;	
	int i;

	//read input	
	for (cin >> answer[++answer_i].number; answer[answer_i].number; cin >> answer[++answer_i].number)
		find_answer(answer[answer_i]);	

	//output result
	cout << "PERFECTION OUTPUT" << endl;
	for (i = 0; i < answer_i; i++)
	{
		cout << setw(5) << answer[i].number;
		if (answer[i].type == 1)
			cout << " ABUNDANT" << endl;
		else if (answer[i].type == 0)
			cout << " PERFECT" << endl;
		else
			cout << " DEFICIENT" << endl;
	}
	cout << "END OF OUTPUT" << endl;
	
	return 0;
}