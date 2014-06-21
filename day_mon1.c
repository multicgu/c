#include<stdio.h>
#define MONTHS 12
int main(void)
{
	int n;
	int month[MONTHS]={31,28,31,30,31,30,31,30,31,30,31,30};
	for(n=0;n<12;n++)
	{
		printf("%d month have %ddays.\n",n+1,month[n]);
	}
	return 0;
}
