#include<stdio.h>
#define COLS 4
int sum(int ar[],int);
int sum2d(int ar[][COLS],int);
int main(void)
{
	int total1,total2,total3;
	int * pt1;
	int (* pt2)[COLS];
	pt1 = (int[2]) {10,20};
	pt2 = (int [2][COLS]) {{1,2,3,-9},{4,5,6,-8}};
	total1 = sum(pt1,2);
	total2 = sum2d(pt2,2);
	total3 = sum((int []) {4,4,4,5,5,5},6);
	printf("total1=%d,total2=%d,total3=%d\n",total1,total2,total3);
	
	return 0;
}

int sum(int ar[],int n)
{
	int i;
	int total=0;
	for(i=0;i<n;i++)
		total += ar[i];
	return total;
}
int sum2d(int ar[][COLS],int n)
{
	int i,m;
	int total=0;
	for(i=0;i<n;i++)
		for(m=0;m<COLS;m++)
			total += ar[i][m];
	return total;
}
