//use_q.c
//compile with queue.c
#include<stdio.h>
#include<stdbool.h>
#include<stdlib.h>
#include "17.6.h"
int main(void)
{
	char ch;
	Item temp;
	Queue line;
	initializequeue(&line);
	puts("Testing the Queue interface.type 'a' to add a vaule,");
	puts("type 'd' to delete a value and type 'q' to quit.");
	while((ch=getchar())!='q')
	{
		if(ch!='a' && ch!='d')
		{
			continue;
			printf("continue test.\n");
		}
		if(ch=='a')
		{
			printf("In a while.\n");
			if(queueisfull(&line))
			{
				fprintf(stderr,"The queue is full.\n");
				exit(1);
			}
			else
			{
				printf("Interger to add: ");
				scanf("%d",&temp);
				printf("putting %d into queue.\n",temp);
				enqueue(temp,&line);
			}
		}
		else
		{
			if(queueisempty(&line))
				puts("The queue is empty.\n");
			else
			{
				dequeue(&temp,&line);
				printf("Romoving %d from queue.\n",temp);
			}
		}
		printf("%d item in queue.\n",queueitems(&line));
		puts("Type 'a' to add,'d' to delete,'q' to quit.");
	}
	emptythequeue(&line);		
	puts("Bye!");
	return 0;
}
