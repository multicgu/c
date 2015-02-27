#include<stdio.h>
void rotate_l(unsigned int x,int a);
int main(void)
{
	unsigned int i;
	printf("Please enter integer number.\n");
	while(scanf("%d",&i)!=1)
		fprintf(stderr,"Error to enter.\n");
	printf("After rotate left 4 position.\n");
	rotate_l(i,4);

	return 0;
}
void rotate_l(unsigned int x,int a)
{
	int n,i;
	int size=sizeof(unsigned int)*8;
	printf("size=%d\n",size);
	for(n=0;n<a;n++)
	{
		if((x&(1<<(size-1)))!=0)
			x=((x<<1)|1);
		else
			x<<=1;
	}	
	printf("%d\n",x);
}
