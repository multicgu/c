#include<stdio.h>
#define SIZE 10	
int sump(int * start,int * end);
int main(void)
{
	int marbles[SIZE]={20,10,5,39,4,16,19,26,31,20};
	int answer;
	answer=sump(marbles,marbles+SIZE);
	printf("The sum of the marbles is %d\n",answer);
	return 0;
}

int sump(int * start,int * end)
{
	int total;
	/*for(total = 0;start<end;start++)
		total += *start; */
	while(start<end)
		total += *start++;
	return total;
}
