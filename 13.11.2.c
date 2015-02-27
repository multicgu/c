#include<stdio.h>
#include<stdlib.h>
#define MAX 81
int main(void)
{
	char src[MAX],dest[MAX];
	FILE * fpsrc;
   	FILE * fpdest;
	char temp[1000];
	char ch;
	int n;
	printf("Enter the the source file and destination file: ");
	fscanf(stdin,"%s%s",src,dest); // change1;
	printf("%s\n%s\n",src,dest);
	if((fpsrc=fopen(src,"rb"))==NULL)
	{
		fprintf(stderr,"file %s cannnot be open.\n",src);
		exit(1);
	}
	printf("right\n");
	if((fpdest=fopen(dest,"wb"))==NULL)
	{
		fprintf(stderr,"file %s cannot be open.\n",dest);
		exit(2);
	}
	/*while(ch=getc(fpsrc)!=EOF)
	{
		putc(ch,fpdest);
	}*/
	while(n=(fread(temp,sizeof(char),10,fpsrc)>0))
	{
		fwrite(temp,sizeof(char),10,fpdest);
		printf("%s",temp);
	}
	// change 2;
	fclose(fpsrc);
	fclose(fpdest);

	return 0;
}
