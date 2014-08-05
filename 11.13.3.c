#include<stdio.h>
#define MAX 81
void gword(char []);
int main(void)
{
	char arr[MAX];
	gword(arr);
	puts(arr);

	return 0;
}
void gword(char string[])
{
	int n=0;
	puts("put some words.");
	gets(string);
	while(string[n])
	{
		if(string[n]==' ' || string[n]=='\t' || string[n]=='\n')
			string[n]='\0';
		n++;
	} 
	puts(string);
}
