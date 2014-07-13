#include<stdio.h>
#include<string.h>
int main(void)
{
	char arr[4][6]={"abcdef","ABCDEF","ghijkl","GHIJKL"};
	char arr2[6]="uvwxyz";
	int arrint[3][6];
	//strncat(arr[0],arr2,6);
	printf("%s\n%s\n",&arr[0][0],&arr[1][0]);


	return 0;
}
