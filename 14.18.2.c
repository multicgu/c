#include<stdio.h>
#include<stdlib.h>
struct month {
	char monname[10];
	char monabbr[3];
	int days;
	int month;
};
static struct month months[12]={
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
struct date {
	int days;
	char months[15];
	int years;
};
int sumdays(int day,char month[],int year);
int main(void)
{
	int day,month,year,sum;
	char ch_mon[10];
	puts("Enter the date,program return sum days.");
	puts("Enter the months.(EX:12 or Dec or December)");
	scanf("%s",ch_mon);
	puts("Enter the days.(Ex:30 or 15 or 28)");
	scanf("%d",&day);
	puts("Enter the year.(EX:2015 or 2014 or 1995)");
	scanf("%d",&year);
	sum=sumdays(day,ch_mon,year);
	printf("The days is %d.\n",sum);

	return 0;
}
int sumdays(int day,char month[],int year)
{
	int n,i;
	int sum=0;
	for(n=0;n<12;n++)
	{
		if(strcmp(month,months[n].monname)==0 || strcmp(month,months[n].monabbr)==0)
			break;
		else if(atoi(month)==months[n].month)
			break;
	}
	if(n==12)
	{
		fprintf(stderr,"Enter error,please enter 1 ~ 12.\n");
		exit(1);
	}
	else
	{
		if(day<=months[n].days)
		{
			for(i=0;i<n;i++)
				sum+=months[i].days;
			sum+=day;
		}
	}
	return sum;
}
