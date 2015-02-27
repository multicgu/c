#include<stdio.h>
#include"12.11.3.h"
/*static int modes;
static double distance;
static double fuel;*/
void set_mode(int * modes)
{
	if(*modes>1)
	{
		printf("Invalid mode specified. Mode 1(US) used.\n");
		*modes=1;
	}
	printf("modes=%d\n",*modes);
}
void get_info(double *distance,double *fuel,int modes)
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
	printf("distance=%.2f,fuel=%.2f\n",*distance,*fuel);
}
void show_info(double distance,double fuel,int modes)
{
	if(modes==0)
		printf("Fuel consumption is %.2f liters per 100 km\n",(fuel/distance)*100);
	else
		printf("Fuel consumption is %.2f miles per gallon.\n",distance/fuel);
}
