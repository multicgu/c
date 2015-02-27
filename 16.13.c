// rect_pol.c  rect to polar
#include<stdio.h>
#include<math.h>
#define RAD_TO_DEG (180/(4*atan(1)))
typedef struct polar_v {
	double magnitude;
	double angle;
} POLAR_V;
typedef struct rect_v {
	double x;
	double y;
} RECT_V;
POLAR_V rect_to_polar(RECT_V rv);
int main(void)
{
	RECT_V input;
	POLAR_V output;
	printf("Enter 2 argv of the rect,x,y(enter q to quit): ");
	while(scanf("%lf%lf",&input.x,&input.y)==2)
	{
		output=rect_to_polar(input);
		printf("The magnitude is %.2f,angle is %.2f\n",output.magnitude,output.angle);
		printf("Enter 2 argv of the rect,x,y(ener q to quit): ");
	}
	return 0;
}
POLAR_V	rect_to_polar(RECT_V rv)
{
	POLAR_V pv;
	pv.magnitude=sqrt(rv.x*rv.x+rv.y*rv.y);
	if(pv.magnitude==0)
		pv.angle=0;
	else
		pv.angle=RAD_TO_DEG*atan2(rv.y,rv.x);
	return pv;
}
