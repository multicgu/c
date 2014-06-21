#include<stdio.h>
void larger_of(double *,double *);
int main(void)
{
	double x,y;
	printf("enter 2 double numbers:\n");
	while(scanf("%lf%lf",&x,&y) != 2)
	{
		scanf("%*s");
		printf("Please input 2 double number:\n");
	}
	printf("x = %lf,y = %lf\n",x,y);
	larger_of(&x,&y);
	printf("Now x = %lf,y = %lf\n",x,y);
	printf("the bigger is %lf.\n",x);

	return 0;
}

void larger_of(double * x,double * y)
{
	if(*x > *y)
		*y = *x;
	else
		*x = *y;
}
