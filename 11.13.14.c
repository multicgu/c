#include<stdio.h>
#define MAX 81
int chtoi(char *ch);
int main(void)
{
	char str[MAX];
	int n;
	puts("Enter");
	gets(str);
	puts("Change the digit char in str to digit.");
	n=chtoi(str);
	printf("n=%d\n",n);
	return 0;
}
int chtoi(char *ch)
{
	int n=0;
	while(*ch)
	{
		if(isdigit(*ch))
		{
			n=n*10+(*ch-'0');
			ch++;
		}
		else
			break;
	}
	return n;
}
