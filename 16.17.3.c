#include<stdio.h>
#include<math.h>
#define RAD_TO_DEG (180/(4*atan(1))) //angle=radian*RAD_TO_DEG
typedef struct {
	double angle;
	double r;
}polar;
typedef struct {
	double x;
	double y;
}rect;
rect rect_polar(polar p);
int main(void)
{
	double angle,vector;
	polar p;
	rect r;
	puts("Please enter the angle and the vector length in polar.");
	puts("q to quit.");
	while(scanf("%lf%lf",&angle,&vector)==2&&(angle<90&&angle>0))
	{
		p.angle=angle;
		p.r=vector;
		r=rect_polar(p);
		printf("In rect x=%lf and y=%lf\n",r.x,r.y);
	}
	puts("Bye!");
	return 0;
}
rect rect_polar(polar p)
{
	rect r;
	printf("p.angle=%lf p.r=%lf\n",p.angle,p.r);
	r.x=p.r*cos(p.angle/RAD_TO_DEG);
	r.y=p.r*sin(p.angle/RAD_TO_DEG);
	return r;
}
