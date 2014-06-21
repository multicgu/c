#include<stdio.h>
void chline(char,int,int);
int main(void)
{
	char ch;
	int x,y;
	//int n;
	printf("enter char\n");
	while((ch=getchar()) == '\n' || ch == ' ' )
		continue;
	printf("ch = '%c'\n",ch);
	while(getchar() != '\n')
		continue;
	printf("enter 2 number\n");
	while(scanf("%d%d",&x,&y) != 2)
	{
		scanf("%*s");
		printf("Please enter 2 number:\n");
	}
	printf("ch = %c, x = %d,y = %d.\n",ch,x,y);
	chline(ch,x,y);
	return 0;
}

void chline(char ch,int x,int y)
{
	int n,m;
	for(n=1;n<=y;n++)
	{
		for(m=1;m<=x;m++)
			putchar(ch);
		putchar('\n');
	}
}
