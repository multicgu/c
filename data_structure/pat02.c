#include<stdio.h>
int main(void)
{
	int n,i;
	int max=0,temp=0,f=0,l,ft=0;
	scanf("%d",&n);
	int arr[n];
	for(i=0;i<n;i++)
		scanf("%d",&arr[i]);
	l=n-1;
	for(i=0;i<n;i++)
	{
		temp+=arr[i];
		if(temp>max || (temp==0 && l==n-1)) //temp for if temp=0(not reset),l=n-1 for if the max appear before and 0 after (1 -2 -2 0 -2)
		{
			max=temp;
			l=i;
			f=ft;
		}
		if(temp<0)
		{
			temp=0;
			ft=i+1;
		}
	}
	printf("%d %d %d\n",max,arr[f],arr[l]);
	return 0;
}
