#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define MAXNUM 18
struct baseinfo {
	char fn[10];
	char ln[10];
	int games;
	int hits;
	int homes;
	int rbis;
	float average;
};
struct baseinfo totalpfm(struct baseinfo members[]);
void clear(struct baseinfo members[]);
int main(void)
{
	struct baseinfo members[MAXNUM];
	struct baseinfo teampfm;
	FILE * fp;
	char buf[41];
	int index,game,hit,home,rbi,n;
	char fname[10],lname[10];
	clear(members);
	if((fp=fopen("14.18.6.txt","r"))==NULL)
	{
		fprintf(stderr,"Fail to open the file.\n");
		exit(1);
	}
	rewind(fp);
	while(fscanf(fp,"%d%s%s%d%d%d%d",&index,fname,lname,&game,&hit,&home,&rbi)==7)
	{
		strcpy(members[index].fn,fname);
		strcpy(members[index].ln,lname);
		members[index].games=game;
		members[index].hits=hit;
		members[index].homes=home;
		members[index].rbis=rbi;
		members[index].average=(float)hit/game;
	}
	teampfm=totalpfm(members);
	printf("name           game hit home rbi average\n");
	for(n=0;n<MAXNUM;n++)
	{
		printf("%7s%7s%4d%4d%4d%4d%7.2f\n",members[n].fn,members[n].ln,members[n].games,members[n].hits,members[n].homes,members[n].rbis,members[n].average);
	}
	printf("team performance %3d%3d%3d%3d%6.2f\n",teampfm.games,teampfm.hits,teampfm.homes,teampfm.rbis,teampfm.average);

	return 0;
}
void clear(struct baseinfo members[])
{
	int n;
	for(n=0;n<MAXNUM;n++)
	{
		strcpy(members[n].fn,"");
		strcpy(members[n].ln,"");
		members[n].games=0;
		members[n].hits=0;
		members[n].homes=0;
		members[n].rbis=0;
		members[n].average=0;
	}
}
struct baseinfo totalpfm(struct baseinfo members[])
{
	int n;
	struct baseinfo teampfm={"","",0,0,0,0,0};
	for(n=0;n<MAXNUM;n++)
	{
		teampfm.games+=members[n].games;
		teampfm.hits+=members[n].hits;
		teampfm.homes+=members[n].homes;
		teampfm.rbis+=members[n].rbis;
	}
	teampfm.average=(float) teampfm.hits/teampfm.games;
	printf("%f\n",teampfm.average);
	return teampfm;
}
