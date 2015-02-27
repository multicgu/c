#include<stdio.h>
#define MAX 20
int main(void)
{
	char ch[MAX];
	while(fgets(ch,MAX,stdin)!=NULL && ch[0]!='\n')
		fputs(ch,stdout);

	//putc(ch[19],stdout);
	putchar(ch[18]);
	if(ch[19]=='\0')
		printf("right.\n");

	return 0;
}
