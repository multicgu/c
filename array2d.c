#include<stdio.h>
#define ROWS 3
#define COLS 4
void sumrow(int (*pr)[COLS]);
void sumcol(int pr[][COLS]);
void sum(int pr[][COLS]);
int main(void)
{
	int junk[ROWS][COLS] = {
		{2,4,6,8},{3,5,7,9},{12,10,8,6}
	};
	sumrow(junk);
	sumcol(junk);
	sum(junk);
	return 0;
}
void sumrow(int pr[][COLS])
{
	int n,i,total;
	for(i=0;i<ROWS;i++)
	{
		total = 0;
		for(n=0;n<COLS;n++)
			total += pr[i][n];
		printf("row %d: sum = %d\n",i,total);
	}
}
void sumcol(int pr[][COLS])
{
	int n,i,total;
	for(n=0;n<COLS;n++)
	{
		total = 0;
		for(i=0;i<ROWS;i++)
			total += pr[i][n];
	printf("col %d: sum = %d\n",n,total);
	}
}
void sum(int pr[][COLS])
{
	int n,i,total;
	total = 0;
	for(n=0;n<ROWS;n++)
		for(i=0;i<COLS;i++)
			total += pr[n][i];
	printf("sum = %d\n",total);
}
