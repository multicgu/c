#include<stdio.h>
#define SIZE 10
int sum(int [],int);
int main(void)
{
	int a;
	int b[]={1,2,3,4};
	printf("%zd\n",sizeof (int));
	int marbles[SIZE]={20,10,5,39,4,16,19,26,31,20};
	int answer;
	answer=sum(marbles,SIZE);
	printf("The sum of the marbles is %d,and the size of the marbles is %d\n",answer,sizeof marbles);
	printf("a size is %zd, b size is %zd\n",sizeof a,sizeof b);
	return 0;
}
int sum(int ar[],int n)
//int sum(int * ar,int n)
{
	int i;
	int total=0;
	for(i=0;i<n;i++)
	{
		printf("ar[%d] = %d,size of %zd\n",i,ar[i],sizeof ar);
		total += ar[i];
	}
	printf("The size of the ar is %zd\n",sizeof ar);
	return total;
}
