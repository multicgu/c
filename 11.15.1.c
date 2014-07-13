#include<stdio.h>
#include<string.h>
int main(void)
{
	char addon[]= "abcdefg";
	char base[] = "ABCDEFG";
	printf("%d\n",strlen(addon));
	//strncat(addon,base,5);
	strcat(addon,base);
	puts(addon);
	printf("%d\n",strlen(addon));
	puts(addon);
	//puts(base);

	return 0;
}
