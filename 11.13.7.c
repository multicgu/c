#include<stdio.h>
#include<string.h>
#define MAX 81
char * string_in(char *,char *);
int main(void)
{
	char a1[MAX];
	char a2[MAX];
	char * a;
	puts("Enter string s1,and enter a blank line to quit.");
	while(gets(a1) && a1[0]!='\0')
	{
		puts("Enter string s2,and the program will return the same string add.");
		gets(a2);
		a=string_in(a1,a2);
		printf("the same add is %p,and it's %s.\n",a,a);
		puts("Enter string s1,and enter a blank line to quit.");
	}
	return 0;
}
char * string_in(char * a1,char * a2)
{
	int i=0;
	int n=0;
	int len;
	while(a1[i])
	{
		if(a1[i]==a2[0])
		{
			len=strlen(a2);
			if(strncmp(&a1[i],a2,len)==0)
				return &a1[i];
		}
		i++;
	}
	return NULL;
}
