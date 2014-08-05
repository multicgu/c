#include<stdio.h>
#include<stdlib.h>
int main(int argc,char * argv[])
{
	int i,count;
	if(argc<2 || (count=atoi(argv[1]))<1)
		printf("Usage: %s positive-number\n",argv[0]);
	else
		for(i=1;i<=count;i++)
			puts("Hello,good looking!");
	printf("%d\n",count);
	return 0;
}
