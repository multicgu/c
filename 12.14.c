#include<stdio.h>
#include<stdlib.h>
int main(void)
{
	int i=0;
	int num;
	int max;
	double * pti;
	printf("What is the maximum number of type double enteries? ");
	scanf("%d",&max);
	printf("max=%d\n",max);
	pti=(double *) malloc(max*sizeof(double));
	if(pti==NULL)
	{
		puts("Memory allocation failed, Goodbye.");
		exit(EXIT_FAILURE);
	}
	puts("Enter the values(q to quit):");
	while(i<max && scanf("%lf",&pti[i])==1)
		++i;
	printf("Here are you %d entries:\n",num=i);
	for(i=0;i<num;i++)
	{
		printf("%7.2f ",pti[i]);
		if(i%7==6)
			putchar('\n');
	}
	/*if(i%7!=0)
		putchar('\n');*/
	if((i-1)%7!=6)
		putchar('\n');
	free(pti);
	return 0;
}
