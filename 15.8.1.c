#include<stdio.h>
#include<string.h>
int btoi(char * bin);
int main(void)
{
	char * pbin="01001001";
	printf("%d\n",btoi(pbin));
	return 0;
}
int btoi(char * bin)
{
	int i=0;
	while(bin[i])
		i++;
	printf("%d.\n",i);
	int n,sum=0;
	int mask=1;
	for(n=i-1;n>=0;n--,mask=mask<<1)
	{
		if(bin[n]==49)
			sum |= mask;
		if(bin[n]!=48 && bin[n]!=49)
		{
			printf("n=%d,bin=%d.\n",n,bin[n]);
			printf("Please input the binary.\n");
			break;
		}
	}
	return sum;
}
