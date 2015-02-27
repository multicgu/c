#include<stdio.h>
#include<math.h>
#define PR(x,...) printf("Message" #x ":"__VA_ARGS__);
int main(void)
{
	double x=48;
	double y;
	y=sqrt(x);
	PR(1,"x=%g\n",x);
	PR(2,"y=%.4f\n",y);
	return 0;
}
