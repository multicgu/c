#include<stdio.h>
int * itobs(int n,int * bits);
void show(int * bits);
int invert(int n,int i);
int main(void)
{
	int n;
	int size=sizeof(int)*8;
	int bits[size];
	puts("Enter integers and see them in binary.");
	puts("Non-numeric input terminates program.");
	while(scanf("%d",&n)==1)
	{
		itobs(n,bits);
		show(bits);
		puts("Inverting the last 4 bits gives.");
		n=invert(n,4);
		itobs(n,bits);
		show(bits);
	}
	return 0;
}
int * itobs(int n,int * bits)
{
	int size=8*sizeof(int);
	int i;
	for(i=size-1;i>=0;i--,n>>=1)
		bits[i]=(1&n);
	return bits;
}
void show(int * bits)
{
	int i,size=8*sizeof(int);
	for(i=0;i<size;i++)
	{
		printf("%d",bits[i]);
		if((i+1)%4==0)
			putchar(' ');
	}
	putchar('\n');
}
int invert(int n,int i)
{
	int mask=0;
	int bit=1;
	for(;i>0;i--,bit<<=1)
	{
		mask |= bit;
	}
	return n^mask;
}
