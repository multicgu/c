#include<stdio.h>
#include<string.h>
#include<ctype.h>
#include "17.10.h"

char menu(void);
void addpet(Tree * pt);
void showpets(Tree * pt);
void findpet(Tree * pt);
void droppet(Tree * pt);
void uppercase(char * str);
void printitem(Item item);

int main(void)
{
	Tree pets;
	char choise;
	while((choise=menu())!='q')
	{
		switch(choise)
		{
			case 'a':addpet(&pets);break;
			case 'l':showpets(&pets);break;
			case 'f':findpet(&pets);break;
			case 'n':printf("%d pets in club\n",TreeItCount(&pets));break;
			case 'd':droppet(&pets);break;
			default: puts("Switching error");
		}
	}
	DeleteAll(&pets);
	puts("Bye.");
	return 0;
}
char menu(void)
{
	int ch;
	puts("Nerfville Pet Club Membership Program");
	puts("Enter the letter corresponding to your choise: ");
	puts("a) add a pet l) show list of pets ");
	puts("n) number of pets f) find pets");
	puts("d) delete a pet q) quit");
	//while((ch=getchar())!='q')
	while((ch=getchar())!=EOF)
	{
		while(getchar()!='\n')
			continue;
		ch=tolower(ch);
		if(strchr("alnfdqr",ch)==NULL)
			puts("Pls enter an a,l,n,f,d or q");
		else 
			break;
	}
	if(ch==EOF)
		ch='q';
	return ch;
}

void addpet(Tree * pt)
{
	Item temp;
	puts("Enter the pet name you want add.\n");
	gets(temp.petname);
	puts("Enter the pet kind you want add.\n");
	gets(temp.petkind);
	uppercase(temp.petname);
	uppercase(temp.petkind);
}

void showpets(Tree * pt)
{
	if(TreeIsEmpty(pt))
		puts("No member in club.");
	else
		Traverse(pt,printitem);
}

void printitem(Item item)
{
	printf("Pet: %-19s Kind: %-19s\n",item.petname,item.petkind);
}

void findpet(Tree * pt)
{
	if(TreeIsEmpty(pt))
	{
		puts("No member in the club.");
		exit(1);
	}
	Item temp;
	puts("Enter the pet name you want to find.");
	gets(temp.petname);
	puts("Enter the pet kind you want to find.");
	gets(temp.petkind);
	uppercase(temp.petname);
	uppercase(temp.petkind);
	printf("%s the %s ",temp.petname,temp.petkind);
	if(InTree(&temp,pt->root)!=NULL)
		printf("is a member.\n");
	else
		printf("is not a member.\n");
}

void droppet(Tree * pt)
{
	Item temp;
	if(TreeIsEmpty(pt))
	{
		puts("No entries!");
		return;
	}
	puts("Please enter name of pet you wish to delete.");
	gets(temp.petname);
	puts("Please enter pet kind.");
	gets(temp.petkind);
	uppercase(temp.petname);
	uppercase(temp.petkind);
	printf("%s the %s ",temp.petname,temp.petkind);
	if(DeleteItem(temp,pt))
		printf("is dropped from the club.\n");
	else
		printf("is not a member.\n");
}

void uppercase(char * str)
{
	while(*str!='\0')
	{
		*str=toupper(*str);
		str++;
	}
}
