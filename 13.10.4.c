#include<stdio.h>
#include<stdlib.h>
int main(int argc,char * argv[])
{
	int count=0;
	char * file;
	double num,sum;
	FILE * fp;
	if(argc==1)
		fp=stdin;
	else if(argc==2)
	{
		if((fp=fopen(argv[1],"r"))==NULL)
			fprintf(stderr,"Failed to open %s.\n",argv[1]);
		exit(1);
	}
	else
	{
		fprintf(stderr,"Usage: %s [filename]\n",argv[0]);
		exit(2);
	}
	while(fscanf(fp,"%lf",&num)==1)	
	{
		sum+=num;
		count++;
	}
	if(count>0)
		printf("The average of the num is %f\n",sum/count);
	else
		printf("No num to cal.\n");

	return 0;
}
