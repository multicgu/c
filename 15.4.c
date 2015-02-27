#include<stdio.h>
// bit filed constant
// whehter opaque
#define YES 1
#define NO 0
// border style
#define SOLID 0
#define DOTTED 1
#define DASHED 2
// 3 orgin color
#define BLUE 4
#define GREEN 2
#define RED 1
// mix color
#define BLACK 0
#define YELLOW (RED|GREEN)
#define MAGENTA (BLUE|RED)
#define CYAN (BLUE|GREEN)
#define WHITE (RED|GREEN|BLUE)
// bit operation
#define OPAQUE 0x1
#define FILL_BLUE 0X8
#define FILL_GREEN 0x4
#define FILL_RED 0X2
#define BORDER 0X100
#define BORDER_BLUE 0X800
#define BORDER_GREEN 0X400
#define BORDER_RED 0X200
#define B_SOLID 0
#define B_DOTTED 0X1000
#define B_DASHED 0X2000
#define STYLE_MASK 0X3000
#define FILL_MASK 0XE
#define BORDER_MASK 0XE00
const char * color[8]={"black","red","green","yellow","blue","magenta","cyan","write"};
struct box_props {
	unsigned int opaque	:1;
	unsigned int fill_color:3;
	unsigned int :4;
	unsigned int show_border:1;
	unsigned int border_color:3;
	unsigned int border_style:2;
	unsigned int :2;
};
union views {
	struct box_props st_view;
	unsigned int ui_view;
};
void itobs(unsigned int p);
void show_settings(const struct box_props * box);
void show_settings1(unsigned int view);
int main(void)
{
	int bin[16];
	union views box={{YES,YELLOW,YES,GREEN,DASHED}};
	printf("Original box settings:\n");
	show_settings(&box.st_view);
	printf("Original unsigned view setting.\n");
	show_settings1(box.ui_view);
	itobs(box.ui_view);

	box.ui_view &= ~FILL_MASK;
	box.ui_view |= (FILL_BLUE | FILL_GREEN);
	box.ui_view ^= OPAQUE;
	box.ui_view &= ~STYLE_MASK;
	box.ui_view |= B_DOTTED;
	printf("\nModified box settings:\n");
	show_settings(&box.st_view);
	printf("\nBox settings using unsigned int view:\n");
	show_settings1(box.ui_view);
	itobs(box.ui_view);
	return 0;
}
void show_settings(const struct box_props * box)
{
	printf("Box is %s.\n",box->opaque==YES?"opaque":"transparent");
	printf("The fill color is %s.\n",color[box->fill_color]);
	printf("%s border.\n",box->show_border==YES?"shown":"no shown");
	printf("The border color is %s.\n",color[box->border_color]);
	printf("The border style issss ");
	switch(box->border_style)
	{
		case SOLID:printf("solid.\n");break;
		case DOTTED:printf("dotted.\n");break;
		case DASHED:printf("dashed.\n");break;
	}
	putchar('\n');
}
void show_settings1(unsigned int view)
{
	int n;
	printf("Box is %s.\n",(view&OPAQUE)==1?"opaque":"transparent");
	printf("The fill color is %s.\n",color[(view>>1)&7]);
	printf("%s border.\n",((view>>8)&1)==1?"Shown":"No shown");
	printf("Border style is .");
	switch(view&STYLE_MASK)
	{
		case SOLID:printf("solid.\n");break;
		case DOTTED:printf("dotted.\n");break;
		case DASHED:printf("doshed.\n");break;
	}
	printf("The border color is %s.\n",color[(view>>9)&7]);
}
void itobs(unsigned int p)
{
	printf("%d\n",p);
	int n=0;
	for(n=0;n<16;p>>=1,n++)
	{
		printf("%d",1&p);
		if((n+1)%4==0)
			putchar(' ');
	}
	putchar('\n');
}
