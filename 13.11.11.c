#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define NAMEMAX 30
#define MAX 81
int main(int argc,char * argv[])
{
	FILE * fp;
	char temp[MAX];
	char * show;
	if(argc!=3)
	{
		fprintf(stderr,"Usage:%s [string] [filename]\n",argv[0]);
		exit(1);
	}
	if((fp=fopen(argv[2],"r"))==NULL)
	{
		fprintf(stderr,"File %s cannot be open.\n");
		exit(1);
	}
	while(fgets(temp,MAX,fp)!=NULL)
	{
		if((show=strstr(temp,argv[1]))!=NULL)
		{
			puts(show);
			puts(temp);
		}
	}
	fclose(fp);

	return 0;
}
