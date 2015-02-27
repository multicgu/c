#include<stdio.h>
#define HARAVER(X,Y) 1/((1/(x)+1/(y))/2)
int main(void)
{
	float x=3;
	float y=5;
	printf("Harmonic average of number 3 & 5 is %f\n",HARAVER(x,y));
	return 0;
}
