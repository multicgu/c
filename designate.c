#include<stdio.h>
#define MONTHS 12
int main(void)
{
	int i;
	int month[MONTHS]={31,28,[4]=31,30,31,[1]=29};
	printf("%2s%14s\n","i","month[i]");
	for(i=0;i<MONTHS;i++)
		printf("%2d%14d\n",i,month[i]);

	return 0;
}
