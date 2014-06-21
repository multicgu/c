#include<stdio.h>
void copy(int n,int m,double target[n][m],double arr[][5]);
void show(int n,int m,double arr[n][m],double target[n][m]);
int main(void)
{
	int a,b;
	double arr[3][5]={
		{1.1,1.2,1.3,1.4,1.5},{2.1,2.2,2.3,2.4,2.5},{3.1,3.2,3.3,3.4,3.5}
	};
	int n=3;
	int m=5;
	double target[n][m];

	printf("main arr\n");
	for(a=0;a<3;a++)
		for(b=0;b<5;b++)
			printf("arr[%d][%d] = %.1lf ",a,b,arr[a][b]);
	putchar('\n');
	
	copy(3,5,target,arr);

	printf("main target\n");
	for(a=0;a<3;a++)
		for(b=0;b<5;b++)
			printf("tar[%d][%d] = %.1lf ",a,b,target[a][b]);
	putchar('\n');

	show(3,5,arr,target);

	return 0;
}
void copy(int n,int m,double target[n][m],double (* arr)[5])
{
	int i,j;

	printf("copy arr\n");
	for(i=0;i<n;i++)
		for(j=0;j<m;j++)
			printf("arr[%d][%d] = %.1lf ",i,j,arr[i][j]);
	
	printf("copy target\n");
	for(i=0;i<n;i++)
		for(j=0;j<m;j++)
		{
			target[i][j] = arr[i][j];
			printf("tar[%d][%d] = %.1lf ",i,j,target[i][j]);
		}
	putchar('\n');
}
void show(int n,int m,double arr[n][m],double target[n][m])
{
	printf("show arr\n");
	int i,j;
	for(i=0;i<n;i++)
		for(j=0;j<m;j++)
			printf("arr[%d][%d] = %.1lf ",i,j,arr[i][j]);
	putchar('\n');
	
	printf("show target\n");
	for(i=0;i<n;i++)
		for(j=0;j<m;j++)
			printf("tar[%d][%d] = %.1lf ",i,j,target[i][j]);
	putchar('\n');
}
