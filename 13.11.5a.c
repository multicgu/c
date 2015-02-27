#include<stdio.h>
#include<stdlib.h>
#include<string.h>
void append(FILE * ,FILE * );
int main(int argc,char * argv[])
{
	FILE * fpsrc,* fpdest;
	if(argc!=3)
	{
		fprintf(stderr,"Usage:%s [source file] [destination file]",argv[0]);
		exit(1);
	}
	else if(strcmp(argv[1],argv[2])==0)
	{
		fprintf(stderr,"you enter the same file.\n");
		exit(2);
	}
	if((fpsrc=fopen(argv[1],"rb"))==NULL)
	{
		fprintf(stderr,"file %s cannot be open.\n",argv[1]);
		exit(3);
	}
	if(setvbuf(fpsrc,NULL,_IOFBF,1024)!=0)
	{
		fprintf(stderr,"Cannot create src buffer.\n");
		exit(4);
	}
	if((fpdest=fopen(argv[2],"ab"))==NULL)
	{
		fprintf(stderr,"file %s cannot be open.\n",argv[2]);
		exit(5);
	}
	else if((setvbuf(fpdest,NULL,_IOFBF,1024))!=0)
	{
		fprintf(stderr,"Cannot create dest buffer.\n");
		exit(6);
	}
	else
	{
		append(fpsrc,fpdest);
		if(ferror(fpsrc)!=0)
			fprintf(stderr,"Error in reading file %s.\n",argv[1]);
		if(ferror(fpdest)!=0)
			fprintf(stderr,"Error in reading file %s.\n",argv[2]);
	}
	fclose(fpsrc);
	fclose(fpdest);

	return 0;
}
void append(FILE * fpsrc,FILE * fpdest)
{
	int n;
	char ch[128];
	while((n=fread(ch,sizeof(char),128,fpsrc))>0)
		fwrite(ch,sizeof(char),n,fpdest);
}
