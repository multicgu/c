//names1.c
#include<stdio.h>
#include<string.h>
struct namect {
	char fname[20];
	char lname[20];
	int letters;
};
void getinfo(struct namect * );
void makeinfo(struct namect * );
void showinfo(const struct namect * );
int main(void)
{
	struct namect pst;
	getinfo(&pst);
	makeinfo(&pst);
	showinfo(&pst);
	return 0;
}
void getinfo(struct namect * pst)
{
	printf("Pls enter you first name.\n");
	gets(pst->fname);
	printf("Pls enter you last name.\n");
	gets((*pst).lname);
}
void makeinfo(struct namect * pst)
{
	(*pst).letters=strlen((*pst).fname)+strlen(pst->lname);
}
void showinfo(const struct namect * pst)
{
	printf("you name is %s %s and have %d letters.\n",(*pst).fname,(*pst).lname,pst->letters);
}
