#include<stdio.h>
int main(void)
{
	char * string = "abcdefg";
	printf("string = %s\n",string);
	printf("&string[0] = %s\n",&string[0]);
	printf("string + 1 = %s\n",string+1);
	printf("string(c) = %c\n",string);
	printf("*string(c) = %c\n",*string);
	printf("*string = %s\n",*string);

	return 0;
}
