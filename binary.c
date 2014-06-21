#include<stdio.h>
void binary(int n);
int main(void)
{
	int n;
	int h;
	printf("Please enter a number,the progerm will print the binary.\n");
	while(scanf("%d",&n) == 1)
	{
		h = n%2;
		binary(n);
		printf("%d\n",h);
	}
	printf("Bye!\n");
	return 0;
}

void binary(int n)
{
	int bin=n/2;
	int h;
	if(bin>=2)
	{
		h = bin % 2;
		binary(bin);
	}
	else
		h = bin;
	printf("%d",h);
}
