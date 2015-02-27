//list.h
#include<stdio.h>
#include<stdbool.h>
#define TSIZE 45
typedef struct {
	char title[TSIZE];
	int rate;
}film;
typedef struct node{
	film item;
	struct node * next;
}Node;
typedef Node * List;

void initialize(List * movies);

bool listisfull(const List * movies);

bool listisempty(const List * movies);

bool additem(film itm,List * movies);

void traverse(const List * movies,void (*showlist)(film item));

int listitemcount(const List * movies);

void emptythelist(List * movies);
