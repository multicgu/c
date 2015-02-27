#include<stdio.h>
#include<time.h>
void delay(double time);
int main(void)
{
	double time;
	puts("Plese enter a delay time(in second),q to quit:");
	while(scanf("%lf",&time)==1&&time>0)
	{
		delay(time);
		puts("time out!");
	}
	return 0;
}
void delay(double time)
{
	//printf("CLOCK_PER_SEC=%ld\n",CLOCKS_PER_SEC);
	double origin=(clock()/CLOCKS_PER_SEC);
	//printf("%lf\n",origin);
	while((time+origin)>(clock()/CLOCKS_PER_SEC));
}
