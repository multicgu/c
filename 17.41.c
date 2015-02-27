#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include "17.31.h"
void showmovies(film item);
int main(void)
{
	film temp;
	List movies;
	movies=(List) malloc(sizeof(Node));
	// initialize a list;
	initialize(movies);
	if(movies==NULL)printf("movies NULL\n");
	if(listisfull(movies))
	{
		fprintf(stderr,"Movie list is full.\n");
		exit(1);
	}
	//get the movies;
	puts("Enter the title of the film:");
	while(gets(temp.title)!=NULL && temp.title[0]!='\0')
	{
		puts("Enter the rating of the film:");
		scanf("%d",&temp.rate);
		//printf("%s %d\n",temp.title,temp.rate);
		while(getchar()!='\n')
		{
			printf("...");
		}
		//printf("Beforeadd:%s %d %p\n",movies->item.title,movies->item.rate,movies);
		if(additem(temp,movies)==false)
		{
			fprintf(stderr,"Error to add item.\n");
			exit(1);
		}
		if(listisfull(movies))
			printf("The movies list is full.\n");
		printf("Afteradd:%s %d %p\n",movies->item.title,movies->item.rate,movies);
		printf("Enter the title of the another film:\n");
	}
	//show the movies & count the movies numbers;
	//if(listisempty(movies)==true)
	if(movies==NULL)
		printf("No date shows.\n");
	else
	{
		printf("The movies information is :\n");
		traverse(movies,showmovies);
		printf("You entered %d movies.\n",listitemcount(movies));
	}
	// empty the list
	emptythelist(movies);
	printf("Bye!\n");
	return 0;
}
void showmovies(film item)
{
	printf("Title: %s,rate: %d\n",item.title,item.rate);
}
