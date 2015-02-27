#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define MAXLINE 256
int main(int argc,char * argv[])
{
	char ch[MAXLINE];
	int i;
	FILE * fp;
	if(argc!=3)
	{
		fprintf(stderr,"Usage:%s [character] [filename]\n",argv[0]);
		exit(1);
	}
	else if(argv[1][1]!='\0')
		fprintf(stderr,"the \'%s\' your enter invalid,just first char \'%c\' be used.\n",argv[1],argv[1][0]);
	if((fp=fopen(argv[2],"r"))==NULL)
	{
		fprintf(stderr,"Can't open the file %s\n",argv[2]);
		exit(2);
	}
	while(fgets(ch,MAXLINE,fp)!=NULL)
	{
		if(strrchr(ch,argv[1][0])==NULL)  //strrchr返回参数1字符串里参数2字符所在的地址，如果不包含返回NULL；
			continue;
		else
			fputs(ch,stdout);
	}

	return 0;
}
