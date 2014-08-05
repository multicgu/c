#include<stdio.h>
#include<string.h>
#define MAX 81
void delsp(char *);
int main(void)
{
	char string[MAX];
	puts("Enter the string and this program will del the space.(enter the blank line to quit.)");
	while(gets(string) && string[0]!='\0')
	{
		delsp(string);
		puts(string);
		puts("Enter the string and this program will del the space.(enter the blank line to quit.)");
	}
	return 0;
}
void delsp(char * string)
{
	int n=0;
	int i;
	int m;
	i=strlen(string);
	while(string[n])
	{
		if(string[n]==' ')
		{
			m=n;
			while(m<=i)
			{
				string[m]=string[m+1];
				m++;
			}
			n--;
		}
		n++;
	}
}
