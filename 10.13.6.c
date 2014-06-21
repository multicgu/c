#include<stdio.h>
void copy_arr(double source[],double target1[],int n);
void copy_ptr(double * source,double * target2,int n);
int main(void)
{
	int a,b,a1,b1;
	double source[2][5]={{6.6,7.7,8.8,9.9,10.1},
	{1.1,2.2,3.3,4.4,5.5}
	};
	double target1[2][5];
	double target2[2][5];
	copy_arr(source[0],target1[0],5);
	copy_arr(source[1],target1[1],5);
	copy_ptr(source[0],target2[0],5);
	copy_ptr(source[1],target2[1],5);

	for(a1=0;a1<2;a1++)
		for(a=0;a<5;a++)
			printf("target1[%d][%d] = %.1lf\n",a1,a,target1[a1][a]);
	for(b1=0;b1<2;b1++)
		for(b=0;b<5;b++)
			printf("target2[%d][%d] = %.1lf\n",b1,b,target2[b1][b]);
	
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

