// 112 - Tree Summing
// Time limit: 3.000 seconds 

#include <iostream>
#include <stdlib.h>

using namespace std;

struct tree_type
{
	long value;
	tree_type* left;
	tree_type* right;
};

//把LISP的語法建立成Binary tree
void parser_tree(tree_type*& root, bool& read_more)
{
	int  digit_no;
	char digit[100];
	long ten;
	char temp;

	if (!read_more)
		cin >> temp;
	cin >> temp;
	if (temp != ')')
	{
		//initial
		digit_no = 0;
		ten = 10;

		//讀入node的value		
		while (temp != '(')
		{
			digit[digit_no] = temp;
			digit_no++;
			cin >> temp;
			read_more = true;
		}
		digit[digit_no] = 0;

		//轉換value
		root = new tree_type;
		root->value = atol(digit);
		
		//建立兩邊的child tree
		root->left = NULL;
		root->right = NULL;
		parser_tree(root->left, read_more);
		parser_tree(root->right, read_more);

		//把最右邊的)讀走
		cin >> temp;
	}
	else
		read_more = false;
}

//找出來答案
void find_ans(tree_type* root, long rest, bool& ans)
{
	if ((!root->left) && (!root->right))	//走到了leaf
	{
		if (rest - root->value == 0)
			ans = true;
	}
	else									//往下繼續找答案
	{
		rest = rest - root->value;
		if (root->left)
			find_ans(root->left, rest, ans);
		if (root->right && !ans) 
			find_ans(root->right, rest, ans);
	}
}

int main()
{
	long target;
	tree_type* root;
	bool read_more;
	bool ans;

	//read input
	while (cin >> target)
	{
		//initial
		root = NULL;
		read_more = false;
		ans = false;

		//paeser tree
		parser_tree(root, read_more);

		//find ans
		if (root)
			find_ans(root, target, ans);

		//output result
		if (ans)
			cout << "yes" << endl;
		else
			cout << "no" << endl;
	}


	return 0;
}