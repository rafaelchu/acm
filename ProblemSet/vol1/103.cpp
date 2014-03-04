// 103 - Stacking Boxes
// Time limit: 3.000 seconds

#include <iostream>
using namespace std;

void find_ans(int k, int n, int box[][15], bool used[], int seq_no, int seq[], int& ans_no, int ans[])
{
	int i;
	int j;

	for (i = 0; i < k; i++)
		if (!used[i])
		{
			// Check nesting.
			if (seq_no >= 1)
			{
				for (j = 0; j < n; j++)
					if (box[i][j] <= box[seq[seq_no-1]][j])
						break;
			}
			else
				j = n;

			if (j >= n)
			{
				if (seq_no + 1 > ans_no)
				{
					// Get a new answer.
					for (j = 0; j < seq_no; j++)
						ans[j] = seq[j];
					ans[j] = i;
					ans_no = seq_no + 1;
				}

				// Keep finding next boxes.
				used[i] = true;
				seq[seq_no] = i;
				find_ans(k, n, box, used, seq_no + 1, seq, ans_no, ans);
				used[i] = false;
			}
		}
}

int main()
{
	int k;
	int n;
	int box[40][15];
	int seq[40];
	int ans_no;
	int ans[40];
	bool used[40];
	int i;
	int j1;
	int j2;

	// Read input.
	while (cin >> k)
	{
		cin >> n;
		for (i = 0; i < k; i++)
			for (j1 = 0; j1 < n; j1++)
				cin >> box[i][j1];

		// Sort boxwes
		for (i = 0; i < k; i++)
		{
			for (j1 = 0; j1 < n - 1; j1++)
			{
				int min = j1;
				for (j2 = j1 + 1; j2 < n; j2++)
					if (box[i][j2] < box[i][min])
						min = j2;

				int temp = box[i][j1];
				box[i][j1] = box[i][min];
				box[i][min] = temp;
			}
		}

		// Find the answer.
		ans_no = 0;
		for (i = 0; i < k; i++)
			used[i] = false;
		find_ans(k, n, box, used, 0, seq, ans_no, ans);

		//output result
		cout << ans_no << endl;
		for (i = 0; i < ans_no - 1; i++)
			cout << ans[i] + 1 << " ";
		cout << ans[i] + 1 << endl;
	}

	return 0;
}