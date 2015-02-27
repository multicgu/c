//randbin.c  
#include<stdio.h>
#include<stdlib.h>
#define ARSIZE 1000
int main(void)
{
	const char * file = "number.dat";
	double num[ARSIZE];
	double value;
	int n;
	FILE * infb;
	for(n=0;n<ARSIZE;n++)
		num[n]=(double)n*100.0+1.00/(n+1);
	if((infb=fopen(file,"wb"))==NULL)
	{
		fprintf(stderr,"file %s open failed.\n",file);
		exit(1);
	}
	fwrite(num,sizeof(double),ARSIZE,infb);
	if((fclose(infb))!=0)
		fprintf(stderr,"The file %s close error.\n",file);
	if((infb=fopen(file,"rb"))==NULL)
	{
		fprintf(stderr,"The file %s open error.\n",file);
		exit(1);
	}
	printf("Enter an index in the range 0-%d.\n",ARSIZE-1);
	scanf("%d",&n);
	while(n>=0 && n<ARSIZE)
	{
		fseek(infb,(long)n*sizeof(double),SEEK_SET);
		fread(&value,sizeof(double),ARSIZE,infb);
		printf("The valuse you want is %f.\n",value);
		printf("Next index (out of range to quit)\n");
		scanf("%d",&n);
	}
	fclose(infb);
	printf("Bye!\n");

	return 0;
}
