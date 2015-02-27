//ungetc();
#include<stdio.h>
int main(void)
{
	FILE * fb;
	char ch;
	char a[40];
	fb=fopen("eddy","r+");
	while((ch=getc(fb))!='y')
		putc(ch,stdout);
	ungetc('y',fb);
	putc('\n',stdout);
	fgets(a,40,fb);
	fputs(a,stdout);

	return 0;
}
