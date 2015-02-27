//12.11.3b.c
#include<stdio.h>
#include"12.11.3.h"
int main(void)
{
	int mode;
	double distance;
	double fuel;

	printf("Enter 0 for metric mode,1 for US mode: ");
	scanf("%d",&mode);
	while(mode>=0)
	{
		set_mode(&mode);
		printf("mode=%d\n",mode);
		get_info(&distance,&fuel,mode);
		show_info(distance,fuel,mode);
		printf("Enter 0 for metric mode,1 for US mode(-1 to quit): ");
		scanf("%d",&mode);
	}
	printf("Done.\n");
	return 0;
}
