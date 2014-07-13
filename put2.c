#include<stdio.h>
int puts2(const char * string)
{
	int i=0;
	while(*string)
	{
		putchar(*string++);
		i++;
	}
	return i;
}
int main(void)
{
	char * pti = "gfedcba";
	printf("%d\n",puts2(pti));
	return 0;
}
