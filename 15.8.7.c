#include<stdio.h>
#define IDMASK 255
#define SIZEMASK 32512
#define ALMASK 98304
//#define BLODMASK
//#define ITAMASK
//#define UNDMASK
void menu(const unsigned long * typeface);
void chfont(unsigned long * typeface);
void chsize(unsigned long * typeface);
void chali(unsigned long * typeface);
void chbold(unsigned long * typeface);
void chitalic(unsigned long * typeface);
void chunderline(unsigned long * typeface);
int main(void)
{
	char choice;
	unsigned long typeface=0;
	menu(&typeface);
	while(scanf("%c",&choice)==1 && choice!='q')
	{
		switch(choice)
		{
			case 'f':chfont(&typeface);break;
			case 's':chsize(&typeface);break;
			case 'a':chali(&typeface);break;
			case 'b':chbold(&typeface);break;
			case 'i':chitalic(&typeface);break;
			case 'u':chunderline(&typeface);break;
		}
		menu(&typeface);
	}
	return 0;
}
void menu(const unsigned long * typeface)
{
	printf("ID SIZE ALIGNMENT B I U\n");
	printf("%d %d ",(*typeface&IDMASK),((*typeface&SIZEMASK)>>8));
	//switch((typeface&ALMASK)<<15)
	switch(((*typeface&ALMASK)>>15))
	{
		case 0:printf("%s ","center ");break;
		case 1:printf("%s ","left ");break;
		case 2:printf("%s ","right ");break;
	}
	if((((*typeface)>>17)&1)==0) printf("off ");
	else printf("on ");
	if((((*typeface)>>18)&1)==0) printf("off ");
	else printf("on ");
	if((((*typeface)>>19)&1)==0) printf("off ");
	else printf("on ");
	printf("\nf)change font s)change size a)changealignment \n");
	printf("b)toggle bold i)toggle italic u)toggle underline\nq)quit\n");
}
void chfont(unsigned long * typeface)
{
	int id;
	*typeface &= (~IDMASK);
	printf("Enter the ID(0-255): ");
	while(scanf("%d",&id)!=1||id>255)
		fprintf(stderr,"ID enter not right.\n");
	*typeface |= id;
}
void chsize(unsigned long * typeface)
{
	int size;
	*typeface &= (~SIZEMASK);
	printf("Enter the size(0-127): ");
	while(scanf("%d",&size)!=1 || size>127)
		fprintf(stderr,"Size enter not right.\n");
	*typeface |= (size<<8);
}
void chali(unsigned long * typeface)
{
	char ali;
	while(getchar()!='\n');
	printf("Select alignment:\n");
	printf("l)left c)center r)right\n");
	while(scanf("%c",&ali)!=1)
		fprintf(stderr,"choice right answer.\n");
	(*typeface) &= (~ALMASK);
	printf("%d\n",(*typeface)>>15);
	switch(ali)
	{
		case 'l':(*typeface) |= (1<<15);break;
		case 'r':(*typeface) |= (1<<16);break;
		case 'c':(*typeface) |= (0<<16);break;
	}
}
void chbold(unsigned long * typeface)
{
	*typeface ^= (1<<17);
}
void chitalic(unsigned long * typeface)
{
	*typeface ^= (1<<18);
}
void chunderline(unsigned long * typeface)
{
	*typeface ^= (1<<19);
}
