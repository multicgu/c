#include<stdio.h>
void binary(int n);
int main(void)
{
	int n;
	while(scanf("%d",&n) == 1)
		binary(n);	

	return 0;
}

void binary(int n)
{
	int i;
	i = n%2;
	if(n>=2)
		binary(n/2);
	printf("%d",i);
}
