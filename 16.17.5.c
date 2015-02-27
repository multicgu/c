#include<stdio.h>
#include<time.h>
#include<stdlib.h>
void luckynum(int *ar,int n,int t);
int main(void)
{
	int ar[20];
	int t=0;
	for(t=0;t<20;t++)
		ar[t]=t+1;
	puts("The progrem will print random number in 1-20.");
	puts("How many numbers you want to show:(q to quit)");
	while(scanf("%d",&t)==1)
	{
		luckynum(ar,20,t);
		puts("How many numbers you want to show:(q to quit)");
	}

	return 0;
}
void luckynum(int *ar,int n,int t)
{
	srand((unsigned)time(NULL));
	int lucky[t];
	int num,i,m;
	for(i=0;i<t;i++)
	{
		lucky[i]=rand()%n+1;
		for(m=0;m<i;m++)
			while(lucky[i]==lucky[m])
			{
				lucky[i]=rand()%n+1;
				m=0;
			}
	}
	printf("%d numbers was selected:",t);
	for(num=0;num<t;num++)
		printf("%d ",lucky[num]);
	putchar('\n');
}
