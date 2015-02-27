//doubincl.c
#include<stdio.h>
#include "16.10.h"
#include "16.10.h"  //the duplicate define error for test
int main(void)
{
	names winners={"Less","Ismoor"};
	printf("%s %s\n",winners.first,winners.last);

	return 0;
}
