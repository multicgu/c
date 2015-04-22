//Reversing Linked List
#include<stdio.h>
typedef struct node{
	int value;
	int next; //next index;
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

/*
 *
 * Given a constant K and a singly linked list L, you are supposed to reverse the links of every K elements on L. For example, given L being 1→2→3→4→5→6, if K = 3, then you must output 3→2→1→6→5→4; if K = 4, you must output 4→3→2→1→5→6.
 *
 * Input Specification:
 *
 * Each input file contains one test case. For each case, the first line contains the address of the first node, a positive N (<= 105) which is the total number of nodes, and a positive K (<=N) which is the length of the sublist to be reversed. The address of a node is a 5-digit nonnegative integer, and NULL is represented by -1.
 *
 * Then N lines follow, each describes a node in the format:
 *
 * Address Data Next
 *
 * where Address is the position of the node, Data is an integer, and Next is the position of the next node.
 *
 * Output Specification:
 *
 * For each case, output the resulting ordered linked list. Each node occupies a line, and is printed in the same format as in the input.
 * Sample Input:
 *
 * 00100 6 4
 * 00000 4 99999
 * 00100 1 12309
 * 68237 6 -1
 * 33218 3 00000
 * 99999 5 68237
 * 12309 2 33218
 *
 * Sample Output:
 *
 * 00000 4 33218
 * 33218 3 12309
 * 12309 2 00100
 * 00100 1 99999
 * 99999 5 68237
 * 68237 6 -1
 *
 */
