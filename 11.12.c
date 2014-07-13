#include<stdio.h>
void put1(char *);
int put2(char *);
int main(void)
{
	put1("If I'd as much money");
	put1(" as I could spend, \n");
	printf("I count %d characters.\n",put2("I never would cry old chairs to mend. "));

	return 0;
}
void put1(char * string)
{
	while(*string)
		putchar(*string++);
}
int put2(char * string)
{
	int i;
	while(*string)
	{
		putchar(*string++);
		i++;
	}
	putchar('\n');
	return i;
}
