#include<stdio.h>
struct member {
	char fname[10];
	char lname[10];
	char mname[10];
}; 
struct information {
	long ssn;
	struct member members;
};
void show(struct information *,int);
int main(void)
{
	int n=0;
	struct information info[5];
	puts("Enter the first name.(Press enter at the start of new line to quit)");
	while(n<5 && gets(info[n].members.fname)!=NULL && info[n].members.fname[0]!='\0')
	{
		puts("Enter the last name.");
		gets(info[n].members.lname);
		puts("Enter the middle name.");
		gets(info[n].members.mname);
		puts("Enter the society security number.");
		scanf("%ld",&info[n].ssn);
		while(getchar()!='\n')
			continue;
		n++;
		if(n<5)
			puts("Enter the next first name.");
	}
	show(info,n);
	return 0;
}
void show(struct information * p,int n)
{
	int i;
	for(i=0;i<n;i++)
		printf("%s, %s %c. - %ld\n",p[i].members.fname,p[i].members.lname,p[i].members.mname[0],p[i].ssn);
}
