#include<stdio.h>
#include<string.h>
#define SIZE 80
int main(void)
{
	char flower[SIZE];
	char addon[] = "s smell like old shoes.";
	int i;
	puts(addon);
	puts("What's your favorite flower?");
	gets(flower);
	strcat(flower,addon);
	puts(flower);
	puts(addon);
	puts(strcat(flower,addon));
	puts(flower);

	return 0;
}
