#include<stdio.h>
#define MAX 81
int main(void)
{
	int n;
	char name[MAX];
	char * ptr;
	printf("Hi, what's your name.\n");
	ptr = gets(name);
	printf("%s? Ah! %s!\n",name,ptr);
	printf("%c? Ah! %c!\n",*name,*ptr);
	printf("%s? Ah! %s!\n",&name[0],&ptr[0]);
	//printf("%s? Ah! %s!\n",*&name[0],*&ptr[0]);
	//printf("%s? Ah! %s!\n",name[0],ptr[0]);
	for(n=0;n<10;n++)
	{
		printf("name[%d] = %s,ptr[%d] = %s\n",n,name+n,n,ptr+n);
		printf("name[%d] = %c,ptr[%d] = %c\n",n,&name[0]+n,n,&ptr[0]+n);
		printf("name[%d] = %c,ptr[%d] = %c\n",n,*(&name[0]+n),n,*(&ptr[0]+n));
	}

	return 0;
}
