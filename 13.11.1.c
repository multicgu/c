#include<stdio.h>
#include<stdlib.h>
int main(void)
{
	char ch;
	int count=0;
	char *file;
	FILE * fp;
	printf("Pls enter the file name: ");
	gets(file);
	if((fp=fopen(file,"r"))==NULL)
	{
		fprintf(stderr,"File %s can't be open.\n",file);
		exit(1);
	}
	while((ch=getc(fp))!=EOF)
	{
		putc(ch,stdout);
		count++;
	}
	fclose(fp);

	return 0;
}
