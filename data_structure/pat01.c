#include<stdio.h>
int main(void)
{
	int n,i;
	fscanf(stdin,"%d",&n);
	int arr[n-1];
	for(i=0;i<n;i++)
		scanf("%d",&arr[i]);
	int max=0;
	int temp=0;
	for(i=0;i<n;i++)
	{
		temp+=arr[i];
		if(temp<0)
			temp=0;
		if(temp>=max)
			max=temp;
	}

	printf("%d\n",max);
	return 0;
}
