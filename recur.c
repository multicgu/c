#include<stdio.h>
void up_and_down(int a);
int main(void)
{
	up_and_down(1);	
	return 0;
}

void up_and_down(int a)
{
	printf("level %d, a location %d.\n",a,&a);
	if(a<5)
		up_and_down(a+1);
	printf("level %d, a location %d.\n",a,&a);
}
