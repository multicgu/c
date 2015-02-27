#include<stdio.h>
typedef struct node{
	int value;
	int next;
}Node;
int main(void)
{
	Node link[100000];

	long index,total,value,next,rev,firstadd;
	long new,old,temp,head;
	long n,i,a;
	scanf("%ld%ld%ld",&firstadd,&total,&rev);
	//first node address,link length,reversing number;
	for(i=0;i<total;i++)
	{
		scanf("%ld%ld%ld",&index,&value,&next);
		link[index].value=value;
		link[index].next=next;
	}
	head=firstadd;
	for(i=1;i<=total;i++)
	{
		if(link[head].next==-1)
			break;
		head=link[head].next;
	}
	head=firstadd;
	if(rev==0)
		rev=1;
	total=i;
	n=total/rev;  //the loop number
	long firstnode[n],lastnode[n];
	
	for(a=0;a<n;a++)
	{
		new=head;
		old=link[new].next;
		for(i=1;i<rev;i++)
		{
			temp=link[old].next;
			link[old].next=new;
			new=old;
			old=temp;
		}
		link[head].next=old;
		firstnode[a]=new;
		lastnode[a]=head;
		head=old;
	}
	
	for(a=0;a<n-1;a++)
		link[lastnode[a]].next=firstnode[a+1];
	
	head=firstnode[0];

	//puts("");
	for(i=0;i<total-1;i++)
	{
		printf("%05ld %ld %05d\n",head,link[head].value,link[head].next);
		head=link[head].next;
	}
	printf("%05ld %ld %2d\n",head,link[head].value,link[head].next);
	
	return 0;
}

