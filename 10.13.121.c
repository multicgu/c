#include<stdio.h>
#define ROWS 3
#define COLS 5
void assign(double [][5],int );
double ass_average(double [][5],int );
double allaverage(double [][5],int );
double max(double [][5],int );
void print(double [][5],int );
int main(void)
{
	double arr[3][5];
	assign(arr,ROWS);   // function a;
	print(arr,ROWS);

	return 0;
}
void assign(double (* arr)[5],int rows)   // function a;
{
	int i,j;
	printf("Enter %d math assembles,every assemble have %d double number.\n",rows,COLS);
	for(i=0;i<rows;i++)
	{
		printf("Pls enter %d numbers in assembles %d\n",COLS,i+1);
		for(j=0;j<COLS;j++)
		{
			scanf("%lf",&arr[i][j]);
		}
	}
}
double ass_average(double (* arr)[5],int r)  // function b;
{
	int i,j;
	double total=0.0;
	for(j=0;j<COLS;j++)
		total += arr[r][j];
	printf("total = %.1lf\n",total);
	return (total/COLS);
}
double allaverage(double arr[][5],int rows)  // function c;
{
	int i,j;
	double total=0;
	for(i=0;i<rows;i++)
		for(j=0;j<COLS;j++)
			total += arr[i][j];
	printf("total = %.1lf\n",total);
	return (total/(rows*COLS));
}
double max(double (* arr)[5],int rows)  // function d;
{
	int i,j;
	double m;
	for(i=0,m=arr[0][0];i<rows;i++)
		for(j=0;j<COLS;j++)
		{
			if(m<arr[i][j])
				m = arr[i][j];
			else
				continue;
		}
	printf("m=%.1lf\n",m);
	return m;
}
void print(double (* arr)[5],int rows)
{
	int i,j;
	for(i = 0;i<rows;i++)
	{
		for(j=0;j<COLS;j++)
			printf("arr[%d][%d]=%.1lf ",i,j,arr[i][j]);
		putchar('\n');	
	}
	for(i=0;i<rows;i++)
	{
		printf("Assemble %d average is %.1lf\n",i+1,ass_average(arr,i));
	}
	printf("The average of all numbers is %.1lf\n",allaverage(arr,ROWS));
	printf("The max numbers in arr[3][5] is %.1lf\n",max(arr,ROWS));
}
