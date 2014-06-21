#include<stdio.h>
void copy_arr(int [],int [],int);
int main(void)
{
	int source[]={1,2,3,4,5,6,7};
	int n;
	for(n=0;n<(sizeof source/sizeof source[0]);n++);
	printf("n=%d\n",n);
	int target1[3];
	copy_arr(&source[2],target1,3);
	printf("target[3]={%d,%d,%d};\n",target1[0],target1[1],target1[2]);
	return 0;
}
void copy_arr(int source[],int target1[],int n)
{
	int a;
	int i;
	for(i=0;i<n;i++)
		target1[i] = source[i];
}
