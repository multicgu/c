#include<stdio.h>
int remaxind(double *,int);
int main(void)
{
	double arr[]={1.1,5.5,2.2,3.3,8.8,6.6,7.7};
	int a,n;
	for(n=0;n<(sizeof arr/sizeof arr[0]);n++);
	printf("n= %d\n",n);
	a = remaxind(arr,n);
	printf("a = %d\n",a);	
	return 0;
}
int remaxind(double * arr,int n)
{
	int m,i;
	double a;
	for(i=1,a=arr[0],m=0;i<n;i++)
	{
		if(a<=arr[i])
		{
			a = arr[i];
			m = i;
		}
	}
		printf("a = %lf,m = %d\n",a,m);
	return m;
}
