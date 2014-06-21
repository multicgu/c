#include<stdio.h>
void to_base_n(int,int);
int main(void)
{
	int a,b;
	printf("Enter a number and the base you want to cal:\n");
	while(scanf("%d%d",&a,&b) == 2)
	{
		to_base_n(a,b);
		putchar('\n');
		printf("Please input another 2 number.\n");	
	}
	return 0;
}

void to_base_n(int a,int b)
{
	int x;
	x = a%b;
	if(a>=b)
	{
		to_base_n(a/b,b);
		printf("%d",x);
	}
	else
		printf("%d",x);
}
