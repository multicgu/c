//r_drive1.c  -- test function rand1() and srand1();
#include<stdio.h>
unsigned seed;
extern unsigned long int rand1(void);
void srand1(int);
int main(void)
{
	int count;
	//unsigned seed;
	printf("Enter the seed value.\n");
	while(scanf("%d",&seed)==1)
	{
		printf("seed = %d\n",seed);
		srand1(seed);
		for(count=1;count<=5;count++)
			printf("%lu\n",rand1());
		printf("Enter the seed value.\n");
	}

	return 0;
}
