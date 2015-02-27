//complit.c
#include<stdio.h>
#define MAXTITL 41
#define MAXAUTL 31
struct book {
	char title[MAXTITL];
	char author[MAXAUTL];
	float value;
};
int main(void)
{
	struct book readfirst;
	int score;
	fprintf(stdout,"Please get the score.\n");
	fscanf(stdout,"%d",&score);
	if(score>=84)
		readfirst=(struct book) {"Crime and Punishment","Fyodor Dostoyevsky",9.99};
	else
		readfirst=(struct book) {"Mr.Bonucy's Nice Hat","Fred Winsome",5.99};
	printf("You assigned reading.\n");
	printf("%s by %s:%.2f\n",readfirst.title,readfirst.author,readfirst.value);
	return 0;
}
