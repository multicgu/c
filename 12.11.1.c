/*noglobal.c NOT use golbal varible*/
#include<stdio.h>
void critic(int * units);
int main(void)
{
	int units;
	printf("How many pounds to a firkin of butter?\n");
	scanf("%d",&units);
	printf("units in main is %d and %p\n",units,&units);
	while(units!=56)
		critic(&units);
	printf("You must have looked it up.\n");
	printf("units in main is %d and %p\n",units,&units);

	return 0;
}
void critic(int * units)
{
	printf("No luck,chummy, try again.\n");
	scanf("%d",units);
	printf("units in critic is %d and %p\n",*units,units);
}
