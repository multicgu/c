#include<stdio.h>
#include<memory.h>
#include<stdlib.h>
#include<string.h>
#define MAXBKS 10
#define MAXTITL 40
#define MAXAUTH 40
struct book {
	char title[MAXTITL];
	char author[MAXAUTH];
	float value;
};
int main(void)
{
	struct book library[MAXBKS];
	int filecount,n,size,count=0;
	int del[10]={0,0};
	size=sizeof(struct book);
	FILE * fp;
	if((fp=fopen("book.bat","r+b"))==NULL)
	{
		fprintf(stderr,"Fail to open the file.\n");
		exit(1);
	}
	rewind(fp);
	while(count<MAXBKS && fread(&library[count],size,1,fp)==1)
	{
		if(count==0)
			printf("book information.\nNum    Title   Author Value.\n");
		printf("%4d%10s%6s%6.2f.\n",count+1,library[count].title,library[count].author,library[count].value);
		count++;
	}
	if(count==MAXBKS)
		printf("The library is full.\n");
	if(count!=0)
	{
		printf("Which books you want to delete?(Enter the book number,Press q to exit.)");
		for(n=0;scanf("%d",&del[n])==1 && del[n]<=10 && n<MAXBKS;n++)
		{
			memset(&library[del[n]-1],0,sizeof(struct book));
			library[del[n]-1]=library[count-1];
			count--;
			/*strcpy(library[del[n]-1].title,"\0");
			strcpy(library[del[n]-1].author,"\0");
			library[del[n]-1].value=;*/
		}
		while(getchar()!='\n')
			continue;
	}
	filecount=count;
	/*printf("Add new book title(Press Enter at the start of a line to quit.)\n");
	printf("%d\n",del[0]);
	for(n=0;del[n]!=0 && gets(library[del[n]-1].title)!=NULL&&library[del[n]-1].title[0]!='\0';n++)
	{
		printf("Enter the Author.\n");
		gets(library[del[n]-1].author);
		printf("Enter the value.\n");
		scanf("%f",&library[del[n]-1].value);
		while(getchar()!='\n')
			continue;
		printf("Add new book title.\n");
	}*/
	//if(del[n]==0)
	//{ 
		printf("Add new book title(Press Enter at the start of a line to quit.)\n");
		while(filecount<MAXBKS && gets(library[filecount].title)!=NULL && library[filecount].title[0]!='\0') 
		{
			printf("Enter the Author.\n");
			gets(library[filecount].author);
			printf("Enter the value.\n");
			scanf("%d",&library[filecount].value);
			while(getchar()!='\n')
				continue;
			filecount++;
			printf("Add new book title.\n");
		}
	//}
	printf("book information.\nNum   Title   Author Value.\n");
	for(n=0;n<filecount;n++)
		printf("%4d%10s%6s%6.2f.\n",n+1,library[n].title,library[n].author,library[n].value);
	printf("count=%d fcount=%d\n",count,filecount);
	fclose(fp);
	if((fp=fopen("book.bat","w+b"))==NULL)
	{
		fprintf(stderr,"error to open file.\n");
		exit(1);
	}
	if(fwrite(library,size,filecount,fp)!=filecount)
	{
		fprintf(stderr,"error to write.\n");
		exit(1);
	}
	fclose(fp);
	printf("testtest\n");
		
	return 0;
}
