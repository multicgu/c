#include<stdio.h>
#include<stdlib.h>
#include<math.h>
int main(void)
{
	int left,right,up,down;
	FILE * fp;
	int m,n;
	int a;
	int c=0;
	int intarr[22][32];
	if((fp=fopen("testtest","r"))==NULL)
	{
		fprintf(stderr,"Error to open.\n");
		exit(1);
	}
	for(n=1;n<21;n++)
	{
		for(m=1;m<31;m++)
		{
			if(fscanf(fp,"%d",&a)==1)
				intarr[n][m]=a;
			printf("%d",intarr[n][m]);
		}
		putchar('\n');
	}
	fclose(fp);
	for(n=1;n<21;n++)
	{
		for(m=1;m<31;m++)
		{
			a=4;
			printf("a ora=%d\n",a);
			left=right=up=down=0;
			if(n-1>0)
			{
				if(abs(intarr[n][m]-intarr[n-1][m])>1)	
					left=1;
			}else{left=1;intarr[n-1][m]=0;a--;}
			printf("a 1=%d\n",a);  //test
			if(n+1<=20)
			{
				if(abs(intarr[n][m]-intarr[n+1][m])>1)
					right=1;
			}else{right=1;intarr[n+1][m]=0;a--;}
			printf("a 2=%d\n",a);  //test
			if(m-1>0)
			{
				if(abs(intarr[n][m]-intarr[n][m-1])>1)
					up=1;
			}else{up=1;intarr[n][m-1]=0;a--;}
			printf("a 3=%d\n",a); //test
			if(m+1<=30)
			{
				if(abs(intarr[n][m]-intarr[n][m+1])>1)
					down=1;
			}else{down=1;intarr[n][m+1]=0;a--;}
			printf("a 4=%d\n",a); //test
				printf("n=%d m=%d\n",n,m); //test
				printf("%d %d %d %d %d %d\n",intarr[n-1][m],intarr[n+1][m],intarr[n][m-1],intarr[n][m+1],intarr[n][m],a); //test
			if(left==1 && right==1 && up==1 && down==1)	
			{
				intarr[n][m]=(int)((intarr[n-1][m]+intarr[n+1][m]+intarr[n][m-1]+intarr[n][m+1])/a);
				printf("%d %d %d %d %d %d\n",intarr[n-1][m],intarr[n+1][m],intarr[n][m-1],intarr[n][m+1],intarr[n][m],a); //test
				printf("n=%d m=%d\n",n,m); //test
				c++; //test
			}
		}
	}
		printf("\nchange\n");
		for(n=1;n<21;n++)
		{
			for(m=1;m<31;m++)
			{
				printf("%d",intarr[n][m]);
			}
			putchar('\n');
		}
	
	printf("c=%d\n",c);

	return 0;
}
