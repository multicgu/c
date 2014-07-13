#include<stdio.h>
void fit(char * string,int i);
int main(void)
{
	char string[] = "abcdef";
	//char * string = "abcdef";
	puts(string);
	//*(string+3) = '\0';
	fit(string,3);
	puts(string);
	puts(string+4);
	return 0;
}
void fit(char * string,int i)
{
	*(string+i)='\0';
}
