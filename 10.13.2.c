#include<stdio.h>
void copy_arr(double source[],double target1[],int n);
void copy_ptr(double * source,double * target2,int n);
int main(void)
{
	int a,b;
	double source[5]={1.1,2.2,3.3,4.4,5.5};
	double target1[5];
	double target2[5];
	copy_arr(source,target1,5);
	copy_ptr(source,target2,5);
	for(a=0;a<5;a++)
		printf("target1[a] = %.1lf\n",target1[a]);
	for(b=0;b<5;b++)
		printf("target2[b] = %.1lf\n",target2[b]);
	
	return 0;
}
void copy_arr(double source[],double target1[],int n)
{
	int i=0;
	for(i=0;i<n;i++)
		target1[i] = source[i];
}
void copy_ptr(double * source,double * target2,int n)
{
	int i;
	for(i=0;i<n;i++)
		*(target2++) = *(source++);
}

