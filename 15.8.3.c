#include<stdio.h>
int itobn(int i);
int main(void)
{
	int i;
	printf("Enter the integer number.\n");
	while(scanf("%d",&i)!=1)
		fprintf(stderr,"Please enter the integer number.\n");
	printf("There are %d bits be opened.\n",itobn(i));
	return 0;
}
int itobn(int i)
{
	int sum=0;
	int n;
	for(n=0;n<8;n++,i>>=1)
		if((i&1)==1)
			sum++;
	return sum;
}
