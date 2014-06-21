#include<stdio.h>
#include "hotel.h"
int menu(void)
{
	int code;
	int status;
	printf("Please select the hotel you need:\n");
	printf("1. hotel 1.   2. hotel 2.\n");
	printf("3. hotel 3.   4. hotel 4.\n");
	while((status = scanf("%d",&code)) != 1 || (code <1 || code >4))
	{
		printf("status = %d\n",status);
		if(status != 1)
			scanf("%*s");
		printf("Please enter the number 1 to 5:\n");
	}
	return code;
}

int getnights(void)
{
	int nights;
	printf("Please enter how many nights you stay:\n");
	while(scanf("%d",&nights) != 1)
	{
		scanf("%*s");
		printf("Please enter number:\n");
	}
	return nights;
}

void showprice(double hotelrate,int nights)
{
	double total = 0.0;
	double discount = 1.0;
	int n;
	printf("hotelrate = %lf\n",hotelrate);
	for(n=1;n<=nights;discount*=0.95,n++)
		total += hotelrate*discount;
	printf("%lf\n",total);
}
