#include<stdio.h>
void put1(const char * string)
{
	while(*string != '\0')	
		putchar(*string++);
}
int main(void)
{
	char line[8];
	char ch;
	printf("pls enter ch.\n");
	while((ch = getchar()) != EOF)
		putchar(ch);
	printf("pls enter line.\n");
	while(gets(line))
		puts(line);
		//put1(line);
	printf("pls enter name.\n");
	char name[81];
	while(fgets(name,81,stdin))
		fputs(name,stdout);

	return 0;
}
