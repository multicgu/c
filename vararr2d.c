#include<stdio.h>
#define ROWS 3
#define COLS 4
int sum2d(int,int,int ar[*][*]);
int main(void)
{
	int junk[ROWS][COLS]={
		{2,4,6,8},{3,5,7,9},{12,10,8,6}
	};
	int morejunk[ROWS-1][COLS+2]={
		{20,30,40,50,60,70},{5,6,7,8,9,10}
	};
	int i,j;
	int a = 3;
	int b = 10;
	int varr[a][b];
	for(i=0;i<a;i++)
		for(j=0;j<b;j++)
			varr[i][j]=i*j+j;
	printf("3*4array\n");
	printf("sum of all elements = %d\n",sum2d(ROWS,COLS,junk));
	printf("2*6array\n");
	printf("sum of all elements = %d\n",sum2d(ROWS,COLS,morejunk));
	printf("3*10 VLA\n");
	printf("sum of all elements = %d\n",sum2d(a,b,varr));
	return 0;
}
int sum2d(int rows,int cols,int ar[rows][cols])
{
	int i,j;
	int total=0;
	for(i=0;i<rows;i++)
		for(j=0;j<cols;j++)
			total += ar[i][j];
	return total;
}
