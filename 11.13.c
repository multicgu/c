#include<stdio.h>
#include<string.h>
void fit(char * string,unsigned int i);
int main(void)
{
	char string[] = "Hold on to your hats, hackers. ";
	puts(string);
	fit(string,7);
	puts(string);
	puts("Let's look at some more of the string. ");
	puts(string+8);

	return 0;
}
void fit(char * string,unsigned int i)
{
	//if(strlen(string)>i)
		*(&string[0]+i)='\0';
}
