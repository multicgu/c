#include<stdio.h>
#define TITLEMAX 41
#define AUTHMAX 31
struct book {
	char title[TITLEMAX];
	char author[AUTHMAX];
	float value;
};
int main(void)
{
	struct book library;
	printf("Enter the book name.\n"); 
	gets(library.title);
	printf("Enter the author name.\n");
	gets(library.author);
	printf("Enter the value of the book.\n");
	scanf("%f",&library.value);
	printf("book %s by %s value is %f.\n",library.title,library.author,library.value);
	return 0; 
}
