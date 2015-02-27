//parta.c
#include<stdio.h>
extern void accumulate(int k);
void report_count(void);
int count=0;  //a;
int main(void)
{
	int value;  //b;
	register int i;  //c;
	printf("Enter a positive interger(0 to quit):\n");
	while(scanf("%d",&value) && value>0)
	{
		++count;
		for(i=value;i>=0;i--)
			accumulate(i);
		printf("Enter a positive interger(0 to quit):\n");
	}
	report_count();

	return 0;
}
void report_count(void)
{
	printf("Loop executed %d times\n",count);
}
