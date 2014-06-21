#include<stdio.h>
int lesser(int,int);
int main(void)
{
	int a,b;
	printf("Enter two number,I will choice lesser one.\n");
	while((scanf("%d%d",&a,&b))==2)
	{
		printf("The lesser between %d and %d is %d.\n",a,b,lesser(a,b));
		printf("Enter another 2 numbers(q to quit)\n");
	}
	return 0;
}

int lesser(int m,int n)
{
	return (m<n)?m:n;
}
