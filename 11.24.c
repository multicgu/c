#include<stdio.h>
#define MAX 20
int main(void)
{
	char first[MAX];
	char last[MAX];
	double prize;
	char format[2*MAX+10];
	puts("Pls enter your first name: ");
	gets(first);
	puts("Pls enter your last name: ");
	gets(last);
	puts("Enter your prize money: ");
	scanf("%lf",&prize);
	sprintf(format,"%s %-19s: $%6.2f\n",last,first,prize);
	puts(format);

	return 0;
}
