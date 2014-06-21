#include<stdio.h>
void show(int [][5],int);
void doub(int [][5],int);
int main(void)
{
	int arr[3][5]={
		{1,2,3,4,5},{11,22,33,44,55},{111,222,333,444,555}
	};
	show(arr,3);
	doub(arr,3);
	show(arr,3);
	return 0;
}
void show(int (*arr)[5],int n)
{
	int i,j;
	for(i=0;i<n;i++)
	{
		for(j=0;j<5;j++)
			printf("arr[%d][%d]=%d ",i,j,arr[i][j]);
		putchar('\n');
	}
	putchar('\n');
}
void doub(int (* arr)[5],int n)
{
	int i,j;
	for(i=0;i<n;i++)
		for(j=0;j<5;j++)
			arr[i][j] *= 2;
}
