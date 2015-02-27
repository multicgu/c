//flexmenb.c
#include<stdio.h>
#include<stdlib.h>
struct flex {
	int count;
	double average;
	double scores[];
};
void showflex(struct flex * );
int main(void)
{
	struct flex * pf1, * pf2;
	int n=5;
	int tol=0;
	int i;
	pf1= malloc(sizeof(struct flex) + n*sizeof(double));
	pf1->count=5;
	for(i=0;i<n;i++)
		{
			pf1->scores[i]=20.0-i;
			tol+=pf1->scores[i];
		}
	pf1->average=tol/n;
	showflex(pf1);
	n=9;
	tol=0;
	pf2=malloc(sizeof(struct flex) + n*sizeof(double));
	pf2->count=n;
	for(i=0;i<n;i++)
	{
		pf2->scores[i]=20.0-i/2;
		tol+=pf2->scores[i];
	}
	pf2->average=tol/n;
	showflex(pf2);
	free(pf1);
	free(pf2);
	return 0;
}
void showflex(struct flex * pf)
{
	int i;
	printf("Scores: ");
	for(i=0;i< pf->count;i++)
		printf("%g ",pf->scores[i]);
	printf("\nAverage: %f\n",pf->average);
}
