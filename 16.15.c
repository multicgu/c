//qsorter.c  use qsort() to sort.
#include<stdio.h>
#include<stdlib.h>
#define NUM 40
void fill(double ar[],int n);
void show(double ar[],int n);
int mycomp(const void * a1,const void * a2);
int main(void)
{
	double ar[NUM];
	printf("Fill in the array.\n");
	fill(ar,NUM);
	show(ar,NUM);
	qsort(ar,NUM,sizeof(ar[0]),mycomp);
	printf("After sort:\n");
	show(ar,NUM);
	return 0;
}
void fill(double ar[],int n)
{
	int i=0;
	for(i=0;i<n;i++)
		ar[i]=(double)rand()/((double)rand()+0.1);
}
void show(double ar[],int n)
{
	printf("Show the randow float number.\n");
	int i;
	for(i=0;i<n;i++)
	{
		printf("%.4lf ",ar[i]);
		if(i%6==5)
			putchar('\n');
	}
	if(i%6!=0)
		putchar('\n');
}
int mycomp(const void * p1,const void * p2)
{
	double * a1=(double*)p1;
	double * a2=(double *)p2;
	if(*a1>*a2)
		return 1;
	else if(*a1==*a2)
		return 0;
	else 
		return -1;
}
