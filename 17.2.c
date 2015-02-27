/*files2.c --struct linked*/
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#define SIZE 45
struct film{
	char title[SIZE];
	int rating;
};
struct linked{
	struct film films;
	struct linked * next;
};
int main(void)
{
	char input[SIZE];
	struct linked * head=NULL;
	struct linked * link,* temp;
	puts("Enter the film name:");
	while(gets(input)!=NULL && input[0]!='\0')
	{
		link=(struct linked *)malloc(sizeof(struct linked));
		if(head==NULL)
			head=link;
		else
			temp->next=link;
		link->next=NULL;
		strcpy(link->films.title,input);
		puts("Enter the rating:");
		scanf("%d",&link->films.rating);
		while(getchar()!='\n');
		temp=link;
		puts("Enter the next movie:");
	}
	/*show the list*/
	if(head==NULL)
		puts("No movie enter.");
	else
		puts("Movie list:");
	temp=head;
	while(temp)
	{
		printf("%s %d\n",temp->films.title,temp->films.rating);
		temp=temp->next;
	}
	/*free the malloc*/
	temp=head;
	while(temp)
	{
		free(temp);
		temp=temp->next;
	}
	puts("bye!");
	return 0;
}
