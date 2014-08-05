#include<stdio.h>
#include<string.h>
#define MAX 81
char * Strncpy(char *,char *,int);
int main(void)
{
	char s1[MAX]="abcdefghijklmnopqrstuvwxyz";
	char s2[MAX];
	int n;
	puts("Enter the S2,the program will copy s2 to s1.(enter blank line to quit.)");
	while(gets(s2) && s2[0]!='\0')
	{
		puts("Enter the number of char in s2 you want to copy.");
		scanf("%d",&n);
		printf("New s1 is %s.\n",Strncpy(s1,s2,n));
		puts(s1);
		while(getchar()!='\n');
	puts("Enter the S2,the program will copy s2 to s1.(enter blank line to quit.)");
	}
	return 0;
}
char * Strncpy(char * s1,char * s2,int n)
{
	int i;
	for(i=0;i<n;i++)
		s1[i]=s2[i];
	if(strlen(s2)>=n)
		s1[n]='\0';
	return s1;
}
