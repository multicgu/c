//count.c
#include<stdio.h>
#include<stdlib.h>
int main(int argc,char * argv[])
{
	int count=0;
	int ch;
	FILE * fp;
	if(argc!=2)
	{
		printf("Usage: %s filenames\n",argv[0]);
		exit(1);
	}
	if((fp=fopen(argv[1],"r"))==NULL)
	{
		printf("The file %s cannot be open.\n",argv[1]);
		exit(1);
	}
	while((ch=getc(fp))!=EOF)
	{
		putc(ch,stdout);
		count++;
	}
	if(fclose(fp)==EOF)
		printf("The file %d cannot be close normal.\n",argv[1]);
	printf("The file %s have %d characters.\n",argv[1],count);

	return 0;
}
