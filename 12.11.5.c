#include<stdio.h>
int rand(void);
unsigned long int seed;
void sort(unsigned long int *,int);
int main(void)
{
	int count=1;
	int i;
	unsigned long int arr[100];
	int n;
	printf("Enter a seed to create 10 numbers random and descending sort them.\n");
	scanf("%ld",&seed);
	for(count = 0;count<100;count++)
	{
		arr[count]=rand();
		printf("arr[%ld]=%d\n",count,arr[count]);
	}
	printf("After descending sort.\n");
	sort(arr,count);
	for(i=0;i<count;i++)
		printf("arr[%ld]=%d\n",i,arr[i]);
	return 0;
}
int rand(void)
{
	seed = seed * 1103515245 + 12345;
	return (unsigned long int) (((seed/65536) % 32768)%10+1);
}
void sort(unsigned long int * pti,int i)
{
	int a;
	int n,m;
	unsigned long int * arr;
	for(n=0;n<(i-1);n++)
		for(m=n+1;m<i;m++)
			if(pti[n]<pti[m])
			{
				*arr=pti[n];
				pti[n]=pti[m];
				pti[m]=*arr;
			}
}
