#include<stdio.h>
#define SIZE 4
int main(void)
{
	int somedata[SIZE] = {1492,1006};
	int i;
	printf("%2c%14s\n",'i',"somedata[i]");
	for(i=0;i<4;i++)
	{
		printf("%2d%14d\n",i,somedata[i]);
	}
	return 0;
}
