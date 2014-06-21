#include<stdio.h>
int main(void)
{
	const int daymonth[] = {31,28,31,30,31,30,31,30,31,30};
	int i;
	printf("%2s%14s\n","i","daymonth[i]");
	for(i=0;i< sizeof daymonth / sizeof daymonth[0];i++)
		printf("%2d%14d\n",i,daymonth[i]);
	printf("sizeof daymonth = %d,sizeof daymonth[0] = %d\n",sizeof daymonth,sizeof daymonth[0]);
	printf("%2d%14d\n",i,daymonth[8]);

	return 0;
}
