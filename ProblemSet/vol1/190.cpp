// 190 - Circle Through Three Points

#include<stdio.h>
#include<math.h>

struct point{
        double x;
        double y;
        }point,cutpoint,nullpoint,linepoint;

struct circle{
        struct point one;
        struct point two;
        struct point three;
        }C;

struct point intersect(struct circle cir);


int main(void)
{
	double radius,g,f,k,cx,cy;
	char sign1[3],sign2[3];

	while(scanf("%lf %lf %lf %lf %lf %lf",
	&C.one.x,&C.one.y,&C.two.x,
	&C.two.y,&C.three.x,&C.three.y)==6)
	{

		cutpoint =intersect(C);
		radius = sqrt(pow((cutpoint.x-C.one.x),2)+pow((cutpoint.y-C.one.y),2));

		g = -2*(cutpoint.x);
		f = -2*(cutpoint.y);
		k = g*g/4+f*f/4-radius*radius;

		if(cutpoint.x<0)
			sign1[0] = '+';
		else
			sign1[0] = '-';
		if(cutpoint.y<0)
			sign1[1] = '+';
		else
			sign1[1] = '-';
		if(g<0)
			sign2[0] = '-';
		else
			sign2[0] = '+';
		if(f<0)
			sign2[1] = '-';
		else
			sign2[1] = '+';
		if(k<0)
			sign2[2] = '-';
		else
			sign2[2] = '+';
	
		cx = fabs(cutpoint.x);
		cy = fabs(cutpoint.y);
		g = fabs(g);
		f = fabs(f);
		k = fabs(k);

		printf("(x %c %.3lf)^2 + (y %c %.3lf)^2 = %.3lf^2\n", sign1[0] ,cx,sign1[1],cy,radius);
		printf("x^2 + y^2 %c %.3lfx %c ", sign2[0] ,g,sign2[1]);
		printf("%.3lfy %c %.3lf = 0\n\n",f,sign2[2],k);
	}
    
    return 0;
}

struct point intersect(struct circle cir)
{
	double m[3],c[3],a[3],b[3];

	if(cir.one.y == cir.two.y)
	{
		c[1] = -1*((cir.one.x+cir.two.x)/2);
		a[1] = 1;
		b[1] = 0;
	}
	else if(cir.one.x == cir.two.x) 
	{
		c[1] = -1*((cir.one.y+cir.two.y)/2);
		a[1] = 0;
		b[1] = 1;
	}
	else{
		m[1] = (cir.one.y - cir.two.y)/(cir.one.x - cir.two.x);
		a[1] = 1/m[1];
		b[1] = 1;
		c[1] = -1*((cir.one.y+cir.two.y)/2+(cir.one.x+cir.two.x)/(2*m[1]));
	}

	if(cir.one.y == cir.three.y)
	{
		c[2] = -1*((cir.one.x+cir.three.x)/2);
		a[2] = 1;
		b[2] = 0;
	}
	else if(cir.one.x == cir.three.x)
	{
		c[2] = -1*((cir.one.y+cir.three.y)/2);
		a[2] = 0;
		b[2] = 1;
	}
	else
	{
		m[2] = (cir.one.y - cir.three.y)/(cir.one.x - cir.three.x);
		a[2] = 1/m[2];
		b[2] = 1;
		c[2] = -1*((cir.one.y+cir.three.y)/2+(cir.one.x+cir.three.x)/(2*m[2]));
	}

	point.x = (b[1]*c[2] - b[2]*c[1]) / (a[1]*b[2] - a[2]*b[1]);
	point.y = (a[2]*c[1] - a[1]*c[2]) / (a[1]*b[2] - a[2]*b[1]);

	return point;
}
