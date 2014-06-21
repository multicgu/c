#include<stdio.h>
double rediff(double *,int);
int main(void)
{
	double arr[]={3.3,3.4,2.2,9.9,4.4,1.1,5.5,6.6};
	int n;
	for(n=0;n<(sizeof arr/sizeof arr[0]);n++);
	printf("n=%d\n",n);
	printf("diff = %.1lf\n",rediff(arr,n));
	return 0;
}
double rediff(double * arr,int n)
{
	int i;
	double a,b;
	for(i=1,a=arr[0],b=arr[0];i<n;i++)
	{
		if(a<=arr[i])
			a = arr[i];
		if(b>=arr[i])
			b = arr[i];
	}
	printf("max=%.1lf,min=%.1lf,diff=%.1lf\n",a,b,a-b);
	return (a-b);
}
