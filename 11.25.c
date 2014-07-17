//selection sort
#include<stdio.h>
#include<string.h>
#define LVM 20
#define SIZE 81
void stsrt(char * string[],int i);
int main(void)
{
	char input[LVM][SIZE];
	char * ptstr[LVM];
	int i=0;
	int k=0;
	printf("Pls enter %d lines, and I will sort them.\n",LVM);
	printf("Enter enter to stop at a line's start.\n");
	while((i<LVM) && (gets(input[i])!=NULL) && (input[i][0]!='\0'))
		{
			ptstr[i] = input[i];
			i++;
		}
	stsrt(ptstr,i);
	puts("\n Here's the sorted list: \n");
	for(k=0;k<i;k++)
		puts(ptstr[k]);
	return 0;
}
void stsrt(char * string[],int i)
{
	char * temp;
	int top,seek;
	for(top=0;top<i-1;top++)
		for(seek=top+1;seek<i;seek++)
		{
			if(strcmp(string[top],string[seek])>0)
				{
					temp = string[top];
					string[top] = string[seek];
					string[seek] = temp;
				}
		}
}
