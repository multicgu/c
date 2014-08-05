#include<stdio.h>
void gch(int n,char []);
int main(void)
{
	char arr[81];
	int n;
	puts("Please enter the number of characters you wanna type.");
	scanf("%d",&n);
	printf("Please enter %d number of characters.\n",n);
	gch(n,arr);
	puts(arr);
	return 0;
}
void gch(int n,char string[])
{
	while(getchar()!='\n');
	gets(string);
	string[n] = '\0';
}
