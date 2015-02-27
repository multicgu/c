#include<stdio.h>
#include<stdlib.h>
#include<time.h>
int main(void)
{
	int n,m;
	srand((unsigned int) time(NULL));
	for(n=0;n<20;n++)
		for(m=0;m<30;m++)
		{
			if(m!=29)
			{
				printf("%d",rand()%10);
				putchar(' ');
			}
			else if(m==29)
			{
				printf("%d",rand()%10);
				putchar('\n');
			}
		}
	/*if((fp=fopen("testtest","w"))==NULL)
	{
		printf("ERROR.\n");
		exit(1);
	}*/
	return 0;
}
