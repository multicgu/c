#include<stdio.h>
#define SIZE 4
int main(void)
{
	short dates [SIZE];
	short * pti;
	double bills [SIZE];
	double * ptf;
	int n;

	pti = dates;
	ptf = bills;
	printf("%23s %10s\n","short","double");
	for(n=0;n<SIZE;n++)
	{
		printf("point + %d,%p %p\n",n,pti+n,ptf+n);
	}

	return 0;
}
