//#pragma c9x on
//queue.h
#ifndef _QUEUE_H_
#define _QUEUE_H_
#include<stdbool.h>
#include<stdlib.h>

//typedef int Item;
typedef struct item{
	int arrivetime;
	int processtime;
}Item;
#define MAXQUEUE 10
typedef struct node{
	Item item;
	struct node * next;
}Node;
typedef struct queue{
	Node * front;
	Node * rear;
	int items;
}Queue;
bool initializequeue(Queue * pq)
{
	pq->front=pq->rear=NULL;
	pq->items=0;
}
bool queueisempty(const Queue * pq)
{
	if(pq->items==0)
		return true;
	else
		return false;
}
bool queueisfull(const Queue * pq)
{
	if(pq->items==MAXQUEUE)
		return true;
	else
		return false;
}
bool enqueue(Item temp,Queue * pq)
{
	if(queueisfull(pq))
	{
		fprintf(stderr,"The line is full.\n");
		exit(1);
	}
	Node * pnew=(Node *) malloc(sizeof(Node));
	pnew->item=temp;
	pnew->next=NULL;
	if(queueisempty(pq))
	{
		pq->front=pq->rear=pnew;
		pq->items=1;
	}
	else
	{
		pq->rear->next=pnew;
		pq->rear=pnew;
		pq->items++;
	}
	return true;
}
bool dequeue(Item * temp,Queue * pq)
{
	Node * ptemp;
	if(queueisempty(pq))
	{
		printf("Nothing can be delete.\n");
		exit(1);
	}
	ptemp=pq->front;
	*temp=ptemp->item;
	pq->front=ptemp->next;
	free(ptemp);
	pq->items--;
	return true;
}
int queueitems(const Queue * pq)
{
	return pq->items;
}
void emptythequeue(Queue * pq)
{
	Node * ptemp;
	while(pq->items==0)
	{
		ptemp=pq->front;
		pq->front=pq->front->next;
		free(ptemp);
		pq->items--;
	}
	/*Item dummy;
	  while(!queueisempty(pq))
		dequeue(&dummy,pq);*/
}
#endif
