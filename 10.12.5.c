#include<stdio.h>
int main(void)
{
	int (* ptr)[2];
	int torf[2][2] = {12,14,16};
	ptr = torf;

	printf("**ptr = %d **(ptr+1) = %d\n",**ptr,**(ptr+1));
	printf("ptr=%p\n",ptr);
	printf("*ptr=%p and &torf[0][0]=%p\n",*ptr,&torf[0][0]);
	printf("");
	printf("ptr+1=%p *(ptr+1)=%p\n",ptr+1,*(ptr+1));
	int n,i;
	for(n=0;n<2;n++)
		for(i=0;i<2;i++)
			printf("torf[%d][%d] = %d\n",n,i,torf[n][i]);

	return 0;
}

