//reverse.c 
#include<stdio.h>
#include<stdlib.h>
#define SLEN 50
int main(void)
{
	FILE * fb;
	char file[SLEN];
	long count,last;
	char ch;
	printf("Please enter the name of the file to be processed: ");
	gets(file);
	if((fb=fopen(file,"rb"))==NULL)
	{
		fprintf(stderr,"cannot open the file %s.\n",file);
		exit(1);
	}
	fseek(fb,0L,SEEK_END);
	last=ftell(fb);
	for(count=1L;count<=last;count++)
	{
		fseek(fb,-count,SEEK_END);
		ch = getc(fb);
		putc(ch,stdout);
	}

	return 0;
}
