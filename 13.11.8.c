#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int caldata(char , FILE *);
int main(int argc,char * argv[])
{
	FILE * fp;
	int n=0;
	int i;
	char  ch[10][10];
	if(argc<2)
	{
		fprintf(stderr,"Usage:%s [character] [file1] [file2] ..\n",argv[0]);
		exit(1);
	}
	else if(argc==2)
	{
		printf("Enter the file name.\n");
		while(scanf("%s",ch[n]))
		{
			n++;
			argc++;
			if(getchar()=='\n')
				break;
		}
		for(i=2;i<=n+2;i++)
		{
			argv[i]=ch[i-2];
		}
	}
	printf("argc=%d, argv[0]=%s, argv[1]=%s, argv[2]=%s, argv[3]=%s, argv[4]=%s, argv[5]=%s.\n",argc,argv[0],argv[1],argv[2],argv[3],argv[4],argv[5]);
		i=0;
		while((i+2)<argc)
		{
			if((fp=fopen(argv[i+2],"r"))==NULL)
				printf("File %s cannot be open.\n",argv[i+2]);
			else
			{
				printf("File %s include %d numbers %c.\n",argv[i+2],caldata(*argv[1],fp),*argv[1]);
				fclose(fp);
			}
			i++;
		}
	return 0;
}
int caldata(char n,FILE * fp)
{
	char ch;
	int i=0;
	while((ch=getc(fp))!=EOF)
		if(ch==n)
			i++;
	return i;
}
