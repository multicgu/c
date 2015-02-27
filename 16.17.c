//mems.c use memcpy() & memmove()
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#define SIZE 10
void show_array(int ar[],int n);
int main(void)
{
	int value[SIZE]={1,2,3,4,5,6,7,8,9,10};
	int target[SIZE];
	double curious[SIZE/2]={1.0,2.0,3.0,4.0,5.0};
	puts("memcpy() use:");
	puts("Show the original data.");
	show_array(value,SIZE);
	memcpy(target,value,10*sizeof(value[0]));
	puts("Show the memcpy copied data.");
	show_array(target,SIZE);
	
	puts("\nUsing memmove() with overlapping ranges: ");
	memmove(value+2,value,5*sizeof(value[0]));
	show_array(value,10);

	puts("\nUsing memcpy() to copy double to int. ");
	memcpy(target,curious,(SIZE/2)*sizeof(curious[0]));
	show_array(target,10);

	return 0;
}
void show_array(int ar[],int n)
{
	int i;
	for(i=0;i<n;i++)
		printf("%d ",ar[i]);
	putchar('\n');
}
