#include<stdio.h>
#define MAX 81
char * stringchar(char *,char);
int main(void)
{
	char string[MAX];
	char n;
	int i=0;
	char ch;
	puts("Pls enter a string.");
	puts("Enter a blank line to stop.");
	while(gets(string) && string[0] != '\0')
	{
		//while(getchar() != '\n');
		puts("Enter a character and I will seach the string you enter.");
		scanf("%c",&ch);
		printf("%c\n",ch);
		for(i=0;string[i];i++)
			printf("add string[%d]=%p\n",i,&string[i]);
		printf("The char is %c,the add is %p.\n",*stringchar(string,ch),stringchar(string,ch));
		while((n=getchar())!='\n' && n!=EOF);
		puts("Pls enter a string.");
		puts("Enter a blank line to stop.");
	}

	return 0;
}
char * stringchar(char * string,char ch)
{
	int n=0;
	while(string[n])
	{
		if(string[n] == ch)
			return &string[n];
		n++;
	}
	return &string[n];
}
