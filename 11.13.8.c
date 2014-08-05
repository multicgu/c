#include<stdio.h>
#include<string.h>
#define MAX 81
void antitone(char *);
int main(void)
{
	char arr[MAX];
	puts("Enter a string,this program will antitone it.");
	while(gets(arr) && arr[0]!='\0')
	{
		puts(arr);
		antitone(arr);
		puts("After antitone");
		puts(arr);
		puts("Enter a string,this program will antitone it.");
	}
	return 0;
}
void antitone(char * arr)
{
	int n;
	int i=0;
	char string[MAX];
	strcpy(string,arr);
	puts(string);
	n=strlen(string);
	printf("%d\n",n);
	while(n>0)
	{
		arr[i]=string[n-1];
		i++;
		n--;
	}
}
