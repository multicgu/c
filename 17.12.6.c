#include<stdio.h>
#include<stdbool.h>
bool searchbin(int * arr,int n,int item);
bool bin(int max,int min,int * arr,int item);
int main(void)
{
	int arr[10]={1,2,3,4,5,6,7,8,9,10};
	int n=10;
	int item=8;
	if(searchbin(arr,n,item))
		printf("true.\n");
	else
		printf("false.\n");
	return 0;
}

bool searchbin(int * arr,int n,int item)
{
	int min=0;
	int max=n-1;
	return bin(max,min,arr,item);
}

bool bin(int max,int min,int * arr,int item)
{
	if(min>max)
		return false;
	int n=(min+max)/2;
	if(arr[n]>item)
		bin(n-1,min,arr,item);
	else if(arr[n]<item)
		bin(max,n+1,arr,item);
	else if(arr[n]==item)
	{
		printf("%d\n",arr[n]);
		return true;
	}
}
