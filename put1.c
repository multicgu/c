#include<stdio.h>
void put1(const char * string)
{
	while(*string)
		putchar(*string++);
}
int main(void)
{
	char arr[81];
	gets(arr);
	put1(arr);
	return 0;
}
