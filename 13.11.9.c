#include<stdio.h>
#include<stdlib.h>
#define MAX 30
int main(void)
{
	FILE * fp;
	char word[MAX];
	char wordout[MAX];
	int n=0;
	if((fp=fopen("word","a+"))==NULL)
	{
		fprintf(stderr,"file word can't be open.\n");
		exit(1);
	}
	while((fgets(word,MAX,fp))!=NULL)
		n++;
	printf("%d\n",n);
	puts("Enter ");
	while(gets(word) && word[0]!='\0')
	{
		fprintf(fp,"%d:%s\n",++n,word);
	}
	rewind(fp);
	while(fscanf(fp,"%s",wordout)==1)
		puts(wordout);

	return 0;
}
