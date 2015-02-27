//append.c  
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define BUFSIZE 1024
#define SLEN 81
void append(FILE * dest,FILE * source);
int main(void)
{
	FILE * fa,* fs;
	char file_app[SLEN];
	char file_src[SLEN];
	int files=0; //the number of the add files;
	printf("Pls enter the destination file: ");
	gets(file_app);
	if((fa=fopen(file_app,"a"))==NULL)
	{
		fprintf(stderr,"Cannot open the file %s.\n",file_app);
		exit(1);
	}
	if(setvbuf(fa,NULL,_IOFBF,BUFSIZE)!=0)
	{
		fputs("Can't create output buffer\n",stderr);
		exit(2);
	}
	puts("Enter name of first source file(empty line to quit): ");
	while(gets(file_src) && file_src[0]!='\0')
	{
		if(strcmp(file_app,file_src)==0)
			fputs("Can't append the same file to itself.\n",stderr);
		else if((fs=fopen(file_src,"r"))==NULL)
			fprintf(stderr,"Can't open the file %s\n",file_src);
		else
		{
			if(setvbuf(fs,NULL,_IOFBF,BUFSIZE)!=0)
			{
				fputs("Can't create input buffer.\n",stderr);
				continue;
			}
			append(fa,fs);
			if(ferror(fs)!=0)
				fprintf(stderr,"File %s reading error.\n",file_src);
			if(ferror(fa)!=0)
				fprintf(stderr,"File %s reading error.\n",file_app);
			fclose(fs);
			files++;
			printf("File %s appended.\n",file_src);
		}
		puts("Next file(emtpy line to quit): ");
	}
	printf("Done. %d files append.\n",files);
	fclose(fa);

	return 0;
}
void append(FILE * dest,FILE * source)
{
	static char temp[BUFSIZE];
	int n;
	while((n=fread(temp,sizeof(char),BUFSIZE,source))>0)
		fwrite(temp,sizeof(char),n,dest);
}
