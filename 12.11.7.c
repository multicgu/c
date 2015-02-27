#include<stdio.h>
#include<time.h>
#include<stdlib.h>
int main(void)
{
	int sets;
	int n;
	int side,dice;
	int roll;
	srand((unsigned int) time(0));
	printf("Enter the number of sets; enter q to stop.\n");
	while(scanf("%d",&sets)!=0)
	{
		printf("How many sides and how many dice?\n");
		scanf("%d%d",&side,&dice);
		printf("Here are %d sets of 3 6-sided throws.\n",sets);
		for(n=0;n<sets;n++)
		{
			roll=roll_n_dice(side,dice);
			if(roll==-1 || roll == -2)
				break;
			printf("%d ",roll);
		}
		printf("\nHow many sets? Enter q to stop.\n");
	}
	return 0;
}
int roll_n_dice(int side,int dice)
{
	int total=0;
	int n;
	if(side<2)
	{
		printf("Need at least 2 sides.\n");
		return -2;
	}
	if(dice<1)
	{
		printf("Need at least 1 sides.\n");
		return -1;
	}
	for(n=0;n<dice;n++)
		total+=rand()%side+1;
	return total;
}
