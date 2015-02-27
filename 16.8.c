#include<stdio.h>
#include "16.6.h"
int main(void)
{
	names candidate;
	getnames(&candidate);
	printf("Show you enter: ");
	shownames(&candidate);
	return 0;
}
