#include<stdio.h>
#include<stdlib.h>
#define MAX 81 
int main(void)
{
	char file[MAX];
	char temp[MAX];
	FILE * fp;
	int row,col;
	int n=1;
	printf("Enter the file name.\n");
	scanf("%s",file);
	puts(file);
	if((fp=fopen(file,"r"))==NULL)
	{
		fprintf(stderr,"File %s can't be open.\n",file);
		exit(1);
	}
	printf("Enter the local of the file.(input the rows and columns.)\n");
	while(scanf("%d%d",&row,&col)==2)
	{
		printf("%d %d.\n",row,col);
		for(n=1;n<row;n++)
			fgets(temp,1000,fp);
		fseek(fp,col-1,SEEK_CUR);
		printf("tight");
		fgets(temp,1000,fp);
		printf("%s",temp);
		puts(temp);
		printf("Enter the local of the file.(rows and columns.)\n");
	}
	fclose(fp);

	return 0;
}
