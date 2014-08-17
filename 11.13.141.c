#include<stdio.h>
#include<ctype.h>
#define MAX 81
double Atof(char * str);
int main(void)
{
	char str[MAX];
	while(gets(str) && *str==EOF);
	printf("%f\n",Atof(str));
	return 0;
}
double Atof(char * str)
{
	double f=0;
	int n=0;
	double f1=0;
	int h=1;
	if(isdigit(str[0]) || str[n]=='-')
	{
		if(isdigit(str[n]))
		{
			while(isdigit(str[n]))
			{
				f=f*10+(str[n] - '0');
				n++;
			}
		}
		if(str[n]=='.')
		{
			n++;
			while(isdigit(str[n]))
			{
				f1=f1*10+(str[n]-'0');
				n++;
				h*=10;
			}
			printf("f1=%f,h = %d\n",f1,h);
			f1/=h;
			return (f+f1);
		}
		else if(str[n!='.'])
			return f;
		/*else if(str[n]=='-')
		{
			n++;
			while(isdigit(str[n]))
			{
				f=f*10+(str[n] - '0');
				n++;
			}
			printf("f=%f\n",f);
			if(str[n]=='.')
			{
				n++;
				while(isdigit(str[n]))
				{
					f1=f1*10+(str[n]-'0');
					n++;
					h*=10;
				}
				f1/=h;
				printf("f1=%f\n",f1);
				return (f+f1);
			}
			else if(str[n]!='.')
				return f;

		}*/
	}
}
