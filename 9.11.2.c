#include<stdio.h>
void chline(char ch,int i,int j);
int main(void)
{
	int i,j;
	char ch = 'a';
	while(scanf("%d%d",&i,&j) != 2)
	{
		scanf("%*s");
		printf("Please enter integer number:\n");
	}
	chline(ch,i,j);

	return 0;
}

void chline(char ch,int i,int j)
{
	int n;
	for(n=1;n<i;n++)
		putchar(' ');

	for(n=i;n<=j;n++)
		putchar(ch);
	putchar('\n');
}
