// 110 - Meta-Loopless Sorts
// Time limit: 3.000 seconds 

#include <iostream>
using namespace std;

void print_loop(int n, char result[], int now)
{
	char new_result[10];
	char temp;
	int  i;
	int  j;

	if (now == n)					//已經走到底了
	{
		//print space
		for (i = 0; i < n; i++)
			cout << "  ";

		//print writeln
		cout << "writeln(";
		cout << result[0];
		for (i = 1; i < n; i++)
			cout << "," << result[i];
		cout << ")" << endl;
	}
	else
	{
		//initial
		for (i = 0; i < now; i++)
			new_result[i] = result[i];
		new_result[i] = static_cast<char>('a' + now);

		//print space
		for (i = 0; i < now; i++)
			cout << "  ";

		//print if
		cout << "if " << new_result[now-1] << " < " << new_result[now] << " then" << endl;
		print_loop(n, new_result, now + 1);

		for (i = now - 1; i >= 1; i--)
		{
			//print space
			for (j = 0; j < now; j++)
				cout << "  ";

			//print else if
			temp = new_result[i + 1];
			new_result[i + 1] = new_result[i];
			new_result[i] = temp;
			cout << "else if " << new_result[i-1] << " < " << new_result[i] << " then" << endl;
			print_loop(n, new_result, now + 1);
		}

		//print space
		for (j = 0; j < now; j++)
			cout << "  ";

		//print else
		temp = new_result[i + 1];
		new_result[i + 1] = new_result[i];
		new_result[i] = temp;
		cout << "else" << endl;
		print_loop(n, new_result, now + 1);
	}
}

int submain()
{
	int n;
	char result[10];
	int i;

	//read input
	cin >> n;

	//initial
	result[0] = 'a';

	//output result
	cout << "program sort(input,output);" << endl;
	cout << "var" << endl;
	cout << "a";
	for (i = 1; i < n; i++)
		cout << "," <<  static_cast<char>('a' + i);
	cout << " : integer;" << endl;
	cout << "begin" << endl;
	cout << "  readln(a";
	for (i = 1; i < n; i++)
		cout << "," <<  static_cast<char>('a' + i);
	cout << ");" << endl;
	
	//找出來如何輸出loop
	print_loop(n, result, 1);

	//最後的end
	cout << "end." << endl;	

	return 0;
}

int main()
{
	long n;
	long i;

	cin >> n;
	for (i = 0; i < n - 1; i++)
	{
		submain();
		cout << endl;
	}
	submain();

	return 0;
}