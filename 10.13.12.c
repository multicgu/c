#include<stdio.h>
#define ROWS 3
#define COLS 5
int main(void)
{
	int i,j;
	double arr[3][5];
	for(i=0;i<3;i++)
	{
		printf("Pls enter the assemble %d\n",i+1);
		for(j=0;j<5;j++)
			scanf("%lf",&arr[i][j]);
	}
	for(i=0;i<3;i++)
		for(j=0;j<5;j++)
			printf("arr[%d][%d]=%lf\n",i,j,arr[i][j]);
}
	
	/*printf("Please input 3 math assembles and every assemble have 5 double bumber.\n");
	for(i=0;i<ROWS;i++);
	{
		printf("Pls enter the assembles %d:\n",i);
		for(j=0;j<COLS;j++)
			scanf("%lf",&arr[i][j]);
	}
	for(i=0;i<ROWS;i++)
	{
		for(j=0;j<COLS;j++)
			printf("arr[%d][%d]=%lf\n",i,j,arr[i][j]);
	}
	printf("");
	return 0;
}*/
