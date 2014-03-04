// 615 - Is It A Tree?

#include <iostream>
#include <string.h>

using namespace std;

struct node_type
{
	long no;
	node_type* next;
};

bool travel(long node_no, node_type node[], bool walk[], long root)
{
	long i;

	if (walk[root])
		return false;		//no unique path
	walk[root] = true;

	for (i = 0; i < node_no; i++)
		if (node[i].next)
			if (node[i].next->no == node[root].no)
			{
				if (!travel(node_no, node, walk, i))
					return false;
			}

	return true;
}

int main()

{
	long case_no;
	long s_edge;
	long e_edge;
	long node_no;
	node_type node[5000];
	long root;
	bool walk[5000];
	bool ans;
	long i;

	case_no = 0;

	//read input
	cin >> s_edge >> e_edge;
	while ((s_edge >= 0) && (e_edge >= 0))
	{
		//initial
		case_no++;
		node_no = 0;
		ans = true;

		//read input and check property 2
		while ((s_edge > 0) && (e_edge > 0))
		{
			for (i = 0; i < node_no; i++)
				if (node[i].no == s_edge)
					break;
			if (i >= node_no)
			{
				//create a new node.
				node[i].no = s_edge;
				node[i].next = NULL;
				node_no++;
			}

			for (i = 0; i < node_no; i++)
				if (node[i].no == e_edge)
					break;
			if (i < node_no)
			{
				if (node[i].next)	//two nodes connect to the same node.
					ans = false;

				node[i].next = new node_type;
				node[i].next->no = s_edge;
				node[i].next->next = NULL;
			}
			else
			{
				//create a new node.
				node[i].no = e_edge;
				node[i].next = new node_type;
				node[i].next->no = s_edge;
				node[i].next->next = NULL;
				node_no++;	
			}
		
			cin >> s_edge >> e_edge;
		}

		//check property 1
		if (ans && (node_no > 0))
		{
			//find the root node
			for (i = 0; i < node_no; i++)
				if (!node[i].next)
					break;
			if (i < node_no)
			{
				root = i;
				for (i++; i < node_no; i++)
					if (!node[i].next)
						break;
				if (i < node_no)
					ans = false;	//has two non-connected nodes.
			}
			else 
				ans = false;		//all nodes are connected.
		}

		//check property 3
		if (ans && (node_no > 0))
		{
			for (i = 0; i < node_no; i++)
				walk[i] = false;
			ans = travel(node_no, node, walk, root);
			if (ans)
			{
				for (i = 0; i < node_no; i++)
					if (!walk[i])
					{
						ans = false;		//not all nodes are walked.
						break;
					}
			}
		}

		//output result
		if (ans)
			cout << "Case " << case_no << " is a tree." << endl;
		else
			cout << "Case " << case_no << " is not a tree." << endl;

		cin >> s_edge >> e_edge;
	}

	return 0;
}