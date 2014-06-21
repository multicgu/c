#include<stdio.h>
#include<ctype.h>
int letter(char);
int main(void)
{
	char a;
	printf("Please enter a letter.\n");
	while(scanf("%c",&a) != EOF)
	{
		printf("%c is %d\n",a,letter(a));
	}
	return 0;
}

int letter(char a)
{
	if(isalpha(a))
	{
		if(islower(a))
			return (a-96);
		if(isupper(a))
			return (a-64);
	}
	else
		return -1;
}
