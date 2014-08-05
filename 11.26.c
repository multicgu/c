//mod_str.c  modify a string.
#include<stdio.h>
//#include<string.h>
#include<ctype.h>
#define LIT 80
void ToUpper(char *);
int PunctCount(const char *);
int main(void)
{
	char str[LIT];
	int i;
	puts("Pls enter a line.");
	gets(str);
	ToUpper(str);
	puts(str);
	i=PunctCount(str);
	printf("That line has %d punctuation characters.\n",i);

	return 0;
}
void ToUpper(char * str)
{
	while(*str)
	{
		*str=toupper(*str);
		str++;
	}
}
int PunctCount(const char * str)
{
	int ct=0;
	while(*str)
	{
		if(ispunct(*str))
			ct++;
		str++;
	}
	return ct;
}
