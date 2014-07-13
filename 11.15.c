#include<stdio.h>
#include<string.h>
#define BUGSIZE 13
#define SIZE 30
int main(void)
{
	char flower[SIZE];
	char addon[] = "s smell like old shoes.";
	puts("What is your favorite flower?");
	gets(flower);
	if((strlen(addon)+strlen(flower)+1)<=SIZE)
		strcat(flower,addon);
	puts(flower);

	char bug[BUGSIZE];
	int i;
	puts("What is your favorite bug?");
	gets(bug);
	i=BUGSIZE-strlen(bug)-1;
	puts(strncat(bug,addon,i));
	puts(bug);

	return 0;
}
