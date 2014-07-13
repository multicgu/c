#include<stdio.h>
#include<string.h>
#define LVM 5
#define SIZE 5
int main(void)
{
	char qwords[LVM][SIZE];
	char temp[SIZE];
	int i=0;
	printf("Enter %d words beginning with q:\n",LVM);
	while(i<LVM && gets(temp))
	{
		//if(temp[0] != 'q')
		if(strncmp(temp,"q",1) != 0)
			printf("you input word is not begin with 'q',try agagin.\n");
		else
		{
			strcpy(qwords[i],temp);
			i++;
		}
	}
	printf("You enter is follow.\n");
	for(i=0;i<LVM;i++)
		puts(qwords[i]);
	return 0;
}
