#include<stdio.h>
void value(double *,double *);
int main(void)
{
	double a,b,c,d;
	printf("enter 2 double number:\n");
	while(scanf("%lf%lf",&a,&b) != 2)
	{
		scanf("%*s");
		printf("you input is error,retry:\n");
	}
	printf("a = %lf,b = %lf\n",a,b);
	value(&a,&b);
	printf("x a = %lf, y b = %lf\n",a,b);
	c = 1/((a + b)/2);
	printf("%lf\n",c);
	return 0;
}

void value(double * x,double * y)
{
	* x = 1 / * x;
	* y = 1 / * y;
}
