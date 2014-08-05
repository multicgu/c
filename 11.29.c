#include<stdio.h>
#include<stdlib.h>
int main(void)
{
	char number[30];
	char * end;
	long n;
	
	puts("Enter a number(empty line to quit):");
	while(gets(number) && number[0]!='\0')
	{
		n=(strtol(number,&end,10));
		printf("vaule=%ld,stopped at %s(%d)\n",n,end,*end);
		n=(strtol(number,&end,16));
		printf("vaule=%ld,stopped at %s(%d)\n",n,end,*end);
		puts("Next number: ");
	}
	puts("bye!");
	return 0;
}
