//atexit
#include<stdio.h>
#include<stdlib.h>
void sign_off(void);
void too_bad(void);
int main(void)
{
	int n;
	atexit(sign_off);
	printf("Enter a integer number.\n");
	if(scanf("%d",&n)!=1)
	{
		fprintf(stderr,"That's no integer.\n");
		atexit(too_bad);
		exit(EXIT_FAILURE);
	}
	printf("%d is %s.\n",n,(n%2)==0?"ever":"odd");

	return 0;
}
void sign_off(void)
{
	puts("Thus terminates another magnificent program from");
	puts("SeeSaw Software!");
}
void too_bad(void)
{
	puts("SeeSaw Software extends its heartfelt condolences");
	puts("to you upon the failure of your program.");
}
