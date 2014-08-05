#include<stdio.h>
#include<string.h>
#include<ctype.h>
#define ANSWER "GRANT"
#define MAX 40
void Toupper(char *);
int main(void)
{
	char try[MAX];
	char a = 'c';
	puts("Who is buried in Grant's tomb?");
	gets(try);
	Toupper(try);
	puts(try);
	while(strcmp(try,ANSWER))  // strcmp > string compare
	{
		puts("No, that's wrong, Try again.");
		gets(try);
		Toupper(try);
		puts(try);
	}
	puts("That's right!");

	return 0;
}
void Toupper(char * string)
{
	while(*string)
	{
		*string=toupper(*string);
		string++;
	}
}
