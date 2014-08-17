#include<stdio.h>
#include<ctype.h>
#include<stdbool.h>
#define MAX 81
int words(char * string);
int IsUpper(char * string);
int IsLower(char * string);
int IsPunct(char * string);
int IsDigit(char * string);
int main(void)
{
	int n;
	int i;
	char arr[MAX];
	puts("Enter a sentence.");
	while(gets(arr) && *arr!=EOF)
	{
		printf("the sentence have %d words.\n",words(arr));
		printf("The sentence have %d upper letters.\n",IsUpper(arr));
		printf("The sentence have %d lower letters.\n",IsLower(arr));
		printf("The sentence have %d punctuations.\n",IsPunct(arr));
		printf("The sentence have %d digits.\n",IsDigit(arr));
		
		puts("Enter a sentence.");
	}
	return 0;
}
int words(char * string)
{
	int n;
	int i=0;
	bool b;
	//while(arr[n]!=EOF)
	for(n=0;string[n]!='\0' /*&& string[n]!=EOF*/;n++)
	{
		if(string[n]==' ')
			b = false;
		else
		{
			if(b == false)
				i++;
			b=true;
		}
	}
	return i;
}
int IsUpper(char * string)
{
	int n;
	int i=0;
	for(n=0;string[n]!='\0';n++)
		if(isupper(string[n]))
			i++;
	return i;
}
int IsLower(char * string)
{
	int n;
	int i=0;
	for(n=0;string[n]!='\0';n++)
		if(islower(string[n]))
			i++;
	return i;
}
int IsPunct(char * string)
{
	int n;
	int i=0;
	for(n=0;string[n]!='\0';n++)
		if(ispunct(string[n]))
			i++;
	return i;
}
int IsDigit(char * string)
{
	int n;
	int i=0;
	for(n=0;string[n]!='\0';n++)
		if(isdigit(string[n]))
			i++;
	return i;
}
