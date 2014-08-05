#include<stdio.h>
#define MAX 81
int is_within(char,char *);
int main(void)
{
	char arr[MAX];
	char ch;
	puts("Pls enter a string.Enter a blank line to quit.");
	while(gets(arr) && arr[0]!='\0')
	{
		puts("Pls enter a char.");
		int a;
		ch= getchar();
		a = is_within(ch,arr);
		printf("return %d\n",a);
		if(a==0)
			printf("%c is not in the %s\n",ch,arr);
		else
			printf("%c is in the %s\n",ch,arr);
		while(getchar()!='\n' );
		puts("Pls enter a string.Enter a blank line to quit.");

	}
	return 0;
}
int is_within(char ch,char *string)
{
	int n=0;
	while(string[n])
	{
		if(string[n] == ch)
			return 1;
		n++;
	}
	return 0;
}
