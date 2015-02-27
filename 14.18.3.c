#include<stdio.h>
#define MAXAUTL 40
#define MAXTITL 40
struct book {
	char title[MAXTITL];
	char author[MAXAUTL];
	float value;
};
void showtitle(struct book *,int);
void sorttitle(struct book *,int);
void sortvalue(struct book *,int);
int main(void)
{
	int n=0;
	int i=0;
	struct book books[10];
	printf("Enter title of the book.(press enter to exit at the start of a line)\n");
	while(n<10 && gets(books[n].title)!=NULL && books[n].title[0]!='\0')
	{
		printf("Enter the author of the book.\n");
		gets(books[n].author);
		printf("Enter the value of the book.\n");
		scanf("%f",&books[n].value);
		while(getchar()!='\n')
			continue;
		n++;
		if(n<10)
			printf("Enter the next book title.\n");
	}
	printf("Show the title of the book.\n");
	showtitle(books,n);
	printf("\nShow the title of the book after sort.\n");
	sorttitle(books,n);
	printf("\nShow the value of the book after sort.\n");
	sortvalue(books,n);

	return 0;
}
void showtitle(struct book * books,int n)
{
	int i;
	for(i=0;i<n;i++)
		printf("%s\n",books[i].title);
}
void sorttitle(struct book books[],int n)
{
	struct book temp;
	int i,a,b;
	for(a=0;a<n-1;a++)
		for(b=a+1;b<n;b++)
		{
			if(books[a].title[0]-books[b].title[0]>0)
			{
				temp=books[a];
				books[a]=books[b];
				books[b]=temp;
			}
		}
	for(i=0;i<n;i++)
		printf("%s\n",books[i].title);
}
void sortvalue(struct book * books,int n)
{
	int i,a,b;
	struct book temp;
	float tmp;
	for(a=0;a<n-1;a++)
		for(b=a+1;b<n;b++)
			if(books[a].value-books[b].value>0)
			{
				tmp=books[a].value;
				books[a].value=books[b].value;
				books[b].value=tmp;
			}
	for(i=0;i<n;i++)
		printf("%s %f\n",books[i].title,books[i].value);
}
