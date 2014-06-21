#include<stdio.h>
void menu(void)
{
    printf("Please choose one of the following:\n");
    printf("1) copy files  2) move files\n");
    printf("3) remove files 4) quit\n");
}

int choise(int x,int y)
{
	int n;
	int i;
	while((i = scanf("%d",&n)) !=1  || (n<x || n>y))
	{
		printf("i = %d\n",i);
	    if(i!=1)
		{
		    scanf("%*s");
		    printf("Please enter a number:\n");
		}
	    else
			menu();
	}

    return n;
}

int main(void)
{
	int n;
	menu();
	n = choise(1,4);
	printf("%d\n",n);
	return 0;
}
