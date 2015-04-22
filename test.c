#include<stdio.h>
#define max(a,b) {return (a)>(b)?(a):(b);}
int main(void)
{
	//int a,b;
	//scanf("%d%d",&a,&b);
	int a=max(2,3);
	//printf("%d\n",max(2,3));
	printf("%d\n",a);

	return 0;
}
