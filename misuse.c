#include<stdio.h>
int imax();
int main(void)
{
	printf("The maximum number of %d and %d is %d.\n",2,5,imax(4));
	printf("The maximun number if %d and %d is %d.\n",2,5,imax(2.0,5.0));
	return 0;
}

int imax(n,m)
int n,m;
{
	int max;
	if(n<m)
		max = m;
	else
		max = n;
	return max;
}
