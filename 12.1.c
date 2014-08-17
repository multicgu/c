#include<stdio.h>
int main(void)
{
	int x = 30;
	printf("x in outer block is %d\n",x);
	{
		int x = 77;
		printf("x in inner block is %d\n",x);
	}
	printf("x in outer block is %d\n",x);
	while(x++ < 33)
	{
		int x = 100;
		x++;
		printf("x in whlie block is %d\n",x);
	}
	printf("x in outer block is %d\n",x);
	return 0;
}
