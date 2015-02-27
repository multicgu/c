#include<stdio.h>
void itobs(int n,int * bits);
void show(int * bits);
int main(void)
{
	int bits[sizeof(int)*8];
	int n;
	printf("Please enter the number.\n");
	while(scanf("%d",&n)==1)
	{
		itobs(n,bits);
		show(bits);
	}
	return 0;
}
void itobs(int n,int * bits)
{
	printf("%d\n",n);
	int i=0;
	int size=sizeof(int)*8;
	for(i=size-1;i>=0;i--,n>>=1)
	{
		bits[i]= (1&n);
		//printf("%d",bits[i]);
	}
}
void show(int * bits)
{
	int i=0;
	int size=sizeof(int)*8;
	for(i=0;i<size;i++)
	{
		printf("%d",bits[i]);
		if((i+1)%4==0)
			putchar(' ');
	}
}
