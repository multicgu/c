#include<stdio.h>
#include<stdlib.h>
int main(int argc,char * argv[])
{
	int n=0;
	FILE * fp;
	char ch[1000];
	for(n=1;n<argc;n++)
	{
		if((fp=fopen(argv[n],"r"))==NULL)
		{
			fprintf(stderr,"file %s cannot be open.\n",argv[n]);
			exit(1);
		}
		printf("%s\n",argv[n]);
		while((fgets(ch,1000,fp))!=NULL)
			fputs(ch,stdout);
		fclose(fp);
	}
	return 0;
}
