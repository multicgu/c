#include<stdio.h>
#define OFF 0
#define ON 1
#define LEFT 1
#define RIGHT 2
#define CENTER 0
struct typeface {
	unsigned int fontid:8;
	unsigned int fontsize:7;
	unsigned int :1;
	unsigned int bold:1;
	unsigned int italic:1;
	unsigned int underline:1;
	unsigned int alignment:2;
	unsigned int :3;
};
struct typeface font={0,0,OFF,OFF,OFF,CENTER};
void manual(void);
void chfont(struct typeface * font);
void chsize(struct typeface * font);
void chalignment(struct typeface * font);
void chbold(struct typeface * font);
void chitalic(struct typeface * font);
void chunderline(struct typeface * font);
int main(void)
{
	char choise;
	//struct typeface font={0,0,OFF,OFF,OFF,CENTER};
	manual();
	while((choise=getchar())!='q')
	{
		switch(choise)
		{
			case 'f':chfont(&font);break;
			case 's':chsize(&font);break;
			case 'a':chalignment(&font);break;
			case 'b':chbold(&font);break;
			case 'i':chitalic(&font);break;
			case 'u':chunderline(&font);break;
		}
		while(getchar()!='\n');
		manual();
	}
	return 0;
}
void manual(void)
{
	printf("ID SIZE ALIGNMENT B I U\n");
	printf("%d %d ",font.fontid,font.fontsize);
	switch(font.alignment)
	{
		case 1:printf("%s ","left");break;
		case 2:printf("%s ","right");break;
		case 0:printf("%s ","center");break;
	}
	if(font.bold==0) printf("off ");
	else printf("on ");
	if(font.italic==0) printf("off ");
	else printf("on ");
	if(font.underline==0) printf("off ");
	else printf("on ");
	printf("\nf)change font s)change size a)change alignment b)toggle bold i)toggle italic u)toggle underline q)quit\n");
}
void chfont(struct typeface * font)
{
	int a;
	printf("Enter font ID(0-255): ");
	while(scanf("%d",&a)!=1 || a>255)
		fprintf(stderr,"Please enter a integer number within 255\n");
	font->fontid=a;
}
void chsize(struct typeface * font)
{
	int a;
	printf("Enter font size(0-127): ");
	while(scanf("%d",&a)!=1 || a>127)
		fprintf(stderr,"Please enter a integer number within 127.\n");
	font->fontsize=a;
}
void chalignment(struct typeface * font)
{
	char a;
	while(getchar()!='\n');
	printf("Select alignment:\n");
	printf("l)left c)center r)right\n");
	a=getchar();
	switch(a)
	{
		case 'l':font->alignment=1;break;
		case 'r':font->alignment=2;break;
		case 'c':font->alignment=0;break;
	}
}
void chbold(struct typeface * font)
{
	font->bold ^= 1;
}
void chitalic(struct typeface * font)
{
	font->italic ^=1;
}
void chunderline(struct typeface * font)
{
	font->underline ^=1;
}
