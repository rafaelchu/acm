// @JUDGE_ID: 5084AA 10031 C++
// Problem: Saskatchewan
#include <iostream.h>

struct point_type
{
	long long int x;
	long long int y;
};

//��X��a�Mb���̤j���]��
long long int find_gcd(long long int a, long long int b)
{
	if (a % b == 0)
		return b;
	else
		return find_gcd(b, a%b);
}

//�D�h��έ��n(�S�����H2!!)
long long int find_area(long long int n, point_type point[])
{
	long long int area;
	long long int i;

	//�p�⭱�n
	area = 0;
	point[n] = point[0];
	for (i = 1; i <= n; i++)
		area = area + (point[i-1].x * point[i].y - point[i].x * point[i-1].y);
//	area = area / 2;
	if (area < 0)
		area = -1 * area;

	return area;
}

//��X�Ӧh��Τ����X�Ӿ���I
long long int find_interpoints(long long int n, point_type point[])
{
	long long int area;		//�h��έ��n
	long long int border;	//�h�����W���I
	long long int difx;		//x���t��
	long long int dify;		//y���t��
	long long int i;

	//�D�X�Ӧh��έ��n���⭿
	area = find_area(n, point);

	//initial
	border = 0;

	//��X����ɤW���I��
	point[n] = point[0];
	for (i = 0; i < n; i++)
	{
		difx = point[i].x - point[i+1].x;
		if (difx < 0)
			difx = -1 * difx;
		dify = point[i].y - point[i+1].y;
		if (dify < 0)
			dify = -1 * dify;
		
		if ((difx > 0) && (dify > 0))	//�׽u
		{
			if (difx >= dify)
				border = border + find_gcd(difx, dify);
			else
				border = border + find_gcd(dify, difx);
		}
		else if (difx > 0)				//��u
			border = border + difx;
		else if (dify > 0)				//���u
			border = border + dify;
	}

	if (border == 0)
		return 0;
	else
		return (area - border) / 2 + 1;
}

int main()
{
	long long int n;
	point_type point[110];
	long long int inter_point;

	//read input
	n = 0;
	while (cin >> point[n].x >> point[n].y)
		n++;

	//find answer
	inter_point = find_interpoints(n, point);

	//output result
	cout << inter_point << endl;

	return 0;
}