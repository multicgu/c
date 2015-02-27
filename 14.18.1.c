#include<stdio.h>
#include<string.h>
#include<stdlib.h>
struct mouth {
	char mthname[15];
	char mthabbr[3];
	int days;
	int monum;
};
static struct mouth mouths[12]={
	{"January","Jan",31,1},
	{"February","Feb",28,2},
	{"March","Mar",31,3},
	{"April","Apr",30,4},
	{"May","May",31,5},
	{"June","Jun",30,6},
	{"July","Jul",31,7},
	{"August","Aug",31,8},
	{"September","Sep",30,9},
	{"October","Oct",31,10},
	{"November","Nov",30,11},
	{"December","Dec",31,12}
};
int allday(char * mouths);
int main(void)
{
	char mouth[10];
	puts("Enter the mouths.");
	gets(mouth);
	printf("sum day is %d.\n",allday(mouth));
	return 0;
}
int allday(char * mou)
{
	int n,i;
	int sum=0;
	for(n=0;n<12;n++)
		if(strcmp(mou,mouths[n].mthname)==0)
			break;
	if(n==12)
	{
		printf("Your enter is error.\n");
		exit(1);
	}
	for(i=0;i<=n;i++)
	{
		printf("days=%d.\n",mouths[i].days);
		sum+=mouths[i].days;
	}
	return sum;
}
