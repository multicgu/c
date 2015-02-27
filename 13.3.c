//addaword.c  -- use fprintf(),fscanf(),rewind() function.
#include<stdio.h>
#include<stdlib.h>
int main(void)
{
	char words[30];
	char wordout[30];
	FILE * a;
	if((a=fopen("words","a+"))==NULL)
	{
		fprintf(stderr,"File 'words' can not be open.\n");
		exit(1);
	}
	puts("Enter words to add to the file; press the Enter ");
	puts("at the beginning of a line to terminate.");
	while(gets(words)!=NULL && words[0]!='\0')
		fprintf(a,"%s ",words);
	puts("File contents: ");
	rewind(a); // return the begin of the file;
	while((fscanf(a,"%s",wordout))==1)
		puts(wordout);
	if(fclose(a)!=0)
		fprintf(stderr,"Error closeing file.\n");

	return 0;

}
