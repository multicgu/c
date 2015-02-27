#include<stdio.h>
int hailstone(int n);
int main(void)
{
	int n;
	int i;
	fprintf(stdout,"Enter n.\n");
	scanf("%d",&n);
	i=hailstone(n);
	printf("i=%d\n",i);

	return 0;
}
int hailstone(int n)
{
	static int length=0;
	while(n>1)
	{
		n=(n%2)!=0?(3*n+1):(n/2);
		printf("%d, ",n);
		length++;
		return hailstone(n);
	}
	return length;
}
