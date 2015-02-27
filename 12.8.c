//r_drive0.c test rand0() function
#include<stdio.h>
extern unsigned long int rand0(void);
int main(void)
{
	int count;
	for(count=1;count<=5;count++)
		printf("%hd\n",rand0());
	return 0;
}
