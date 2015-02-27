// list.c 
#include<stdio.h>
#include<stdlib.h>
#include "17.3.h"
static void CopyToNode(Item item,Node * pnode);

void initializelist(List * plist)
{
	*plist = NULL;
}
bool listisempty(const List * plist)
{
	if(*plist==NULL)
		return true;
	else
		return false;
}
bool listisfull(const List * plist)
{
	Node * pt;
	bool full;

	pt=(Node *) malloc(sizeof(Node));
	if(pt==NULL)
		full=true;
	else
		full=false;
	free(pt);
	return full;
}
unsigned int listitemcount(const List * plist)
{
	unsigned int count = 0;
	Node * pnode = * plist;
	while(pnode!=NULL)
	{
		++count;
		pnode=pnode->next;
	}
	return count;
}
bool additem(Item item,List * plist)
{
	Node * pnew;
	Node * scan=*plist;
	pnew=(Node *) malloc(sizeof(Node));
	if(pnew==NULL)
		return false;

	CopyToNode(item,pnew);
	pnew->next=NULL;
	if(scan==NULL)
		*plist=pnew;
	else
	{
		while(scan->next!=NULL)
			scan=scan->next;
		scan->next=pnew;
	}
	return true;
}
void traverse(const List * plist,void (*pfun)(Item item))
{
	Node * pnode=*plist;
	while(pnode!=NULL)
	{
		(*pfun)(pnode->item);
		pnode=pnode->next;
	}
}
void emptythelist(List * plist)
{
	Node * psave;
	while(*plist !=NULL)
	{
		psave=(*plist)->next;
		free(*plist);
		*plist=psave;
	}
}
static void CopyToNode(Item item,Node * pnode)
{
	pnode->item=item;
}
