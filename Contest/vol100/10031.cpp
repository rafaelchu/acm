// @JUDGE_ID: 5084AA 10031 C++
// Problem: Saskatchewan
#include <iostream.h>

struct point_type
{
	long long int x;
	long long int y;
};

//找出來a和b的最大公因數
long long int find_gcd(long long int a, long long int b)
{
	if (a % b == 0)
		return b;
	else
		return find_gcd(b, a%b);
}

//求多邊形面積(沒有除以2!!)
long long int find_area(long long int n, point_type point[])
{
	long long int area;
	long long int i;

	//計算面積
	area = 0;
	point[n] = point[0];
	for (i = 1; i <= n; i++)
		area = area + (point[i-1].x * point[i].y - point[i].x * point[i-1].y);
//	area = area / 2;
	if (area < 0)
		area = -1 * area;

	return area;
}

//找出來多邊形內有幾個整數點
long long int find_interpoints(long long int n, point_type point[])
{
	long long int area;		//多邊形面積
	long long int border;	//多邊形邊上的點
	long long int difx;		//x的差值
	long long int dify;		//y的差值
	long long int i;

	//求出來多邊形面積的兩倍
	area = find_area(n, point);

	//initial
	border = 0;

	//找出來邊界上的點數
	point[n] = point[0];
	for (i = 0; i < n; i++)
	{
		difx = point[i].x - point[i+1].x;
		if (difx < 0)
			difx = -1 * difx;
		dify = point[i].y - point[i+1].y;
		if (dify < 0)
			dify = -1 * dify;
		
		if ((difx > 0) && (dify > 0))	//斜線
		{
			if (difx >= dify)
				border = border + find_gcd(difx, dify);
			else
				border = border + find_gcd(dify, difx);
		}
		else if (difx > 0)				//橫線
			border = border + difx;
		else if (dify > 0)				//直線
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