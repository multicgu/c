#include<stdio.h>
int fibonacci(int);
int main(void)
{
	int n;
	printf("Please enter a number,the progrem will cal the fibonacci.\n");
	while(scanf("%d",&n)==1)
	{
		printf("the number is %d\n",fibonacci(n));
	}
	return 0;
}

int fibonacci(int n)
{
	if(n<=2)
		return 1;
	else 
		return fibonacci(n-1) + fibonacci(n-2);
}
