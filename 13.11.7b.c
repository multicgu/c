#include<stdio.h>
#include<stdlib.h>
#define SIZE 200
char * funputs(char * ch,FILE * fp);
int main(int argc,char * argv[])
{
	char ch1[SIZE],ch2[SIZE],temp[SIZE];
	char ch;
	FILE * fp1,*fp2;
	if(argc!=3)
	{
		fprintf(stderr,"Usage:%s [file1] [file2] \n",argv[0]);
		exit(1);
	}
	if(((fp1=fopen(argv[1],"r"))==NULL) || ((fp2=fopen(argv[2],"r"))==NULL))
	{
		fprintf(stderr,"Error to open files.\n");
		exit(1);
	}
	while(((funputs(ch1,fp1)!=NULL)) && ((fgets(ch2,SIZE,fp2)!=NULL)))
	{
		fputs(ch1,stdout);
		fputs(ch2,stdout);
	}
	fclose(fp1);fclose(fp2);

	return 0;
}
char * funputs(char * ch,FILE * fp)
{
	char c;
	int n;
	for(n=0;(c=getc(fp))!='\n';n++)
	{
		if(c==EOF)
		{
	//		printf("eof\n");
			return NULL;
		}
		ch[n]=c;
	}
	/*if(c==EOF)
	{
		printf("eof\n");
		return NULL;
	}*/
	return ch;
}
