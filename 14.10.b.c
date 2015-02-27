#include<stdio.h>
struct gas {
	float distance;
	float gals;
	float mpg;
};
void mpg(struct gas &ptrip);
int main(void)
{
	struct gas ohio = {583, 17.6};
	mpg(ohio);
	printf("%f %f %f.\n",ohio.distance,ohio.gals,ohio.mpg);
	return 0;
}
void mpg(struct gas &ptrip)
{
	if(ptrip->gals>0)
		ptrip->mpg=ptrip->distance/ptrip->gals;
	else
		ptrip->mpg=-1.0;
}
