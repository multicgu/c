#include<stdio.h>
#include "16.6.h"
void getnames(names * pn)
{
	printf("Please enter you first name: ");
	fgets(pn->first,SLEN,stdin);
	int i=0;
	while(pn->first[i]!='\n' && pn->first[i]!='\0')
		i++;
	if(pn->first[i]=='\n')
		pn->first[i]='\0';
	else
		while(getchar()!='\n')
			continue;
	printf("Please enter last name: ");
	fgets(pn->last,SLEN,stdin);
	i=0;
	while(pn->last[i]!='\n' && pn->last[i]!='\0')
		i++;
	if(pn->last[i]=='\n')
		pn->last[i]='\0';
	else 
		while(getchar()!='\n')
			continue;
}
void shownames(const names * pn)
{
	printf("%s %s \n",pn->first,pn->last);
}
