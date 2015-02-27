#include<stdio.h>
int fb(void);
int main(void)
{
	int n=0;
	int i;
	while(n<=5)
	{
		//printf("%d\n",fb());
		printf("i=%d\n",fb());
		n++;
	}
	return 0;
}
int fb(void)
{
	static int i=0;
	//printf("i0=%d\n",i);
/*	if(&i==NULL)
		i=1;
	else 
		i++;
	printf("i=%d\n",i);*/
	i++;
	return i;
}
