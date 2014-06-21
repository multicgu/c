#include<stdio.h>
char chi();
float num();
int main(void)
{
	char ch;
	float a,b;
	printf("Enter the operation of your choice:\n");
	printf("a. add   s. subtract  m. multiply  d. divide  q. quit\n");
	while((ch = chi()) != 'q')
	{
		while(ch!='a' && ch!='s' && ch!='m' && ch!='d' && ch!='q')
		{
			printf("Please input 'a','s','m','d','q'\n");
			ch = chi();
		}
			printf("ch = %c\n",ch);
		printf("Enter first number: \n");
		a = num();
		printf("a = %f\n",a);
		printf("Enter second number: \n");
		b = num();
		printf("b = %f\n",b);
		switch(ch)
		{
			case 'a':
				printf("%.2f + %.2f = %.2f\n",a,b,a+b);
				break;
			case 's':
				printf("%.2f - %.2f = %.2f\n",a,b,a-b);
				break;
			case 'm':
				printf("%.2f * %.2f = %.2f\n",a,b,a*b);
				break;
			case 'd':
				if(b == 0)
				{
					printf("Enter a number other than 0: ");
					b = num();
				}
				printf("%.2f / %.2f = %.2f\n",a,b,a/b);
				break;
			case 'q':
				break;		
		}
	printf("Enter the operation of your choice:\n");
	printf("a. add   s. subtract  m. multiply  d. divide  q. quit\n");
	}
	printf("Bye!\n");
	return 0;
}

char chi()
{
	char ch;
	while((ch = getchar()) == '\n')
		continue;
		while(getchar() != '\n')
			continue;
		printf("chi = %c\n",ch);
	
	return ch;
}

float num()
{
	float i;
	char n;
	while((scanf("%f",&i)) != 1)
	{
		if((n = getchar()) != '\n')
		{
			printf("%c is not an number.\nPlease enter a number: ",n);
			while(getchar() != '\n')
				continue;
		}
	}
	printf("i = %f\n",i);
	while(getchar() != '\n')
			continue;
	return i;
}

