#include<stdio.h>
int main(void)
{
	int i=0;
	int a[] = {1,2,3,4,5};
	for(i=0;i<5;i++)
	    scanf("%d",&a[i]);
	int *b = a;
	printf("~~~~~~~~~~~~~~~~\n");
	for(i=0;i<8;i++)
		printf("%d\n",b[i]);

	return 0;
}
