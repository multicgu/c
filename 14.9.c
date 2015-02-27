//names2.c
#include<stdio.h>
#include<string.h>
struct namect {
	char fname[20];
	char lname[20];
	int letters;
};
struct namect getinfo(void);
struct namect makeinfo(struct namect);
void showinfo(struct namect);
int main(void)
{
	struct namect persion;
	persion=getinfo();
	persion=makeinfo(persion);
	showinfo(persion);
	return 0;
}
struct namect getinfo(void)
{
	struct namect temp;
	printf("Please enter you first name.\n");
	gets(temp.fname);
	printf("Please enter you last name.\n");
	gets(temp.lname);
	return temp;
}
struct namect makeinfo(struct namect info)
{
	info.letters=strlen(info.fname)+strlen(info.lname);
	return info;
}
void showinfo(struct namect info)
{
	printf("you name is %s %s and have %d letters.\n",info.fname,info.lname,info.letters);
}
