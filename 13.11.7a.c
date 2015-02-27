#include<stdio.h>
#include<stdlib.h>
int main(int argc,char * argv[])
{
	FILE * fpa,* fpb;
	char cha[200], chb[200];
	printf("%s %s\n",argv[1],argv[2]);
	if(argc!=3)
	{
		fprintf(stderr,"Usage:%s [file1] [file2]\n",argv[0]);
		exit(1);
	}
	if(((fpa=fopen(argv[1],"r"))==NULL) || ((fpb=fopen(argv[2],"r"))==NULL))
	{
		fprintf(stderr,"Error to open the files.\n");
		exit(2);
	}
	while((fgets(cha,1000,fpa)!=NULL) && (fgets(chb,1000,fpb)!=NULL))
	{
		fputs(cha,stdout);
		fputs(chb,stdout);
	}

	return 0;
}
