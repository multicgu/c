#include<stdio.h>
int main(void)
{
	int n,m,i,a;
	scanf("%d%d",&n,&m);
	printf("%d %d\n",n,m);
	int ar[n];
	int save[m][n];
	int size[m];
	for(i=0;i<n;i++)
	{
		scanf("%d",&ar[i]);
		printf("%d ",ar[i]);
	}
	int lo,hi;
	for(i=0;i<m;i++)
	{
		int h=0;
		scanf("%d%d",&lo,&hi);
		printf("%d %d\n",lo,hi);
		for(a=0;a<n;a++)
			if(ar[a]>=lo && ar[a]<=hi)
			{
				save[i][h++]=ar[a];
				printf("%d %d\n",ar[a],save[i][h-1]);
				size[i]=h;
			}
				
	}
	for(i=0;i<m;i++)
	{
		for(a=0;a<size[i];a++)
			printf("%d ",save[i][a]);
		puts("");
	}

	return 0;
}
