#include<stdio.h>
#include<stdlib.h>
int btoi(char * bin);
void itob(int n);
int main(int argc,char * argv[])
{
	printf("%d\n",argc);
	printf("%s %s\n",argv[1],argv[2]);
	int a,b;
	if(argc!=3)
	{
		fprintf(stderr,"Please enter 2 binary numbers.\n");
		exit(1);
	}
	a=btoi(argv[1]);
	b=btoi(argv[2]);
	printf("The number you enter is %d and %d\n",a,b);
	printf("After use ~:\n");
	itob(~a);
	itob(~b);
	printf("After use &:\n");
	itob(a&b);
	printf("After use |:\n");
	itob(a|b);
	printf("After use ^:\n");
	itob(a^b);

	return 0;
}
int btoi(char * bin)
{
	int i=0;
	while(bin[i])
		i++;
	int n,sum=0;
	int mask=1;
	for(n=i-1;n>=0;n--,mask=mask<<1)
	{
		if(bin[n]==49)
			sum |= mask;
		if(bin[n] != 48 && bin[n]!=49)
		{
			printf("System found the input number is not binary.\n");
			break;
		}
	}
	return sum;
}
void itob(int n)
{
	int i=0;
	int bin[8];
	for(i=7;i>=0;i--,n>>=1)
		bin[i]= (n&1);
	for(i=0;i<8;i++)
		printf("%d",bin[i]);
	putchar('\n');
}
