// 536 - Tree Recovery
#include <iostream>
#include <string.h>

using namespace std;

void find_ans(char preorder[], char inorder[])
{
	char pre[30];
	char in[30];
	int i;	

	if (strlen(preorder) == 0)
	{
		return;
	}
	else
	{
		i = 0;
		while (preorder[0] != inorder[i])
		{
			i++;
		}		

		//Left subtree
		strncpy(pre, preorder + 1, i);
		pre[i] = 0;
		strncpy(in, inorder, i);
		in[i] = 0;

		find_ans(pre, in);

		//Right subtree
		int j = strlen(preorder) - i;
		
		strncpy(pre, preorder + i + 1, j);
		pre[j] = 0;
		strncpy(in, inorder + i + 1, j);
		in[j] = 0;

		find_ans(pre, in);

		//Output result
		cout << preorder[0];
	}	
}


int main()
{
	char preorder[30];
	char inorder[30];

	while (cin >> preorder >> inorder)
	{
		find_ans(preorder, inorder);
		cout << endl;
	}

	return 0;
}