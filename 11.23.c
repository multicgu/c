#include<stdio.h>
#include<string.h>
#define LVM 5
#define TARGSIZE 7
#define SIZE 40
int main(void)
{
	char qword[LVM][TARGSIZE];
	char temp[SIZE];
	int i=0;
	puts("Pls enter the string with q.");
	while(i<LVM && gets(temp))
	{
		//if(temp[0] != 'q')
		if(strncmp(temp,"q",1))
			printf("you enter %s isn't began with 'q',try again.\n",temp);
		else
		{
			strncpy(qword[i],temp,TARGSIZE);
			qword[i][TARGSIZE-1]='\0';
			i++;
		}
	}
	printf("the string you enter is:\n");
	for(i=0;i<LVM;i++)
		puts(qword[i]);

	return 0;
}
