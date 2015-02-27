#include<stdio.h>
int main(void)
{
	int a;
	char ch[1024];
	FILE * eddy,* temp;
	char * var;
	while(gets(var)&& var[0]!='\0')
	{
		eddy=fopen(var,"r");
		temp=fopen("temp","a");
		char * chr;
		while((a=fread(ch,sizeof(char),1024,eddy))>0)
		{
			printf("a = %d\n",a);
			fwrite(ch,sizeof(char),a,temp);
		}
			printf("a = %d\n",a);
	}

	return 0;
}
