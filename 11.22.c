#include<stdio.h>
#include<string.h>
#define SIZE 30
#define WORD "beast"
int main(void)
{
	char copy[SIZE]="Be the best that you can be.";
	puts(copy);
	char * ps;
	ps = strcpy(&copy[7],WORD);
	puts(copy);
	puts(ps);

	return 0;
}
