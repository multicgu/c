#include<stdio.h>
#define CSIZE 4
#include"14.18.5.ab.c"
//extern student;
int getinfo(student *);
void putinfo(student *,int n);
int main(void)
{
	int n;
	student students[CSIZE];
	n=getinfo(students);
	putinfo(students,n);
	
	return 0;
}
int getinfo(student * students)
{
	int i=0;
	int n;
	float sum;
	puts("Pls enter first name.(press enter at start of new line to quit)");
	while(i<CSIZE && gets(students[i].names.fname)!=NULL && students[i].names.fname[0]!='\0')
	{
		puts("Pls enter last name.");
		gets(students[i].names.lname);
		printf("Pls enter the 3 grades of %s.",students[i].names.fname);
		for(n=0,sum=0;n<3;n++)
		{
			fscanf(stdin,"%f",&students[i].grade[n]);
			sum+=students[i].grade[n];
		}
		students[i].avegrade=sum/3;
		while(getchar()!='\n')
			continue;
		i++;
		if(i<CSIZE)
			puts("Pls enter you first name");
	}
	return i;
}
void putinfo(student * students,int n)
{
	int i,a,b;
	float sum;
	float classave;
	for(i=0;i<n;i++)
	{
		printf("%s %s's grades is:\n",students[i].names.fname,students[i].names.lname);
		for(a=0;a<3;a++)
			printf("%f ",students[i].grade[a]);
		puts("\n");
		printf("The average grade is %f.\n",students[i].avegrade);
	}
	for(b=0;b<n;b++)
		sum+=students[b].avegrade;
	classave=sum/n;
	printf("The class average grade is %f.\n",classave);
}
