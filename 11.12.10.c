#include<stdio.h>
char * space(const char *);
int main(void)
{
	char str[30];
	gets(str);
	puts(str);
	printf("%s\n",space(str));
	printf("str = %s\n",str);

	return 0;
}
char * space(const char * string)
{
	char * sp;
	while(*string!=' ' && *string!='\0')
		string++;
	if(*string==' ')
	{
		sp = (char *) string;
		printf("sp = '%s'\n",sp);
		//printf("space = %s\n",string);
	}
	else//if(*string='\n')
		return NULL;
	return sp;
}
