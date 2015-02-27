// films3.c
/*与list.c 一起编译*/
#include<stdio.h>
#include<stdlib.h>
#include "17.3.h"
void showmovies(Item item);
int main(void)
{
	List movies;
	Item temp;

	initializelist(&movies);
	if(listisfull(movies))
	{
		fprintf(stderr,"No memory available! bye!\n");
		exit(1);
	}
	puts("Enter first movie title: ");
	while(gets(temp.title)!=NULL && temp.title[0] != '\0')
	{
		 	puts("Enter your rating<0-10>: ");
			scanf("%d",&temp.rating);
			while(getchar()!='\n')
				continue;
			if(additem(temp,&movies)==false)
			{
				fprintf(stderr,"Problem allocating memory\n");
				break;
			}
			if(listisfull(movies))
			{
				puts("The list is now full.");
				break;
			}
			puts("Enter next moves title (empty line to quit):");
	}

	if(listisempty(movies))
		printf("No data entered.\n");
	else
	{
		printf("Here is the movie list:\n");
		traverse(movies,showmovies);
	}
	printf("You entered %d movies.\n",listitemcount(movies));

	emptythelist(&movies);
	printf("Bye!\n");
	return 0;
}
void showmovies(Item item)
{
	printf("Movie: %s Rating: %d\n",item.title,item.rating);
}
