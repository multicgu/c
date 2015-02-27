//partb.c
#include<stdio.h>
extern int count;
static int total=0;
void accumulate(int k);
void accumulate(int k)
{
	static int subtotal=0;
	printf("k=%d\n",k);	
	if(k==0)
	{
		printf("Loop cycle: %d\n",count);
		printf("subtotal=%d,total=%d\n",subtotal,total);
		subtotal=0;
	}
	else if(k>0)
	{
		total+=k;
		subtotal+=k;
	}
}
