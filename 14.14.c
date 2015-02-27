#include<stdio.h>
#include<stdlib.h>
#define MAXTITL 40
#define MAXAUTH 40
#define MAXBKS 10
struct book {
	char title[MAXTITL];
	char author[MAXAUTH];
	double value;
};
int main(void)
{
	struct book library[MAXBKS];
	FILE * pbooks;
	int count=0;
	int index,filecount;
	int size=sizeof(struct book);
	if((pbooks=fopen("book.bat","a+b"))==NULL)
	{
		fputs("Can't open book.bat.\n",stderr);
		exit(1);
	}
	rewind(pbooks);
	while(count<MAXBKS && fread(&library[count],size,1,pbooks))
	{
		if(count==0)
			puts("Current content of book.bat");
		printf("%s by %s: $%.2f.\n",library[count].title,library[count].author,library[count].value);
		count++;
	}
	filecount=count;
	if(count==MAXBKS)
	{
		fputs("The book.dat file is full.\n",stderr);
		exit(2);
	}
	printf("Pls enter the new book titles(press ENTER at the start of a line to stop).\n");
	while(count<MAXBKS && gets(library[count].title) && library[count].title[0]!='\0')
	{
		printf("Enter the author.\n");
		gets(library[count].author);
		printf("Enter the value of the book.\n");
		fscanf(stdin,"%lf",&library[count++].value);
		while(getchar()!='\n')
			continue;
		if(count<MAXBKS)
			puts("Enter the next book title.");
	}
	if(count>0)
	{
		puts("Here is the list of you books: ");
		for(index=0;index<count;index++)
			printf("%s by %s: $%.2f.\n",library[index].title,library[index].author,library[index].value);
		fwrite(&library[filecount],size,count-filecount,pbooks);
	}
	else
		printf("No book,too bad.\n");
	puts("bye.");
	fclose(pbooks);
	return 0;
}
