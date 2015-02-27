#include<stdio.h>
#include<stdbool.h>
#include<stdlib.h>
#include<string.h>
typedef struct {
	int seatnum;
	bool seatassign; 
	char name[20];
}seatinfo;
void disfun(void);
void emptynum(seatinfo * seatinfos,int n);
void emptylist(seatinfo * seatinfos,int n);
void seatalp(seatinfo * seatinfos);
void seatass(seatinfo * seatinfos);
void seatdel(seatinfo * seatinfos);
int main(void)
{
	seatinfo seatinfos[12];
	FILE * fp;
	char fun;
	int n=0;
	int size=sizeof(seatinfo);
	if((fp=fopen("seatinfo","a+b"))==NULL)
	{
		fprintf(stderr,"Error to open the file.\n");
		exit(1);
	}
	for(n=0;n<12 && fread(&seatinfos[n],size,1,fp)==1;n++)
		continue;
	printf("n=%d\n",n);
	disfun();
	while((fun=getchar())!='f')
	{
		switch (fun) 
		{
			case 'a':emptynum(seatinfos,n); break;
			case 'b':emptylist(seatinfos,n); break;
			case 'c':seatalp(seatinfos);n=12; break;
			case 'd':seatass(seatinfos); break;
			case 'e':seatdel(seatinfos); break;
		}
		while(getchar()!='\n')
			continue;
		disfun();
	}
	printf("Bye.\n");
	if((fp=fopen("seatinfo","w+b"))==NULL)
	{
		fprintf(stderr,"error to open file.\n");
		exit(1);
	}
	if(fwrite(seatinfos,size,12,fp)!=12)
		printf("err.\n");
	return 0;
}
void disfun(void)
{
	printf("\nTo choose a function, enter its letter label;\n");
	printf("a) Show number of empty seats\n");
	printf("b) Show list of empty seats\n");
	printf("c) Show alphabetical list of seats\n");
	printf("d) Assogn a customer to a seat assignment\n");
	printf("e) Delete  seat assignment\n");
	printf("f) Quit\n\n");
}
void emptynum(seatinfo * seatinfos,int n)
{
	int i;
	int m=0;
	int noepy[n];
	for(i=0;i<n;i++)
		if(seatinfos[i].seatassign==0)	
			m++;
	printf("%d empty seats.\n",12-m);
}
void emptylist(seatinfo * seatinfos,int n)
{
	int i,a,m;
	int noepy[n];
	printf("%d\n",n);
	if(n!=0)
	{
		printf("The empty seat list is :\n");
		for(a=0;a<n;a++)
		{
			if(seatinfos[a].seatassign==1)
				printf("%d ",seatinfos[a].seatnum);
		}
	}
	else
	{
		printf("The empty seat list is :\n");
		for(m=0;m<12;m++)
		{
			printf("%d ",m+1);
			seatinfos[m].seatnum=m+1;
			seatinfos[m].seatassign=1;
			strcpy(seatinfos[m].name,"\0");
		}
	}
	putchar('\n');	
}
void seatalp(seatinfo * seatinfos)
{
	int n;
	char whempty[10];
	printf("List of the seat.\n");
	int ch[]={'a','b','c','d','e','f','g','h','i','j','k','l'};
	for(n=0;n<12;n++)
	{
		if(seatinfos[n].seatassign==1)
		{
			strcpy(whempty,"empty");
			printf("empty\n");
		}
		else if(seatinfos[n].seatassign==0)
		{
			strcpy(whempty,"no empty");
			printf("no empty\n");
		}
		printf("%c %d %s %s\n",ch[n],n+1,whempty,seatinfos[n].name);
		printf("%d\n",seatinfos[n].seatassign);
	}
}
void seatass(seatinfo * seatinfos)
{
	int getem,n=0;
	printf("Choise a empty seat.(Enter q to quit)\n");
	while(scanf("%d",&getem)==1)
	{
		if(seatinfos[getem-1].seatassign==0)
		{
			fprintf(stderr,"Notice!!!You enter an occupy seat!!!\n");
			break;
		}
		while(getchar()!='\n')
			continue;
		printf("Enter the customer name.\n");
		gets(seatinfos[getem-1].name);
		seatinfos[getem-1].seatassign=false;
		printf("Choise another empty seat.\n");
	}
}
void seatdel(seatinfo * seatinfos)
{
	int getn;
	printf("Enter the seat number that you want to delete.(q to quit)\n");
	while(scanf("%d",&getn)==1 && getn<=12)
	{
		seatinfos[getn-1].seatassign=true;
		strcpy(seatinfos[getn-1].name,"\0");
	}
}
