#include<stdio.h>
#include<stdlib.h>
int main(int argc,char * argv[])
{
	printf("argc=%d,argv[0]=%s,argv[1]=%s,argv[2]=%s\n",argc,argv[0],argv[1],argv[2]);
	int i;
	double f,n;
	n=atof(argv[1]);
	i=atoi(argv[2]);
	printf("n=%f i=%d\n",n,i);
	int count;
	if(i>0)
	{
		for(f=1.0,count=1;count<=i;count++)
			f*=n;
	}
	else if(i==0)
	{
		f=1;
	}
	else if(i<0)
	{
		for(f=1.0,count=-1;count>=i;count--)
		{
			printf("%d\n",count);
			f*=n;
		}
		f=1/f;
	}
	printf("The answer is %f\n",f);
	return 0;
	
}
