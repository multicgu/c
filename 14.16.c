//func_ptr.c
#include<stdio.h>
#include<string.h>
void ToUpper(char *);
void ToLower(char *);
void Transpose(char *);
void Dummy(char *);
void eatline(void);
void show(void (* p_fun)(char *),char * str);
int showchoice(void);
typedef void (* PFUN)(char *);
int main(void)
{
	char line[81];
	char copy[81];
	PFUN p_fun[4]={ToUpper,ToLower,Transpose,Dummy};
	int choice;
	printf("Please enter a string.(input enter at a new line to quit)\n");
	while((gets(line)!=NULL) && line[0]!='\0')
	{
		while((choice=showchoice()) !=4)
		{
			strcpy(copy,line);
			show(p_fun[choice],copy);
		}
	}

	return 0;
}
int showchoice(void)
{
	char ans;
	printf("Select a menu choice.\n");
	puts("u) uppercase l) lowercase t) transposed case o) original case");
	puts("n) next string");
	ans=getchar();
	ans=tolower(ans);
	eatline();
	while(strchr("ulton",ans)==NULL)
	{
		puts("Pls enter a u,l,t,o,or n: ");
		ans=tolower(getchar());
		eatline();
	}
	if(ans=='u') return 0;
	else if(ans=='l') return 1;
	else if(ans=='t') return 2;
	else if(ans=='o') return 3;
	else if(ans=='n') return 4;
}
void eatline(void)
{
	while(getchar() != '\n')
		continue;
}
void ToUpper(char * str)
{
	while(*str)
	{
		*str=toupper(*str);
		str++;
	}
}
void ToLower(char * str)
{
	while(*str)
	{
		*str=tolower(*str);
		str++;
	}
}
void Transpose(char * str)
{
	while(*str)
	{
		if(islower(*str))
			*str=toupper(*str);
		else if(isupper(*str))
			*str=tolower(*str);
		str++;	
	}
}
void Dummy(char * str)
{
	//
}
void show(void (*p_fun)(char *),char * str)
{
	(*p_fun)(str);
	puts(str);
}
