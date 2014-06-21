#include<stdio.h>
double min(double,double);
int main(void)
{
	double x;
	double y;
	printf("please input 2 number:\n");
	while(scanf("%lf%lf",&x,&y) != 2)
	{
		scanf("%*s");
		printf("enter is error,please reinput:\n");
	}
	min(x,y);
	printf("%lf\n",min(x,y));
	return 0;
}

double min(double m,double n)
{
	if(m<n)
		return m;
	else
		return n;
}
