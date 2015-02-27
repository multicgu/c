#include<stdio.h>
#include<stdlib.h>
#include "17.12.7.h"
void showmanu(void);
void showword(tree * pt);
void showtimes(tree * pt,char * word);
void addnode(tree * pt,char * word);
int main(void)
{
	FILE * fp;
	char choise;
	char word[20];
	char item[20];
	tree * pt=createtree();
	if((fp=fopen("word1","r"))==NULL)
	{
		fprintf(stderr,"the file \'word\' can not be open.\n");
		exit(1);
	}
	while(fscanf(fp,"%s",item)==1)
		addnode(pt,item);

	showmanu();
	choise=getchar();
	while(choise!='e')
	{
		while(getchar()!='\n')
			continue;
		switch(choise)
		{
			case 'l': showword(pt);break;
			case 'i': gets(word);
					  showtimes(pt,word);	break;
			case 'e': break;
			default: printf("Please enter 'l','i','e'\n");break;
		}
		showmanu();
		choise=getchar();
	}
	return 0;
}
void showmanu(void)
{
	puts("Select below options:");
	puts("l) list all words in the file.");
	puts("i) input a word and we will show the numbers in file.");
	puts("e) end the progrem.");
}
void showword(tree * pt)
{
	listword(pt->root);
}
void showtimes(tree * pt,char * word)
{
	sw * s=searchword(pt->root,word);
	if(s->b==1 || s->b==0)
		printf("these is no word that you enter.\n");
	else
		printf("The word %s have %d times.\n",s->root->item,s->root->num);
}
