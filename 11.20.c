#include<stdio.h>
#include<string.h>
int main(void)
{
	char * string[] = {"astronomy","astounding","astrophysics","ostracize","asterism"};
	int i=sizeof(string)/sizeof(string[0]);
	int n,a;
	for(n=0,a=0;n<i;n++)
		if(strncmp(string[n],"astro",i)==0)
			{
				a++;
				puts(string[n]);
			}	
	printf("Ths list contained %d words beginning with astro.\n",a);

	return 0;
}
