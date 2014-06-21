#include<stdio.h>
int fibonacci(int);
int main(void)
{
	int n;
	printf("Please input the number of the fibonacci:\n");
	while(scanf("%d",&n) == 1)
	{
		printf("%d's fibonacci is %d\n",n,fibonacci(n));
	}
	return 0;
}

int fibonacci(int n)
{
	int a=1;
	int	b=1;
	int	c=1;
	int i;
	if(n<=2)
		return 1;
	else
	{
		for(i=3;i<=n;i++)
		a=b;
		b=c;
		c=a+b;
	}
	return c;
}
