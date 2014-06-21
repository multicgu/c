#include<stdio.h>
double pow(double,int);
int main(void)
{
	double n,x;
	int p;
	printf("please enter a number and the positive integer power");
	printf(" to which the number will be riased.enter q to quit.\n");
	while(scanf("%lf%d",&n,&p) == 2 )
	{
		x=pow(n,p);
		printf("%g to the power %d is %g\n",n,p,x);
		printf("Enter next pair of numbers or q to quit.\n");
	}
	return 0;
}

double pow(double n,int p)
{
	double pow = 1.0;
	int i;
	if(p>0)
	{
		for(i=1;i<=p;i++)
			pow *= n;
		return pow;
	}
	else if(p<0)
	{
		for(i=1;i<=-p;i++)
			pow *= n;
		pow = 1/pow;
		return pow;
	}
	else
	{
		return 1;
	}
}
