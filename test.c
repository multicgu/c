#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int main(void)
{
	int n;
	char a[2];
	char *d=a;
	char *b="abc";
	n=strcmp(d,b);
	printf("%d\n",n);
	return 0;
}
