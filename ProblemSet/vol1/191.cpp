// 191 - Intersection

#include <iostream>

using namespace std;

struct point_type
{
	long x;
	long y;
};

void find_value(long x1, long x2, long& px1, long& px2)
{
	if (x1 <= x2)
	{
		px1 = x1;
		px2 = x2;
	}
	else
	{
		px1 = x2;
		px2 = x1;
	}
}

//use quick rejection
bool q_reject(point_type line1[], point_type line2[])
{
	point_type p1;
	point_type p2;
	point_type p3;
	point_type p4;

	//find line1's bounding box
	find_value(line1[0].x, line1[1].x, p1.x, p2.x);
	find_value(line1[0].y, line1[1].y, p1.y, p2.y);

	//find line2's bounding box
	find_value(line2[0].x, line2[1].x, p3.x, p4.x);
	find_value(line2[0].y, line2[1].y, p3.y, p4.y);

	//check intersection
	if ((p2.x >= p3.x) && (p4.x >= p1.x) && (p2.y >= p3.y) && (p4.y >= p1.y))
		return true;
	else
		return false;
}

//calculate cross product(p0p1 X p0p2)
long find_cross(point_type p0, point_type p1, point_type p2)
{
	return (p1.x - p0.x) * (p2.y - p0.y) - (p2.x - p0.x) * (p1.y - p0.y);
}

//check intersection
bool intersect(point_type line1[], point_type line2[])
{
	bool ans;
	long cross1;
	long cross2;

	//Use--Quick rejection
	ans = q_reject(line1, line2);

	//Use--Straddle
	if (ans)
	{		
		cross1 = find_cross(line1[0], line2[0], line1[1]);
		cross2 = find_cross(line1[0], line2[1], line1[1]);

		if (cross1 * cross2 <= 0)
		{
			cross1 = find_cross(line2[0], line1[0], line2[1]);
			cross2 = find_cross(line2[0], line1[1], line2[1]);

			if (cross1 * cross2 <= 0)
				ans = true;
			else
				ans = false;
		}
		else
			ans = false;
	}

	return ans;
}


int main()
{	
	long n;
	point_type line[2];			//line 
	long xleft, ytop, xright, ybottom;
	point_type rec[4][2];		//rectangle
	bool ans;
	long i;
	long j;
	
	//read input
	cin >> n;
	for (i = 0; i < n; i++)
	{
		cin >> line[0].x >> line[0].y >> line[1].x >> line[1].y;
		cin >> xleft >> ytop >> xright >> ybottom;

		if (xleft > xright)
		{
			long temp = xleft;
			xleft = xright;
			xright = temp;
		}
		if (ybottom > ytop)
		{
			long temp = ybottom;
			ybottom = ytop;
			ytop = temp;
		}	

		//left
		rec[0][0].x = xleft;
		rec[0][0].y	= ybottom;
		rec[0][1].x = xleft;		
		rec[0][1].y	= ytop;
		//up
		rec[1][0].x = xleft;
		rec[1][0].y	= ytop;
		rec[1][1].x = xright;		
		rec[1][1].y	= ytop;
		//right
		rec[2][0].x = xright;
		rec[2][0].y	= ytop;
		rec[2][1].x = xright;		
		rec[2][1].y	= ybottom;
		//down
		rec[3][0].x = xright;
		rec[3][0].y	= ybottom;
		rec[3][1].x = xleft;		
		rec[3][1].y	= ybottom;

		//check lien and rectangle
		ans = false;
		for (j = 0; j < 4 ; j++)
		{
			ans = intersect(line, rec[j]);
			if (ans)
				break;
		}

		rec[0][0].x = xleft;
		rec[0][0].y = ybottom;
		rec[0][1].x = xright;
		rec[0][1].y = ytop;

		//print output
		if (ans)
			cout << 'T' << endl;
		else
		{
			point_type p1;
			point_type p2;

			//find bounding box
			find_value(line[0].x, line[1].x, p1.x, p2.x);
			find_value(line[0].y, line[1].y, p1.y, p2.y);

			//print output
			if ((p1.x >= xleft) && (p2.x <= xright) && (p1.y >= ybottom) && (p2.y <= ytop))
				cout << 'T' << endl;
			else
				cout << 'F' << endl;
		}
	}

	return 0;
}

