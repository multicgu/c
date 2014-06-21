#include<stdio.h>
int main(void)
{
	int a[2]={4,5};
	int * b;
	b = &a[0];
	printf("a[0]=%d %p,a[1]=%d %p,b=%p %p\n",a[0],a,a[1],&a[1],b,b+1);
	return 0;
}
