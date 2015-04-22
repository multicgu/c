//List Components
#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#define MAX 20
typedef struct queue{
	int max;
	int head; //when delete node,head add
	int tail; //when add node,tail add
	int item[MAX];
} Queue;
Queue * createqueue(int max);
bool emptyq(Queue * q);
void enqueue(Queue * q,int n);
int delqueue(Queue * q);
void dfs(int v,int (*grap)[v],int r,bool *visited);
void bfs(int v,int (*grap)[v],int r,bool * visited);
void ListComponents(int v,int (*grap)[v],bool *visited);
int main(void)
{
	int v, e,i=0;
	int vt1, vt2, n,big,small;
	scanf("%d%d",&v,&e);
	int grap[v][v];
	for(i=0;i<v;i++) //intitation grap
		for(n=0;n<v;n++)
			grap[i][n]=0;

	for(i=0;i<e;i++)
	{
		scanf("%d%d",&vt1,&vt2);
		grap[vt1][vt2]=grap[vt2][vt1]=1;
	}
	int h=0;
	/*for(i=0;i<v;i++)
		for(n=0;n<v;n++)
		{
			printf("grap[%d][%d]=%d\n",i,n,grap[i][n]);
			if(grap[i][n]==1)h++;
		}
	printf("h=%d\n",h);*/
	bool visited[v];
	//int unvisited[v];
	//dfs
	ListComponents(v,grap,visited);

	return 0;
}
void initialvisited(bool *visited,int v)
{
	int i;
	for(i=0;i<v;i++)
		visited[i]=false;
}
void ListComponents(int v,int (*grap)[v],bool *visited)
{
	int i,n;
	/*for(i=0;i<v;i++)
	{
		visited[i]=false;
		//unvisited[i]=0;
	}*/
	initialvisited(visited,v);

	for(i=0;i<v;i++)
		if(visited[i]!=true)
		{
			printf("{ %d ",i);
			dfs(v,grap,i,visited);
			printf("}\n");
		}
	initialvisited(visited,v);
	for(i=0;i<v;i++)
	{
		if(visited[i]!=true)
		{
			printf("{ ",i);
			bfs(v,grap,i,visited);
			printf("}\n",i);
	   	}
	}
}

void dfs(int v,int (*grap)[v],int r,bool *visited)
{
	visited[r]=true;
	int i;
	for(i=0;i<v;i++)
		if(grap[r][i]==1 && visited[i]!=true)
		{
			printf("%d ",i);
			dfs(v,grap,i,visited);
		}
}


void bfs(int v,int (*grap)[v],int r,bool * visited)
{
	int i;
	bool n;
	visited[r]=true;
	Queue * q;
	q=createqueue(v);
	enqueue(q,r);
	while(!emptyq(q))
	{
		r=delqueue(q);
		printf("%d ",r);
		visited[r]=true;
		for(i=0;i<v;i++)
			if(grap[r][i]==1 && visited[i]!=true)
			{
				enqueue(q,i);
				visited[i]=true;
			}
	}
}
Queue * createqueue(int max)
{
	Queue * q;
	q=(Queue *) malloc(sizeof(Queue));
	q->max=max;
	q->head=q->tail=-1;
	return q;
}
bool emptyq(Queue * q)
{
	if(q->tail==q->head)
		return true;
	else
		return false;
}
void enqueue(Queue * q,int n)
{
	int m=q->max;
	if((q->tail+1)%m==q->head)
	{
		fprintf(stderr,"The queue is full.\n");
		return;
	}
	q->tail=(q->tail+1)%m;
	q->item[q->tail]=n;
	//printf("***in enqueue q->item[%d]=%d\n",q->tail,q->item[q->tail]);
}
int delqueue(Queue * q)
{
	int m=q->max;
	if(q->tail==q->head)
	{
		fprintf(stderr,"The queue is empty.\n");
		return;
	}
	q->head=(q->head+1)%m;
	//printf("***delq q->item[%d]=%d\n",q->head,q->item[q->head]);
	return q->item[q->head];
}

/*
 *
 * For a given undirected graph with N vertices and E edges, please list all the connected components by both DFS and BFS. Assume that all the vertices are numbered from 0 to N-1. While searching, assume that we always start from the vertex with the smallest index, and visit its adjacent vertices in ascending order of their indices.
 *
 * Input Specification:
 *
 * Each input file contains one test case. For each case, the first line gives two integers N (0<N<=10) and E, which are the number of vertices and the number of edges, respectively. Then E lines follow, each described an edge by giving the two ends. All the numbers in a line are separated by a space.
 *
 * Output Specification:
 *
 * For each test case, print in each line a connected component in the format "{ v1 v2 ... vk }". First print the result obtained by DFS, then by BFS.
 * Sample Input:
 *
 * 8 6
 * 0 7
 * 0 1
 * 2 0
 * 4 1
 * 2 4
 * 3 5
 *
 * Sample Output:
 *
 * { 0 1 4 2 7 }
 * { 3 5 }
 * { 6 }
 * { 0 1 2 7 4 }
 * { 3 5 }
 * { 6 }
 *
 */
