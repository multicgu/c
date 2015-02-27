#include<stdio.h>
#include<stdbool.h>
#include<stdlib.h>
#include<string.h>
typedef struct node{
	char item[20];
	int num;
	struct node * left;
	struct node * right;
}Node;
typedef struct tree{
	Node * root;
	int n;
}tree;
tree * createtree(void)
{
	tree * pt;
	pt=(tree *) malloc(sizeof(tree));
	pt->root=NULL;
	pt->n=0;
	return pt;
}

void listword(Node * root)
{
	if(root->left!=NULL)
		listword(root->left);
	printf("item is %s,and have %d times.\n",root->item,root->num);
	if(root->right!=NULL)
		listword(root->right);
}

typedef struct sw{
	int b;
	Node * root;	
}sw;
sw * searchword(Node * root,char * word)
{
	if(strcmp(root->item,word)>0)
	{
		if(root->left!=NULL)
			searchword(root->left,word);
		else
		{
			sw * s=(sw*)malloc(sizeof(sw));
		//	printf("Note: can not found the %s.(in left)\n",word);
			s->b=0;
			s->root=root;
			return s;
		}
	}
	else if(strcmp(root->item,word)<0)
	{
		if(root->right!=NULL)
			searchword(root->right,word);
		else
		{
			sw * s=(sw*)malloc(sizeof(sw));
		//	printf("Note: can not found the %s.(in right)\n",word);
			s->b=1;
			s->root=root;
			return s;
		}
	}
	else if(strcmp(root->item,word)==0)
	{
		sw * s=(sw*)malloc(sizeof(sw));
		s->b=2;
		s->root=root;
		return s;
	}
}

void addnode(tree * pt,char * word)
{
	if(pt->root==NULL)
	{
		pt->root=(Node *)malloc(sizeof(Node*));
		strcpy(pt->root->item,word);
		pt->root->left=pt->root->right=NULL;
		pt->root->num=1;
		pt->n=1;
		return ;
	}
	sw * s=searchword(pt->root,word);
	if(s->b==0 || s->b==1)
	{
		Node * temp=(Node *) malloc(sizeof(Node));
		strcpy(temp->item,word);
		temp->num=1;
		temp->left=temp->right=NULL;
		if(s->b==0)
			s->root->left=temp;
		if(s->b==1)
			s->root->right=temp;
	}
	else if(s->b==2)
		s->root->num++;
}
