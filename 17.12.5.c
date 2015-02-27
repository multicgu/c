#include<stdio.h>
#include<stdlib.h>
typedef struct node{
	char item;
	struct node * next;
}stack;
void installstack(stack * s);
void instack(stack * s,char * str);
char * pop(stack * s);
int main(void)
{
	char *str;
	stack s;
	installstack(&s);
	str=(char *) malloc(sizeof(char));
	printf("Enter a string, and we will show antiphrasis.\n");
	gets(str);
	printf("you enter is %s.\n",str);
	instack(&s,str);
	printf("%s\n",pop(&s));
	
	return 0;
}
void installstack(stack * s)
{
	s->next=NULL;
}
void instack(stack * s,char * str)
{
	//stack * temp;
	//temp=(stack *) malloc(sizeof(stack));
	printf("***instack after malloc temp\n");
	while((*str)!='\0')
	{
		stack * temp;
		temp=(stack *) malloc(sizeof(stack));
		if(s->next==NULL)
			temp->next=NULL;
		else
		{
			temp->next=s->next;
		}
		temp->item=*str;
		s->next=temp;
		str++;
	}
	printf("out instack.\n");
}
char * pop(stack * s)
{
	if(s->next==NULL)
		return NULL;
	stack * temp;
	temp=s->next;
	char * str;	
	str=(char *)malloc(sizeof(char));
	int n=0;
	while(s->next!=NULL)
	{
		temp=s->next;
		str[n++]=temp->item;
		printf("str[%d]=%c\n",n-1,*str);
		s->next=temp->next;
		//free(temp);
	}
	return str;
}
