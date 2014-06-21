#include<stdio.h>
#define SIZE 4
int main(void)
{
	int i;
	int no_data[SIZE];
	printf("%2s%14s\n","i","no_data[i]");
	for(i=0;i<4;i++)
	{
		printf("%2d%14d\n",i+1,no_data[i]);
	}
	return 0;
}
