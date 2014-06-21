#include<stdio.h>
#include<string.h>
#define NAME "GIGATHINK.INC. "
#define ADRESS "101 Megabuck Plaza"
#define PLACE "Megapolis, CA 94904"
#define WIDTH 40
#define SPACE ' '

void show_n_char(char ch,int num);
int main(void)
{
	int space;
	show_n_char('*',WIDTH);
	putchar('\n');
	show_n_char(SPACE,12);
	printf("%s\n",NAME);
	space = (WIDTH-strlen(ADRESS)) / 2;
	show_n_char(SPACE,space);
	printf("%s\n",ADRESS);
	space = (WIDTH - strlen(PLACE)) / 2;
	show_n_char(SPACE,space);
	printf("%s\n",PLACE);
	show_n_char('*',WIDTH);
	putchar('\n');

	return 0;
}

void show_n_char(char ch,int num)
{
	int i;
	for(i=1;i<=num;i++)
		putchar(ch);
}
