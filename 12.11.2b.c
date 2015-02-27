#include<stdio.h>
#include"pe12-2.h"
static int modes;
static double distance;
static double fuel;
void set_mode(int  mode)
{
	if(mode==0 || mode==1)
		modes = mode;
	else
	{
		printf("Invalid mode specified. Mode 1(US) used.\n");
		*modes=1;
	}
	printf("modes=%d\n",*modes);
}
void get_info(void)
{
	if(modes==1)
	{
		printf("Enter distance traveled in miles: ");
		scanf("%lf",distance);
		printf("Enter fuel consumed in gallons: ");
		scanf("%lf",fuel);
	}
	else
	{
		printf("Enter distance traveled in kilometers: ");
		scanf("%lf",distance);
		printf("Enter fuel consumed in liters: ");
		scanf("%lf",fuel);
	}
	printf("distance=%.2f,fuel=%.2f\n",distance,fuel);
}
void show_info(void)
{
	if(modes==0)
		printf("Fuel consumption is %.2f liters per 100 km\n",(fuel/distance)*100);
	else
		printf("Fuel consumption is %.2f miles per gallon.\n",distance/fuel);
}
