#include<stdio.h>
#include<stdlib.h>
#define MAX 81
int main(void)
{
	int m,n;
	char ch;
	int a;
	int intarr[20][30];
	char charr[20][31];
	FILE * fp;
	FILE * chfp;
	if((fp=fopen("testtest","r"))==NULL)
	{
		fprintf(stderr,"Error to open the file.\n");
		exit(1);
	}
	for(n=0;n<20;n++)
	{
		for(m=0;m<30;m++)
		{
			if((fscanf(fp,"%d",&a))==1)
			{
				intarr[n][m]=a;
				printf("%d",intarr[n][m]);
			}
		}
		putchar('\n');	
	}
	for(n=0;n<20;n++)
	{
		for(m=0;m<31;m++)
		{
			if(m!=30)
			{
				switch(intarr[n][m])
				{
					case 0:ch=' '; break;
					case 1:ch='.'; break;
					case 2:ch=','; break;
					case 3:ch=':'; break;
					case 4:ch='~'; break;
					case 5:ch='*'; break;
					case 6:ch='"'; break;
					case 7:ch='$'; break;
					case 8:ch='%'; break;
					case 9:ch='#'; break;
				}
				charr[n][m]=ch;
			}
			else if(m==30)
			{
				charr[n][m]='\0';
			}
		}
	}
	if((chfp=fopen("13.11.12ch","w"))==NULL)
	{
		fprintf(stderr,"Error to open 13.11.12ch.\n");
		exit(1);
	}
	n=0;
	while(n<20)
	{
		fputs(charr[n],chfp);
		puts(charr[n]);
		n++;
	}

	fclose(fp);
	fclose(chfp);
	
	return 0;
}
