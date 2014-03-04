// 152 - Tree's a Crowd

#include <iostream>
#include <stdio.h>
#include <math.h>

using namespace std;

const double INF = 20000000.0;
const int MAX = 5010;

struct point
{
	double x;
	double y;
	double z;
};

double find_dis(point a, point b)
{
	double t1 = a.x - b.x;
	double t2 = a.y - b.y;
	double t3 = a.z - b.z;

	return sqrt(t1* t1 + t2 * t2 + t3 * t3);
}

int main()
{	
	int    tree_no;
	point  tree[MAX];
	double min; 
	long   ans[10];
	int    in[10];
	int i;
	int j;

	//initial
	tree_no = 0;
	for (i = 0; i < 10; i++)
		ans[i] = 0;	

	//read input
	tree_no = 0;
	cin >> in[0] >> in[1] >> in[2];
	while (in[0] || in[1] || in[2])
	{		
		tree[tree_no].x = static_cast<double>(in[0]);
		tree[tree_no].y = static_cast<double>(in[1]);
		tree[tree_no].z = static_cast<double>(in[2]);
		tree_no++;

		cin >> in[0] >> in[1] >> in[2];
	}

	for (i = 0; i < tree_no ; i++)
	{
		min = INF;
		for (j = 0; j < tree_no; j++)
		{
			if (i != j)
			{
				double temp1 = find_dis(tree[i], tree[j]);
				if (temp1 < min)
					min = temp1;
			}
		}

		long temp2 = static_cast<long>(min);
		if ((temp2 >= 0) && (temp2 < 10))
			ans[temp2]++;
	}

	//output result
	for (i = 0; i < 10; i++)
		printf("%4ld", ans[i]);
	printf("\n");

	return 0;
}

