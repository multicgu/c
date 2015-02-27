#include<stdio.h>
#define JUSTCHECK
#undef JUSTCHECK
#define LIMIT 4
int main(void)
{
	int i;
	int total=0;
	for(i=1;i<=LIMIT;i++)
	{
		total+=2*i*i+1;
#ifdef JUSTCHECK
	printf("i=%d total=%d\n",i,total);
#endif
	}
	printf("total=%d\n",total);

	return 0;
}
