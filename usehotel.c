#include<stdio.h>
#include "hotel.h"
int main(void)
{
	int code;
	int nights;
	double hotel_rate;
	code = menu();
	switch(code)
	{
		case 1:hotel_rate=hotel1;
			   break;
		case 2:hotel_rate=hotel2;
			   break;
		case 3:hotel_rate=hotel3;
			   break;
		case 4:hotel_rate=hotel4;
			   break;
		default:hotel_rate=0.0;
				printf("Opps!\n");
				break;
	}
	nights=getnights();
	printf("hotel_rate= %lf\n",hotel_rate);
	showprice(hotel_rate,nights);

	return 0;
}
