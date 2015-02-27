/* list.h */
#ifndef LIST_H_
#define LIST_H_
#include<stdbool.h>
#define TSIZE 45
struct film
{
	char title[TSIZE];
	int rating;
};
typedef struct film Item;
typedef struct node
{
	Item item;
	struct node * next;
}Node;
typedef Node * List;

void initializelist(List * plist);

bool listisempty(const List * plist);

bool listisfull(const List * plist);

unsigned int listitemconut(const List * plist);

bool additem(Item item,List * plist);

void Traverse(const List * plist,void (*prfun)(Item item));

void emptythelist(List * plist);

#endif
