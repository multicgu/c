#include<stdio.h>
#include<math.h>
#include<stdlib.h>
void transform(double *source,double *target,int n,double change(double source));
double triple(double source);
double duplicate(double source);
int main(void)
{
	int i;
	double source[100];
	double target[100];
	for(i=0;i<100;i++)
	{
		source[i]=i+0.12345;
	}
	int n=100;
	transform(source,target,100,triple);
	transform(source,target,100,duplicate);
	transform(source,target,100,sin);
	transform(source,target,100,floor);
	return 0;
}
double triple(double source)
{
	return 3*source;
}
double duplicate(double source)
{
	return 2*source;
}
void transform(double *source,double *target,int n,double change(double source))
{
	int i;
	printf("source    target\n");
	for(i=0;i<n;i++)
	{
		target[i]=change(source[i]);
		printf("%lf    %lf\n",source[i],target[i]);
	}
	
}
