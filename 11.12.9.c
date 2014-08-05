#include<stdio.h>
int strle(char * string);
int main(void)
{
	char * str = "abcdefg";
	printf("%d\n",strle(str));
	return 0;
}
int strle(char * string)
{
	int i=0;
	while(*string)
	{
		i++;
		string++;
	}
	return i;
}
