#include<stdio.h>
void addarr(int *,int *,int *,int,int,int);
int main(void)
{
	int n,i;
	int arr1[4]={2,4,5,8};
	int arr2[6]={1,0,4,6,7,8};
	int arr3[7];
	addarr(arr1,arr2,arr3,4,6,7);
	for(i=0;i<7;i++)
		printf("arr3[%d]=%d\n",i,arr3[i]);
	return 0;
}
void addarr(int arr1[],int arr2[],int arr3[],int m,int n,int o)
{
	int i;
	int a;
	if(m>n)
	{
		if(m>o)
			a = m;
		else
			a=o;
	}
	else
	{
		if(n>o)
			a=n;
		else
			a=o;
	}	
	printf("a = %d\n",a);
	for(i=0;i<a;i++)
		arr3[i]= arr1[i]+arr2[i];
}
