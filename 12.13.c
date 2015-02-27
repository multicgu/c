//manydice.c
//compile with diceroll.c(12.11.c)
#include<stdio.h>
#include<stdlib.h>
#include"12.12.h"
int main(void)
{
	int dice,sides,roll;
	printf("Pls enter the number of dice sides.(0 to stop)\n");
	while(scanf("%d",&sides)==1 && sides>0)
	{
		printf("How many dice do you want?\n");
		scanf("%d",&dice);
		roll=roll_n_dice(dice,sides);
		printf("You have rolled a %d using %d %d-sided dices.\n",roll,dice,sides);
		printf("Pls enter the number of dice sides.(0 to stop)\n");
	}
	printf("The rollem() function was called %d times.\n",count);
	
	return 0;
}
