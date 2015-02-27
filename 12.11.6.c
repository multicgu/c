#include<stdio.h>
int rand(void);
unsigned long int seed;
int main(void)
{
	int n,i;
	int one=0;int two=0;int three=0;int four=0;int five=0;int six=0;int seven=0;int eight=0;int nine=0;int ten=0;
	unsigned long arr[1000];
	printf("Enter the seed,program will cal the num of the repeater.");
	
	scanf("%ld",&seed);
	for(n=0;n<1000;n++)
	{
		arr[n]=rand();
		if(arr[n]==1) one++;
		if(arr[n]==2) two++;
		if(arr[n]==3) three++;
		if(arr[n]==4) four++;
		if(arr[n]==5) five++;
		if(arr[n]==6) six++;
		if(arr[n]==7) seven++;
		if(arr[n]==8) eight++;
		if(arr[n]==9) nine++;
		if(arr[n]==10) ten++;
	}
	printf("one %d,two %d,three %d,four %d,five %d,six %d,seven %d,eight %d,nine %d,ten %d\n",one,two,three,four,five,six,seven,eight,nine,ten);
	printf("sum=%d\n",one+two+three+four+five+six+seven+eight+nine+ten);
	
	return 0;
}
int rand(void)
{
	seed = seed*1103515245 + 12345;
	return (unsigned int) (((seed/65536)%32768)%10+1);
}
