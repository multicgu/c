//reducto.c  --压缩文件为原来的3/1;
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#define LEN 40
int main(int argc,char * argv[])
{
	FILE * a;
	FILE * b;
	char name[LEN];
	char ch;
	int count=0;
	if(argc<2)
	{
		fprintf(stderr,"Usage: %s filename.\n",argv[0]);
		exit(1);
	}
	if((a=fopen(argv[1],"r"))==NULL)
	{
		fprintf(stderr,"%s could not be open.\n",argv[1]);
		exit(2);
	}
	strcpy(name,argv[1]);
	strcat(name,".red");
	if((b=fopen(name,"w"))==NULL)
	{
		fprintf(stderr,"file %s could not be created.\n",name);
		exit(3);
	}
	while((ch=getc(a))!=EOF)
		if((count++)%3==0)
			putc(ch,b);
	if(fclose(a)==EOF || fclose(b)!=0)
		fprintf(stderr,"Error in closeing files\n");

	return 0;
}
