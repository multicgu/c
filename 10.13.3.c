#include<stdio.h>
int remax(int ar[],int n);
int main(void)
{
	int arr[]={1,2,3,47,532,4,6,7};
	int a;
	int n = 0;
	for(n=0;n<(sizeof arr/sizeof arr[0]);n++)
		continue;	
	printf("n=%d\n",n);
	
	a = remax(arr,n);
	printf("a = %d\n",a);
	return 0;
}
int remax(int ar[],int n)
{
	int i,a;
	a = ar[0];
	for(i=1;i<n;i++)
	{
		if(a<ar[i])
			a = ar[i];
	}
	return a;
}
