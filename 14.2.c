//manybook.c
#include<stdio.h>
//#include<math.h>
//double dummy = sin(0.0);
#define MAXTITL 40
#define MAXAUTH 30
#define MAXBKS 100
struct book {
	char title[MAXTITL];
	char author[MAXAUTH];
	float value;
};
int main(void)
{
	struct book library[MAXBKS];
	int count=0;
	int n;
	printf("Enter the book title.");
	printf("Press [Enter] at the start of a line to stop.\n");
	while(count<MAXBKS && gets(library[count].title)!=NULL && library[count].title[0]!='\0')
	{
		printf("Enter the book author.\n");
		gets(library[count].author);
		printf("Enter value of the book.\n");
		scanf("%f",&library[count++].value);
		while(getchar()!='\n')
			continue;
		if(count<MAXBKS)
			printf("Enter the next book title.\n");
	}
	if(count>0)
		for(n=0;n<count;n++)
			printf("%s by %s: $%.2f.\n",library[n].title,library[n].author,library[n].value);
	else
		printf("No books.Too bad.\n");	
	return 0;
}
