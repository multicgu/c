#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<stdbool.h>
typedef struct {
	int num;
	bool ass; // whether has been assigned;
	char name[20];
} seat;
void dismeum(int n);
void shownum(seat * seats);
void showlist(seat * seats);
void alplist(seat * seats);
int seatass(seat * seats);
int seatdel(seat * seats);
int conass(seat * seats);
int main(void)
{
	seat seats[4][12];
	FILE * fp;
	int size=sizeof(seat);
	int n,i;
	int airline[4]={102,311,444,519};
	char choice; //choice the meum;
	int sal;  // select the airline;
	if((fp=fopen("seats","a+b"))==NULL)
	{
		fprintf(stderr,"Error to open the file.\n");
		exit(1);
	}
	fread(seats,size,48,fp);
	/*{
		fprintf(stderr,"Error to fread.\n");
		exit(1);
	}*/
	for(n=0,i=0;n<4;n++)
	{
		if(seats[n][0].num!=1 && (seats[n][0].ass!=0||seats[n][0].ass!=1))
		{
			for(i=0;i<12;i++)
			{
				seats[n][i].num=i+1;
				seats[n][i].ass=1;
				strcpy(seats[n][i].name,"\0");
			}
		}
	}
	printf("Choice the airline (Press q to exit)\n");
	printf("1. 102  2. 311  3. 444  4. 519\n");
	while(scanf("%d",&sal)==1)
	{
		if(sal>4)
		{
			printf("Enter the num range 1-4\n1.102 2.311 3.444 4.519\n");
			break;
		}
		/*if((fp=fopen("seats","a+b"))==NULL)
		{
			fprintf(stderr,"Error to open the file.\n");
			exit(1);
		}
		if(fseek(fp,(long)12*size*(sal-1),SEEK_SET)!=0)
		{
			fprintf(stderr,"Locate location error.\n");
			exit(1);
		}
		while(fread(&seats[sal-1][n],size,1,fp)==1)
			n++;*/
		// judge the file be opened first or not;
		/*if(seats[sal][0].num!=1&&(seats[sal][0].ass!=1||seats[sal][0].ass!=0))
			for(n=0;n<12;n++)
			{
				seats[sal][n].num=n+1;
				seats[sal][n].ass=1;
				strcpy(seats[sal][n].name,"\0");
			}*/
		while(getchar()!='\n')
			continue;
		dismeum(sal);
		printf("first dis:\n");
		while((choice=getchar())!='g')
		{
			switch (choice)
			{
				case 'a':shownum(seats[sal]);break;
				case 'b':showlist(seats[sal]);break;
				case 'c':alplist(seats[sal]);break;
				case 'd':seatass(seats[sal]);break;
				case 'e':seatdel(seats[sal]);break;
				case 'f':conass(seats[sal]);break;
			}
			while(getchar()!='\n')
				continue;
			dismeum(sal);	
			printf("second dis:\n");
		}
		printf("Choice the airline (Press q to exit)\n");
		printf("1. 102  2. 311  3. 444  4. 519\n");
	}
	if((fp=fopen("seats","w+b"))==NULL)
	{
		fprintf(stderr,"Error to open the file.\n");
		exit(1);
	}
	/*if(fseek(fp,(long)12*size*(sal-1),SEEK_SET)!=0)
	{
		fprintf(stderr,"Error to locate location.\n");
		exit(1);
	}*/
	if(fwrite(seats,size,48,fp)!=48)
		fprintf(stderr,"Error to write.\n");
	return 0;
}
void dismeum(int n)
{
	int airline[4]={102,311,444,519};
	printf("\nIn the airline %d\n",airline[n-1]);
	printf("To choose a function, enter its letter label:\n");
	printf("a) Show number of empty seats\n");
	printf("b) Show list of empty seats\n");
	printf("c) Show alphabetical list of seats\n");
	printf("d) Assign a customer to a seat assignment\n");
	printf("e) Delete a seat assignment\n");
	printf("f) Confirm assignment\n");
	printf("g) return to selest the airline\n\n");
}
void shownum(seat * seats)
{
	int n,i;
	for(n=0,i=0;n<12;n++)
		if(seats[n].ass==1)
			i++;
	printf("Have %d empty seats.\n",i);
}
void showlist(seat * seats)
{
	int n,i;
	printf("Empty seats:\n");
	for(n=0;n<12;n++)
		if(seats[n].ass==1)
			printf("%d ",seats[n].num);
	putchar('\n');
}
void alplist(seat * seats)
{
	int n;
	char whem[3];
	printf("alphabetical seatnum empty? name\n");
	int ch[12]={'a','b','c','d','e','f','g','h','i','j','k','l'};
	for(n=0;n<12;n++)
	{
		if(seats[n].ass==1)
			strcpy(whem,"yes");
		else
			strcpy(whem,"no");
		printf("%9c %7d %4s %s\n",ch[n],seats[n].num,whem,seats[n].name);
	}
}
int seatass(seat * seats)
{
	int unem[12];
	int getem,n,i;
	for(n=0,i=0;n<12;n++)
		if(seats[n].ass==0)
		{
			unem[i]=seats[n].num;
			i++;
		}
	printf("Pls enter a empty seat.(Press q to quit)\n");
	while(scanf("%d",&getem)==1)
	{
		for(n=0;n<=i;n++)
			if(getem==unem[n])
			{
				fprintf(stderr,"You enter a no empty seat.\n");
				return 0;
			}
		while(getchar()!='\n')
			continue;
		printf("Pls enter the customer name.\n");
		gets(seats[getem-1].name);
		seats[getem-1].ass=0;
		printf("Pls enter a another empty seat.");
	}
	return 0;
}
int seatdel(seat * seats)
{
	int n,get;
	int em[12];
	printf("Enter the seat to delete.\n");
	while(scanf("%d",&get)!=1 && get>12)
		printf("Pls enter a seat number range 1-12.\n");
	for(n=0;n<12;n++)
		if(seats[n].ass==1 && seats[n].num==get)
		{
			fprintf(stderr,"Pls enter a no empty seat number.\n");
			return 0;
		}
	seats[get-1].ass=1;
	strcpy(seats[get-1].name,"\0");
	return 0;
}
int conass(seat * seats)
{
	int get;
	printf("Pls enter a seat number.\n");
	if(scanf("%d",&get)!=1 && get<=12)
	{
		fprintf(stderr,"Pls enter seat number range 1-12.\n");
		return 0;
	}
	if(seats[get-1].ass==1)
		printf("Seat number %d you enter is empty.\n",get);
	else
		printf("Seat number %d you enter is no empty.\n",get);
	return 0;
}
