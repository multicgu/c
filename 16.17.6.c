#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define NUM 5
typedef struct 
{
	char first[10];
	char last[10];
}names;
int chcomp(const void * p1,const void * p2);
void show(const names * p,int n);
int main(void)
{
	names name[NUM];
	char temp[2][10];
	int n=0;
	puts("Enter you first and last name.");
	//while(scanf("%s%s",temp[0],temp[1])==2 )
	while(gets(temp[0])&&gets(temp[1])&&temp[0][0]!='\0')
	{
		strcpy(name[n].first,temp[0]);
		strcpy(name[n].last,temp[1]);
		n++;
	}
	puts("Show your enter.");
	show(name,n);
	puts("\nAfter sorting.");
	qsort(name,NUM,sizeof(name[0]),chcomp);
	show(name,n);
	return 0;
}
void show(const names * p,int n)
{
	int i=0;
	for(i=0;i<n;i++)	
		printf("%s %s\n",p[i].first,p[i].last);
}
int chcomp(const void * p1,const void * p2)
{
	names * a1=(names *)p1;
	names * a2=(names *)p2;
	int n=strcmp(a1->first,a2->first);
	if(n!=0)
		return n;
	else
		return strcmp(a1->last,a2->last);
}
