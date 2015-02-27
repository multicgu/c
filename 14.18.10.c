#include<stdio.h>
float add(float x,float y);
float subtract(float x,float y);
float multiply(float x,float y);
float divide(float x,float y);
//float (*fp[4])(float x,float y);
int main(void)
{
	int n;
	float x,y;
	printf("Enter x and y.\n");
	scanf("%f%f",&x,&y);
	float (* pf[4])(float x,float y)={add,subtract,multiply,divide};
	printf("Please choice:\n");
	printf("1.add 2.subtract 3.multicply 4.divide\n");
	scanf("%d",&n);
	printf("%f\n",(*pf[n-1])(x,y));
	return 0;
}
float add(float x,float y)
{
	return x+y;
}
float subtract(float x,float y)
{
	return x-y;
}
float multiply(float x,float y)
{
	return x*y;
}
float divide(float x,float y)
{
	return x/y;
}
