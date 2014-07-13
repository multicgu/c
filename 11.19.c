#include<stdio.h>
#include<string.h>
#define SIZE 81
#define LIM 100
#define STOP "stop"
int main(void)
{
	char input[LIM][SIZE];
	int ct;
	printf("Enter up to %d lines (type quit to quit);\n",LIM);
	while(ct < LIM && gets(input[ct])!=NULL && strcmp(input[ct],STOP) && input[ct][0] != '\0')
	{
		ct++;
	}
	printf("%d strings entered\n",ct);

	return 0;
}
