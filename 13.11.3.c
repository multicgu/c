#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
#define MAX 81
int main(void)
{
	char src[MAX],dest[MAX];
	int ch;
	FILE *fpsrc,*fpdest;
	printf("Enter the srource file and the dentination file.\n");
	if(fscanf(stdin,"%s%s",src,dest)!=2)
	{
		printf("Enter file name failed.\n");
		exit(1);
	}
	printf("%s %s\n",src,dest);
	if((fpsrc=fopen(src,"r"))==NULL)
	{
		fprintf(stderr,"file %s cannot be open.\n",src);
		exit(1);
	}
	if((fpdest=fopen(dest,"w"))==NULL)
	{
		fprintf(stderr,"file %s cannot be open.\n",dest);
		exit(1);
	}
	while((ch=getc(fpsrc))!=EOF)
	{
		printf("%c",ch);
		ch=toupper(ch);
		//printf("%c",ch);
		putc(ch,fpdest);
	}
	fclose(fpsrc);
	fclose(fpdest);

	return 0;
}
