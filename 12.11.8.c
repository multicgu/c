//pe12-8.c
#include<stdio.h>
#include<stdlib.h>
int * make_array(int elem,int val);
void show_array(const int ar[],int n);
int main(void)
{
	int * pa;
	int size;
	int value;
	printf("Enter the number of elements: ");
	scanf("%d",&size);
	while(size>0)
	{
		printf("Enter the initialization value: ");
		scanf("%d",&value);
		printf("size=%d,value=%d\n",size,value);
		pa = make_array(size,value);
		if(pa)
		{
			show_array(pa,size);
				free(pa);
		}
		printf("Enter the number of elements(<1 to quit): ");
		scanf("%d",&size);
	}
	printf("Done.\n");
	return 0;
}
int * make_array(int elem,int val)
{
	//printf("In makearray,val=%d\n",val);
	int * pti = (int *) malloc(elem * sizeof(int));
	int n;
	for(n=0;n<elem;n++)
		pti[n] = val;
	return pti;
}
void show_array(const int ar[],int n)
{
	int i;
	for(i=0;i<n;i++)
	{
		printf("%3d",ar[i]);
		if(i%8==7)
			putchar('\n');
	}
	if(i%9!=8)
		putchar('\n');
}
