#include<stdio.h>
#include<ctype.h>
#define MAX 81
int main(int argc,char *argv[])
{
	char string[MAX];
	int n=0;
	puts("Pls enter something.");
	gets(string);
	if(argv[1]==NULL)
		puts("Argument is null,Please enter argument.");
	else if(strcmp(argv[1],"-p")==0)
		puts(string);
	else if(strcmp(argv[1],"-u")==0)
		{
			while(string[n])
			{
				string[n]=toupper(string[n]);
				n++;
			}
			puts(string);
		}
	else if(strcmp(argv[1],"-l")==0)
	{
		while(string[n])
		{
			string[n]=tolower(string[n]);
			n++;
		}
		puts(string);
	}
	else if(strcmp(argv[1],"-p")!=0 && strcmp(argv[1],"-u")!=0 && strcmp(argv[1],"-l")!=0) 
		puts("Pls enter right argument.");
	return 0;
}
