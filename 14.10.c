//names3.c
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
struct namect {
	char * fname;
	char * lname;
	int letters;
};
void getinfo(struct namect *);
void makeinfo(struct namect *);
void showinfo(const struct namect *);
void clearup(struct namect *);
int main(void)
{
	struct namect person;
	getinfo(&person);
	makeinfo(&person);
	showinfo(&person);
	clearup(&person);
	return 0;
}
void getinfo(struct namect * pst)
{
	char temp[81];
	printf("Pls enter the first name.\n");
	gets(temp);
	pst->fname=(char *) malloc(strlen(temp)+1);
	strcpy(pst->fname,temp);
	printf("Pls enter the last name.\n");
	gets(temp);
	pst->lname=(char *) malloc(strlen(temp)+1);
	strcpy(pst->lname,temp);
}
void makeinfo(struct namect * pst)
{
	pst->letters=strlen(pst->fname)+strlen(pst->lname);
}
void showinfo(const struct namect * pst)
{
	printf("you name is %s %s and have %d letters.\n",pst->fname,pst->lname,pst->letters);
}
void clearup(struct namect * pst)
{
	free(pst->fname);
	free(pst->lname);
}