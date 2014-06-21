#include<stdio.h>
long fact(int n);
long rfact(int n);
int main(void)
{
	int n;
	printf("Enter a number between 0 to 12.\n");
	while((scanf("%d",&n)) == 1)
	{
		if((n<0) && (n>12))
			printf("The number you input isn't suit.Please retry.\n");
		else
		{
			printf("loop: %d factorial = %ld.\n",n,fact(n));
			printf("loop: %d factorial = %ld.\n",n,rfact(n));
		}
	}
	return 0;
}

long fact(int n)
{
	long ans;
	for(ans=1;n>0;n--)
		ans *= n;
	return ans;
}

long rfact(int n)
{
	long ans;
	if(n>0)
		ans = n * rfact(n-1);
	else
		ans = 1;
	return ans;
}
