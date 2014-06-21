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
		x= pow(n,p);
		printf("pow() = %lf\n",pow(n,p));
		if(p>=0)
			printf("%lf power %d is %lf\n",n,p,x);
		else
			printf("%lf power %d is %lf\n",n,p,1/x);
		printf("Enter next pair of number or q to quit.\n");
	}
	return 0;
}

double pow(double n,int p)
{
	double x;
	if(p>0)
	{
		x = pow(n,p-1)*n;
		return x;
	}
	else if(p<0)
	{
		x = pow(n,p+1)*n;
		return x;
	}
	else
		return 1;
}
