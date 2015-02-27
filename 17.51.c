#include<stdio.h>
#include<stdlib.h>
#include "17.31.h"
void initialize(List * movies)
{
	*movies = NULL;
}
bool listisempty(const List * movies)
{
	if(*movies==NULL)
		return true;
	else
		return false;
}
bool listisfull(const List * movies)
{
	bool full;
	List temp=(List) malloc(sizeof(Node));
	if(temp==NULL)
		full=true;
	else
		full=false;
	free(temp);
	return full;
}
/*bool additem(film item,List movies)
{
	List tp;
	tp=(List) malloc(sizeof(List));
	tp=movies;
	//if(listisfull(movies))
	//	return false;
	if(movies==NULL)
	{
		movies=(List) malloc(sizeof(List));
		printf("addtrue\n");
		movies->item=item;
		movies->next=NULL;
	}
	else
	{
		printf("addtrueee\n");
		while(tp->next!=NULL)
			tp=tp->next;
		tp->next=movies;
		movies->next=NULL;
	}
	return true;
}*/
bool additem(film itm,List * movies)
{
	List tp;
	List scan=*movies;
	tp=(List) malloc(sizeof(Node));
	if(tp==NULL)
		return false;
	tp->item=itm;
	tp->next=NULL;
	if(*movies==NULL)
	{
		printf("null\n");
		//movies=(List) malloc(sizeof(Node));
		*movies=tp;
		printf("itm %s %d\n",itm.title,itm.rate);
		printf("tp %s %d\n",tp->item.title,tp->item.rate);
		printf("movies %s %d %p\n",(*movies)->item.title,(*movies)->item.rate,*movies);
	}
	else
	{
		printf("nonull\n");
		printf("itm %s %d\n",itm.title,itm.rate);
		printf("tp %s %d\n",tp->item.title,tp->item.rate);
		//printf("movies %d %s\n",(*movies)->item.title,(*movies)->item.rate);
		while(scan->next!=NULL)
			scan=scan->next;
		scan->next=tp;
	}
	return true;
}
void traverse(const List * movies,void (*showlist)(film item))
{
	List temp=*movies;
	while(temp)
	{
		(*showlist)(temp->item);
		temp=temp->next;
	}
}
int listitemcount(const List * movies)
{
	int n=1;
	List temp=*movies;
	while(temp)
	{
		n++;
		temp=temp->next;
	}
	return n;
}
void emptythelist(List * movies)
{
	List temp;
	while(*movies)
	{
		temp=(*movies)->next;
		free(*movies);
		*movies=temp;
	}
}
