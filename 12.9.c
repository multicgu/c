#include<stdio.h>
static unsigned long int next=1;
unsigned long int rand1(void)
{
	next=next*1103515245 + 12345;
	return (next/65536)%32768;
}
void srand1(int seed)
{
	next = seed;
}
