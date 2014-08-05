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
	int i;
	while(getchar()!='\n');
	gets(string);
	for(i=0;i<n;i++)
	{
		if(string[i]==' ' || string[i]=='\t'||string[i]=='\n')
			string[i]='\0';
	}
	string[n] = '\0';
}
