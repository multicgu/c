#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define SIZE 81
int main(void)
{
	char file[SIZE],temp[SIZE];
	FILE * fp,* ftemp;
	char ch;
	int count=0;
	printf("This progrem will compress 1/3 size of file that you enter.\n");
	printf("Enter the file: ");
	scanf("%s",file);
	strcpy(temp,file);
	strcat(temp,".red");
	if((fp=fopen(file,"r"))==NULL)
	{
		fprintf(stderr,"File %s cannot be open.\n",file);
		exit(1);
	}
	if((ftemp=fopen(temp,"w"))==NULL)
	{
		fprintf(stderr,"File %s cannot be open.\n",temp);
		exit(2);
	}
	while((ch=getc(fp))!=EOF)
		if((++count)%3==1)
			putc(ch,ftemp);
	if(fclose(fp)!=0 || fclose(ftemp)!=0)
		fprintf(stderr,"Error in closing files.\n");

	return 0;
}
