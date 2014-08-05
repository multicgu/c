#include<stdio.h>
#define LIM 10
#define MAX 81
void ascchange(char *string[],int i);
void lensort(char *string[],int i);
void wordlensort(char *string[],int i);

int main(void)
{
	char string[LIM][MAX];
	char *temp[LIM];
	int i;
	int n;
	int a;
	int h;
	//get the 10 string.
	puts("Pls enter 10 strings,or enter EOF to stop.");
	for(i=0;i<LIM && gets(string[i]) && string[i][0]!=EOF;i++)
		continue;
	for(n=0;n<i;n++)
		temp[n]=string[n];
	puts("Enter the number of the follow list you want.");
	puts("1.puts the string you enter\t2.puts the string by ascII sort");
	puts("3.puts the string by length\t4.puts the string by word length");
	puts("5.quit");
	while(scanf("%d",&a)!='0' && a !=5 )
	{
		switch(a)
		{
			case 1:
				puts("Show the stirng");
				for(n=0;n<i;n++)
					puts(string[n]);
				break;

			case 2:
				puts("Show the stirng by the ascII sort.");
				ascchange(temp,i);
				for(n=0;n<i;n++)
					puts(temp[n]);
				break;

			case 3:
				puts("Show the string by the length sort.");
				lensort(temp,i);
				for(n=0;n<i;n++)
					puts(temp[n]);
				break;

			case 4:
				puts("Show the string by the word length sort.");
				wordlensort(temp,i);
				for(n=0;n<i;n++)
					puts(temp[n]);

			case 5:
				break;

			default:
				break;
		}
		//get the 10 string.
		while(h=getchar() !='\n' && h!=EOF)
			continue;
		puts("Pls enter 10 strings,or enter EOF to stop.");
		for(i=0;i<LIM && gets(string[i]) && string[i][0]!=EOF;i++)
			continue;
		for(n=0;n<i;n++)
			temp[n]=string[n];
		puts("Enter the number of the follow list you want.");
		puts("1.puts the string you enter\t2.puts the string by ascII sort");
		puts("3.puts the string by length\t4.puts the string by word length");
		puts("5.quit");
	}
	return 0;
}
void ascchange(char *string[],int i)
{
	//printf("i=%d\n",i);
	int n,m,o,p;
	char * temp;
	for(n=0;n<i-1;n++)
		for(m=n+1;m<i;m++)
		{
			if(strcmp(string[n],string[m])>0)
			{
				temp = string[n];
				string[n] = string[m];
				string[m] = temp;
			}
		}
	/*puts("test the arr value");
	o=0;
	while(o<i)
	{
		puts(string[o]);
		o++;
	}*/
}

void lensort(char *string[],int i)
{
	int m,n,o,p;
	char *temp;
	for(n=0;n<i-1;n++)
		for(m=n+1;m<i;m++)
		{
			for(o=0;string[n][o]!='\0';o++);
			for(p=0;string[m][p]!='\0';p++);
			if(o<p)
			{
				temp = string[n];
				string[n] = string[m];
				string[m] = temp;
			}
		}
}

void wordlensort(char *string[],int i)
{
	int m,n,o,p;
	char *temp;
	for(n=0;n<i-1;n++)
		for(m=n+1;m<i;m++)
		{
			for(o=0;string[n][o]!=' ' && string[n][o]!='\0';o++);
			for(p=0;string[m][p]!=' ' && string[m][p]!='\0';p++);
			if(o<p)
			{
				temp = string[n];
				string[n] = string[m];
				string[m] = temp;
			}
		}
}
