#include<stdio.h>
int checkbit(int i,int bit);
int main(void)
{
	int i,bit;
	printf("Please enter a integer and a position of the bit.\n");
	while(scanf("%d%d",&i,&bit)!=2 || bit>8)
		fprintf(stderr,"You enter is error,retry.\n");
	printf("The return is %d.\n",checkbit(i,bit));
	return 0;
}
int checkbit(int i,int bit)
{
	if(((i>>(bit-1))&1)==1)
		return 1;
	else
		return 0;
}
