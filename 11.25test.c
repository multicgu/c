#include<stdio.h>
int main(void)
{
	int i=0;
	//char * arr[40];
	char arr[30][30];
	while(i<40 && gets(arr[i]) && arr[i][0]!='\0')
	{
		printf("arr[%d]=%s\n",i,arr[i]);
	//	puts(arr[i]);	
		i++;
	}
	return 0;
}
