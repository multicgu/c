#include<stdio.h>
#define ROWS 3
#define COLS 5
void assign(int m,int n,double [m][n]);
double ass_average(int m,int n,double arr[m][n]);
double allaverage(int m,int n,double arr[m][n]);
double max(int m,int n,double arr[m][n]);
void print(int m,int n,double arr[m][n]);
int main(void)
{
	double arr[3][5];
	assign(3,5,arr);
	print(3,5,arr);

	return 0;
}
void assign(int m,int n,double arr[m][n])
{
	int i,j;
	printf("Enter %d number assembles,every assembles have %d numbers.\n",m,n);
	for(i=0;i<m;i++)
	{
		printf("Pls enter assemble %d:\n",i);
		for(j=0;j<n;j++)
			scanf("%lf",&arr[i][j]);
	}
}
double ass_average(int m,int n,double arr[m][n])
{
	int i,j;
	double total=0;
	for(j=0;j<n;j++)
		total += arr[m][j];
	return (total/j);
}
double allaverage(int m,int n,double arr[m][n])
{
	int i,j;
	double total=0;
	for(i=0;i<m;i++)
		for(j=0;j<n;j++)
			total += arr[i][j];
	return (total/(m*n));
}
double max(int m,int n,double arr[m][n])
{
	int i,j;
	double maxnum;
	for(i=0,maxnum=arr[0][0];i<m;i++)
		for(j=0;j<n;j++)
			{
				if(maxnum<=arr[i][j])
					maxnum = arr[i][j];
			}
	return maxnum;
}
void print(int m,int n,double arr[m][n])
{
	int i,j;
	for(i=0;i<m;i++)
	{
		for(j=0;j<n;j++)
			printf("arr[%d][%d]=%.1lf ",i,j,arr[i][j]);
		putchar('\n');
	}
	for(i=0;i<m;i++)
		printf("Assembles %d average is %.1lf\n",i+1,ass_average(i,COLS,arr));
	printf("All numbers average in arr is %.1lf\n",allaverage(ROWS,COLS,arr));
	printf("max is %.1lf\n",max(ROWS,COLS,arr));

}
