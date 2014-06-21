#include<stdio.h>
void year(int n,int m,float rain[n][m]);
void month(int n,int m,float rain[n][m]);
#define MONTHS 12
#define YEARS 5
int main(void)
{
	float rain[YEARS][MONTHS]={
		{4.3,4.3,4.3,3.0,2.0,1.2,0.2,0.2,0.4,2.4,3.5,6.6},
		{8.5,8.2,1.2,1.6,2.4,0.0,5.2,0.9,0.3,0.9,1.4,7.3},
		{9.1,8.5,6.7,4.3,2.1,0.8,0.2,0.2,1.1,2.3,6.1,8.4},
		{7.2,9.9,8.4,3.3,1.2,0.8,0.4,0.0,0.6,1.7,4.3,6.2},
		{7.6,5.6,3.8,2.8,3.8,0.2,0.0,0.0,0.0,1.3,2.6,5.2}
	};
	year(YEARS,MONTHS,rain);

	return 0;
}
void year(int n,int m,float rain[n][m])
{
	int i,j;
	float year,month,yeartotal,monthtotal;
	for(i=0;i<n;i++)
	{
		for(j=0,year=0;j<m;j++)
		{
			year += rain[i][j];
		}
		printf("200%d year total rainfall is %.1f inchs.\n",i+1,year);
		yeartotal += year;
	}
	printf("\nThe yearly average is %.1f inches.\n",yeartotal/YEARS);

	printf("Monthly averages: \n");
	printf(" Jan Feb Mar Apr May Jun Jul Aug Sep Oct Nov Dec\n");
	for(j=0;j<m;j++)
	{
		for(i=0,month=0;i<n;i++)
			month += rain[i][j];
		printf("Month %d total rainfall is %.1f\n",i+1,month);
		printf("Month %d average rainfall in 5 years is %.1f\n",j+1,month/YEARS);
		monthtotal += month;
	}
	printf("monthtotal = %.1f\n",monthtotal);
}