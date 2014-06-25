#include<stdio.h>
int main(void)
{
	char * pl = "Klingon";
	char arr[] = "AAAAAAA";
	//pl[0]= 'F';
	arr[0] = 'F';
	printf("Klingon");
	printf(": Beware the %ss!\n","Klingon");
	printf("arr=%s\n","AAAAAAA");

	return 0;
}
