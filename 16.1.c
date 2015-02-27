#include<stdio.h>
#define TWO 2
#define FOUR TWO*TWO
#define OW "Consistency is the last refuge of the unimagina\
	tive. - Oscar Wilde"
#define PX printf("X is %d.\n",x);
#define FMT "X is %d.\n"
int main(void)
{
	int x = TWO;
	PX;
	x=FOUR;
	printf(FMT,x);
	printf("%s\n",OW);
	printf("%d %s\n",TWO,OW);
	return 0;
}
